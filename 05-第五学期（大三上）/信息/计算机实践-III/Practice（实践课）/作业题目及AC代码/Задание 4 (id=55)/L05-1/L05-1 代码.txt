#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int main(int c, char *v[]) {
    DIR *dir = opendir(v[1]); struct dirent *e; struct stat s; char p[1024]; long long t = 0;
    if (!dir) return 1;
    while ((e = readdir(dir)))
        if (strcmp(e->d_name, ".") && strcmp(e->d_name, ".."))
            snprintf(p, sizeof(p), "%s/%s", v[1], e->d_name),
            (!lstat(p, &s) && S_ISREG(s.st_mode) ? t += s.st_size : 0);
    return closedir(dir), printf("%lld\n", t), 0;
}