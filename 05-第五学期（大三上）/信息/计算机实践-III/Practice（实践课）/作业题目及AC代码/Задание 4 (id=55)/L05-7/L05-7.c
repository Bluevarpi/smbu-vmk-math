#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    const char *in = argv[--argc];
    argv[argc] = NULL;
    if (!fork()) {
        int fd = open(in, O_RDONLY);
        dup2(fd, 0), close(fd), execvp(argv[1], argv + 1), exit(1);
    }
    return wait(NULL), 0;
}