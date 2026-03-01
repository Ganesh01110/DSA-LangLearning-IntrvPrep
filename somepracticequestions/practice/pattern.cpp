#include <bits/stdc++.h>
using namespace std;

void printsquare(int n){
    cout<<"--------square pattern::-----"<<endl;
    for(int i=1;i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

void printarectangle(int n){
    cout<<"its for rectangle pattern"<<endl;
    for(int i=0; i<=n-1 ; i++){
        for(int j=0 ; j<=(n-1)*2 ; j++){
            cout<<" *" ;
        } 
        cout<<endl;
    }
}

void printAtriangle(int n){
    for( int i=1; i<=n; i++){
        for( int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

}

void inversetriangle(int n){
    cout<<"inverted triangle pattern::"<<endl;
    for (int i=n; i>=1 ; i--){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
// 88888888888888888888

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





// int main() {
//   pyramidwithstar();
//   diagonalstar();
//   pyramidnumber();
//   numbertriangle();
// }

int main(){
    int n;
    cout<<"enter a number::";
    cin>>n;
    printAtriangle(n);
    printsquare(n);
    inversetriangle(n);
    printarectangle(n);
    pyramidwithstar();
    diagonalstar();
    pyramidnumber();
    numbertriangle();
     rightanglestar();
    mirroredrightanglestar();
    return 0;
}
