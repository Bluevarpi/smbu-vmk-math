#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char input[1001], output[1001];
    FILE *inFile, *outFile;
    int i, j = 0;
    inFile = fopen("input.txt", "r");
    while (fscanf(inFile, "%c", &input[j]) != EOF && j < 1000)
        if (isalpha(input[j])) {
            for (i = 0; i < j; i++) if (input[i] == input[j]) break;
            if (i == j) output[j] = input[j], j++;
        }
    output[j] = '\0';
    fclose(inFile);
    outFile = fopen("output.txt", "w");
    fprintf(outFile, "%s", output);
    fclose(outFile);
    return 0;
}
