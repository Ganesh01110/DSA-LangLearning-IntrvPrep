#include <stdio.h>

int pyramidwithstar(){
    int n = 5; // Number of rows
    for (int i = 1; i <= n; i++) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

int diagonalstar() {
    int n = 5; // Number of rows
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}

int pyramidnumber() {
    int n = 5; // Number of rows
    for (int i = 1; i <= n; i++) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int k = 1; k <= (2 * i - 1); k++) {
            printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}

int numbertriangle() {
    int n = 5; // Number of rows
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}



int main() {
  pyramidwithstar();
  diagonalstar();
  pyramidnumber();
  numbertriangle();
}
