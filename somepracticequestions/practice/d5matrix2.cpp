#include <iostream>
using namespace std;

void inputMatrix(int matrix[100][100], int &m, int &n){

    cout<<"Enter number of rows and columns: ";
    cin>>m>>n;

    cout<<"Enter matrix elements:\n";

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
}

void printMatrix(int matrix[100][100], int m, int n){

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void addMatrix(int A[100][100], int B[100][100], int C[100][100], int m, int n){

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void transposematrix(int A[100][100], int m, int n){
    int T[100][100];

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            T[j][i] = A[i][j];
        }
    }

    cout<<"Transpose of the matrix is:\n";
    printMatrix(T,n,m);
}

void multiplyMatrix(int A[100][100], int B[100][100], int C[100][100], int m, int n, int p){

    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++){
          C[i][j]=0;
          for(int k=0; k<n;k++){
            C[i][j] += A[i][k] * B[k][j];
          }
        }
    }
}

int main(){

    int m,n,p;

    int matrix1[100][100];
    int matrix2[100][100];
    int sum[100][100];

    cout<<"Enter first matrix\n";
    inputMatrix(matrix1,m,n);
    cout<<"-> first matrix:\n";
    printMatrix(matrix1,m,n);

    cout<<"Enter second matrix\n";
    // inputMatrix(matrix2,m,n); // for addition and transpose
    inputMatrix(matrix2,n,p); // for multiplication
    cout<<"-> second matrix:\n";
    printMatrix(matrix2,n,p);

    // transposematrix(matrix1,m,n);

    // addMatrix(matrix1,matrix2,sum,m,n);
    // cout<<"Sum matrix:\n";
    // printMatrix(sum,m,n);


    multiplyMatrix(matrix1,matrix2,sum,m,n,p);
    cout<<"multiply matrix:\n";
    printMatrix(sum,m,p);

    return 0;
}