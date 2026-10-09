#include <stdio.h>
#include <stdlib.h>
int main() {
    FILE *readFile, *writeFile;
    char *outputString;
    int N;
    readFile = fopen("input.txt", "r");
	fscanf(readFile, "%d", &N);
    fclose(readFile);
    outputString = (char *)malloc((N + 1) * sizeof(char));
    for (int i = 0; i < N; i++) {
        if (i & 1) outputString[i] = '2' + (i - 1) % 8;
        else outputString[i] = 'A' + i / 2;
    }
    outputString[N] = '\0';
    writeFile = fopen("output.txt", "w");
    fprintf(writeFile, "%s\n", outputString);
    fclose(writeFile);
    return 0;
}
