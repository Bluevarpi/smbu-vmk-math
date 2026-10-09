#include <fcntl.h>
#include <unistd.h>

void copy_twice(char *source_file, char *destination_file) {
    int fd_in = open(source_file, O_RDONLY), fd_out;
    char buf[4]; ssize_t n;
    if (fd_in < 0) return;
    if ((fd_out = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0) { close(fd_in); return; }
    while ((n = read(fd_in, buf, 4)) > 0) write(fd_out, buf, n), write(fd_out, buf, n);
    close(fd_in), close(fd_out);
}

int main() {
    return copy_twice("input.dat", "output.dat"), 0;
}