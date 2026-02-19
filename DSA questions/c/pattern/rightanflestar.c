#include <stdio.h>

int rightanglestar() {
    int n = 5; // Number of rows
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}


int mirroredrightanglestar() {
    int n = 5; // Number of rows
    for (int i = 1; i <= n; i++) {
        for (int j = n; j > i; j--) {
            printf("  ");
        }
        for (int k = 1; k <= i; k++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}

int main(){
    rightanglestar();
    mirroredrightanglestar();
}
