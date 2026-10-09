#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat s;
    int fd = open("array.dat", O_RDONLY);
    fstat(fd, &s);
    int32_t *map = mmap(NULL, s.st_size, PROT_READ, MAP_SHARED, fd, 0);
    for (int i = 1, idx; i < argc; i++) idx = atoi(argv[i]), printf("%d%s", idx >= 0 && idx < s.st_size / 4 ? map[idx] : 0, i < argc - 1 ? " " : "");
    return puts(""), munmap(map, s.st_size), close(fd), 0;
}