#include <iostream>
using namespace std;

void matrix(){
    int m , n;
    int matrix[100][100];

    cout<<"enter number of rows and columns: ";
    cin>>m>>n;
    cout<<"enter the elements of the matrix: "<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>matrix[i][j];
        }
    }

    cout <<"the matrix is :"<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return ;
}


int main(){
    matrix();
    return 0;
}