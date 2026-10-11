#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]), fd = open("fibonachi.dat", O_RDWR | O_CREAT | O_TRUNC, 0644);
    size_t size = N * sizeof(uint32_t);
    uint32_t *map = (ftruncate(fd, size), mmap(NULL, size, PROT_WRITE, MAP_SHARED, fd, 0)), a = 0, b = 1, next;
    for (int i = 0; i < N; i++) map[i] = a, next = a + b, a = b, b = next;
    return munmap(map, size), close(fd), 0;
}