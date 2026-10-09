#define _POSIX_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <string.h>

static int fd_pipe[2], max_value;
static pid_t child_pid, father_pid;
static volatile sig_atomic_t got_usr1 = 0;
static sigset_t block_mask, old_mask;

static void usr1_handler(int signo) { (void)signo, got_usr1 = 1; }

static void wait_for_turn(void) {
    got_usr1 = 0;
	while (!got_usr1) sigsuspend(&old_mask);
	got_usr1 = 0;
}

static void run_son(void) {
    int x, token = INT_MIN;
    for (;;) {
        wait_for_turn();
        if (read(fd_pipe[0], &x, sizeof(x)) != sizeof(x) || x == token) break;
        printf("son %d\n", x), fflush(stdout);
        x = (x >= max_value) ? token : x + 1;
        write(fd_pipe[1], &x, sizeof(x)), kill(father_pid, SIGUSR1);
        if (x == token) break;
    }
    close(fd_pipe[0]), close(fd_pipe[1]), _exit(0);
}

static void run_father(void) {
    int x = 0, token = INT_MIN;
    write(fd_pipe[1], &x, sizeof(x)), kill(child_pid, SIGUSR1);
    for (;;) {
        wait_for_turn();
        if (read(fd_pipe[0], &x, sizeof(x)) != sizeof(x) || x == token) break;
        printf("father %d\n", x), fflush(stdout);
        x = (x >= max_value) ? token : x + 1;
        write(fd_pipe[1], &x, sizeof(x)), kill(child_pid, SIGUSR1);
        if (x == token) break;
    }
    close(fd_pipe[0]), close(fd_pipe[1]), waitpid(child_pid, NULL, 0);
}

int main(void) {
    struct sigaction sa;
    if (scanf("%d", &max_value) != 1 || max_value < 0) return 0;
    if (pipe(fd_pipe) < 0) return perror("pipe"), 1;
    memset(&sa, 0, sizeof(sa)), sa.sa_handler = usr1_handler, sigemptyset(&sa.sa_mask);
    if (sigaction(SIGUSR1, &sa, NULL) < 0) return perror("sigaction"), 1;
    sigemptyset(&block_mask), sigaddset(&block_mask, SIGUSR1);
    if (sigprocmask(SIG_BLOCK, &block_mask, &old_mask) < 0) return perror("sigprocmask"), 1;
    father_pid = getpid();
    if ((child_pid = fork()) < 0) return perror("fork"), 1;
    if (child_pid == 0) return father_pid = getppid(), run_son(), 0;
    return run_father(), 0;
}