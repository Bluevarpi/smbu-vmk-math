#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    int p1[2], p2[2], x, min = 0, max = 0, first = 1;
    if (pipe(p1) < 0 || pipe(p2) < 0) return perror("pipe"), 1;
    pid_t pid = fork();
    if (pid < 0) return perror("fork"), 1;
    if (pid == 0) {
        pid_t gp = fork();
        if (gp < 0) perror("fork"), _exit(1);
        if (gp == 0) {
            close(p1[0]), close(p2[0]), close(p2[1]);
            while (scanf("%d", &x) == 1) if (write(p1[1], &x, sizeof(x)) != sizeof(x)) perror("write"), close(p1[1]), _exit(1);
            close(p1[1]), _exit(0);
        }
        close(p1[1]), close(p2[0]);
        while (read(p1[0], &x, sizeof(x)) == sizeof(x)) if (write(p2[1], &x, sizeof(x)) != sizeof(x)) perror("write"), close(p1[0]), close(p2[1]), wait(NULL), _exit(1);
        close(p1[0]), close(p2[1]), wait(NULL), _exit(0);
    }
    close(p1[0]), close(p1[1]), close(p2[1]);
    while (read(p2[0], &x, sizeof(x)) == sizeof(x)) first ? (min = max = x, first = 0) : ((x < min ? min = x : 0), (x > max ? max = x : 0));
    close(p2[0]);
    if (!first) printf("%d %d\n", min, max);
    return wait(NULL), 0;
}