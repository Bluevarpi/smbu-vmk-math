#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int c, char *v[]) {
    int p[2], l = 0, n; pid_t f; char b[4096];
    if (c < 2 || pipe(p) || (f = fork()) < 0) return 1;
    if (!f) return dup2(p[1], 1), close(p[0]), close(p[1]), execvp(v[1], v + 1), 1;
    for (close(p[1]); (n = read(p[0], b, sizeof(b))) > 0; fflush(stdout)) for (int i = 0; i < n; i++) if (l < 5) putchar(b[i]) < 0 ? (close(p[0]), wait(0), exit(1)) : (void)(l += (b[i] == '\n'));
    return close(p[0]), wait(0), 0;
}