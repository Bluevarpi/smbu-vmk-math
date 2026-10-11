#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int p[2], x, sum = 0;
    pid_t pid;
    if (pipe(p) || (pid = fork()) < 0) return perror(pid < 0 ? "fork" : "pipe"), 1;
    if (!pid) {
        close(p[1]);
        while (read(p[0], &x, sizeof(x)) == sizeof(x)) sum += x;
        return close(p[0]), printf("%lld\n", sum), 0;
    }
    close(p[0]);
    while (scanf("%d", &x) == 1) if (write(p[1], &x, sizeof(x)) != sizeof(x)) return perror("write"), close(p[1]), wait(NULL), 1;
    return close(p[1]), wait(NULL), 0;
}