#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    const char *out = argv[--argc];
    argv[argc] = NULL;
    if (!fork()) {
        int fd = open(out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        dup2(fd, 1), close(fd), execvp(argv[1], argv + 1), exit(1);
    }
    return wait(NULL), 0;
}