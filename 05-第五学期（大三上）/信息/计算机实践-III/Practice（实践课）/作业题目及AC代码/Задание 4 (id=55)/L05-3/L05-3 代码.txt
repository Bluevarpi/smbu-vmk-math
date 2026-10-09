#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

long long max_size = -1;
char max_file_name[1024];

void find_max(const char *dir_path) {
    DIR *dir = opendir(dir_path);
    struct dirent *entry;
	struct stat st;
	char path[1024];
    if (!dir) return;
    while ((entry = readdir(dir)))
        if (strcmp(entry->d_name, ".") && strcmp(entry->d_name, "..")) {
            snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);
            if (!lstat(path, &st)) if (S_ISREG(st.st_mode) && st.st_size > max_size) max_size = st.st_size, strcpy(max_file_name, entry->d_name);
            else if (S_ISDIR(st.st_mode)) find_max(path);
        }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    return find_max(argv[1]), printf("%s\n", max_size == -1 ? "EMPTY" : max_file_name), 0;
}