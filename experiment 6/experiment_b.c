#include <stdio.h>

void TOWER(int NUM, const char* A, const char* B, const char* C);

int main() {
    int N;
    printf("Enter the number of disks to be transferred: ");
    scanf("%d", &N);
    if (N < 1) {
        printf("\nIncorrect value\n");
    } else {
        printf("\nThe following moves are required for n = %d\n\n", N);
        TOWER(N, "BEG", "AUX", "END");
    }
    return 0;
}

void TOWER(int NUM, const char* A, const char* B, const char* C) {
    if (NUM == 1) {
        printf("%s -> %s\t", A, C);
        return;
    }
    TOWER(NUM - 1, A, C, B);
    printf("%s -> %s\t", A, C);
    TOWER(NUM - 1, B, A, C);
}