#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    DIR *d = opendir(argv[1]);
    struct dirent *e;
	struct stat s;
	char p[1024];
    if (!d) return 1;
    while ((e = readdir(d)))
        if (strcmp(e->d_name, ".") && strcmp(e->d_name, "..")) {
            snprintf(p, sizeof(p), "%s/%s", argv[1], e->d_name);
            if (!lstat(p, &s) && S_ISREG(s.st_mode)) printf("%lld %s\n", (long long)s.st_size, e->d_name);
        }
    return closedir(d), 0;
}