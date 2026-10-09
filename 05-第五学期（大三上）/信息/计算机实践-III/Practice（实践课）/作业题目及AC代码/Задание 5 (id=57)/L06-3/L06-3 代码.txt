#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int N, d[2], s[2], n_fd = -1;
	char b = '1';
	pid_t top, my, pp, c;
    if (scanf("%d", &N) != 1 || N <= 0 || pipe(d)) return 0;
    top = getpid();
    if ((c = fork()) < 0) return perror("fork"), 1;
    if (c) {
        close(d[1]);
        while (read(d[0], &b, 1) > 0);
        return close(d[0]), wait(NULL), 0;
    }
    close(d[0]);
    for (int i = 1; i <= N; i++) {
        my = getpid(), pp = getppid();
        printf("%d %d\n", my - pp, my - top); fflush(stdout);
        fprintf(stderr, "PID = %d PPID = %d\n", my, pp); fflush(stderr);
        if (n_fd != -1) write(n_fd, &b, 1), close(n_fd);
        if (i == N) break;
        if (pipe(s) || (c = fork()) < 0) return perror("fork"), 1;
        if (c) {
            close(s[1]), close(d[1]);
            read(s[0], &b, 1);
            exit(0);
        }
        close(s[0]), n_fd = s[1];
    }
    return 0;
}