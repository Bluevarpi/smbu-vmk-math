#include <stdio.h>
#include <string.h>
int main() {
    char input[10001], output[10001];
    int i, j = 0;
    FILE *inFile, *outFile;
    inFile = fopen("input.txt", "r");
    if (fgets(input, 10001, inFile) == NULL) fclose(inFile);
    fclose(inFile);
    if(strlen(input) > 0 && input[strlen(input) - 1] == '\n') input[strlen(input) - 1] = '\0';
    for (i = 0; i < strlen(input); i++) {
        if (strncmp(input + i, "Cao", strlen("Cao")) == 0) {
            strcpy(output + j, "Ling");
            j += strlen("Ling"), i += strlen("Cao") - 1;
        } else output[j++] = input[i];
    }
    output[j] = '\0';
    outFile = fopen("output.txt", "w");
    fprintf(outFile, "%s", output);
    fclose(outFile);
    return 0;
}
