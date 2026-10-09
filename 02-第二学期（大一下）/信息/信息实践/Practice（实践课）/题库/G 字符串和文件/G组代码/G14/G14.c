#include <stdio.h>
#include <string.h>
int main() {
    char input[10001];
    char name[10001], fam[10001];
    FILE *inFile, *outFile;
	inFile = fopen("input.txt", "r");
    if (fgets(input, 10001, inFile) == NULL) fclose(inFile);
    fclose(inFile);
    if(strlen(input) > 0 && input[strlen(input) - 1] == '\n') input[strlen(input) - 1] = '\0';
    char *blank = strchr(input, ' ');
    if (blank) {
        *blank = '\0';
        strcpy(fam, input);
        strcpy(name, blank + 1);
    }
    blank = strchr(name, ' ');
    if (blank) *blank = '\0';
    outFile = fopen("output.txt", "w");
    fprintf(outFile, "Hello, %s %s!", name, fam);
    fclose(outFile);
    return 0;
}
