#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char input[10001];
    char *word;
    FILE *inFile, *outFile;
    inFile = fopen("input.txt", "r");
    if (fgets(input, 10001, inFile) == NULL) fclose(inFile);
    fclose(inFile);
    if(strlen(input) > 0 && input[strlen(input) - 1] == '\n') input[strlen(input) - 1] = '\0';
    outFile = fopen("output.txt", "w");
    for (word = strtok(input, " \n"); word != NULL; word = strtok(NULL, " \n")) fprintf(outFile, "%s\n", word);
    fclose(outFile);
    return 0;
}
