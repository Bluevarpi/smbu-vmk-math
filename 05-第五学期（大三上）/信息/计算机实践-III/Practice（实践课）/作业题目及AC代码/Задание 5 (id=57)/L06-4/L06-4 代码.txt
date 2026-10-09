#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    int N;
    if (scanf("%d", &N) != 1 || N <= 0) return 0;
    for (int i = 1; i <= N; i++) {
        pid_t pid = fork();
        if (pid < 0) return perror("fork"), 1;
        if (pid == 0) printf("son %d\n", i), fflush(stdout), fprintf(stderr, "PID = %d PPID = %d\n", (int)getpid(), (int)getppid()), fflush(stderr), _exit(0);
        wait(NULL);
    }
    return 0;
}