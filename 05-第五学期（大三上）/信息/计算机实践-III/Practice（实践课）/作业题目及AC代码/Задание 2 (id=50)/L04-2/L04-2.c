#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    if (argc != 4) return 1;
    int32_t n = atoi(argv[3]), num;
    FILE *src = fopen(argv[1], "rb"), *dst;
    if (!src) return 1;
    if (!(dst = fopen(argv[2], "wb"))) return fclose(src), 1;
    while (fread(&num, sizeof(num), 1, src) == 1) if (num < n) fwrite(&num, sizeof(num), 1, dst);
    return fclose(src), fclose(dst), 0;
}