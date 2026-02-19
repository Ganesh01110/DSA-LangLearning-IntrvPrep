#include <iostream>

using namespace std;

// * * *
// * * *
// * * * row=col
void rowColPattern(){
    int num = 5;
    int i=0;
    while(i < num){
        int j=0;
        while(j<num){
            cout<< "* ";
            j=j+1;
        }
        cout<< endl;
        i=i+1;
    }
}

// * 
// * * 
// * * * 
void upTrianglePattern(){
     cout<< "____________"<<endl;
    int num =5;
    int i=0;
    while( i<num){
        int j =0;
        while(j<=i){
            cout<< "* ";
            j=j+1;
        }
         cout<< endl;
        i=i+1;
    }
}


// * * *
// * * 
// *  
void downTrianglePattern(){
    cout<< "____________"<<endl;
    int num =5;
    int i = num;
    while( i>0){
        int j = 0;
        while(j<i){
            cout<< "* ";
            j=j+1;
        }
         cout<< endl;
        i=i-1;
    }
}

// 1
// 1 2  
// 1 2 3
void upNumTrianglePattern(){
    cout<< "____________"<<endl;
    int num =5;
    int i = 1;
    while( i<=num){
        int j = 1;
        while(j<=i){
            cout<< j << " " ;
            j=j+1;
        }
         cout<< endl;
        i=i+1;
    }
}
 
// 1 2 3
// 1 2  
// 1 
void downNumTrianglePattern(){
    cout<< "____________"<<endl;
    int num =5;
    int i = num;
    while( i>0){
        int j = 1;
        while(j<=i){
            cout<< j << " " ;
            j=j+1;
        }
         cout<< endl;
        i=i-1;
    }
}

// 1
// 2 3  
// 4 5 6
void upcountTrianglePattern(){
    cout<< "____________"<<endl;
    int num =5;
    int i = 1;
    int count =1;
    while( i<=num){
        int j = 1;
        while(j<=i){
            cout<< count << " " ;
            count++;
            j=j+1;
        }
         cout<< endl;
        i=i+1;
    }
}

// 6
// 5 4  
// 3 2 1
void downcountTrianglePattern(){
    cout<< "____________"<<endl;
    int num =5;
    int i = num;
    int count =(num*(num+1))/2;
    while( i>=0){
        int j = 1;
        while(j<=i){
            cout<< count << " " ;
            count--;
            j=j+1;
        }
         cout<< endl;
        i=i-1;
    }
}

// 1
// 22
// 333
void upnextNumTrianglePattern(){
    cout<< "____________"<<endl;
    int num =5;
   for(int i=1 ; i<=num ; i++) {
    for (int j=1 ; j<=i ; j++ ){
        cout<< i ;
    }
    cout<< endl ;
   }
   
}

// *
//  *
//   *
  
void slantedStarPattern(){
    cout<< "____________"<<endl;
    int num =5;
   for(int i=1 ; i<=num ; i++) {
    for (int j=1 ; j<=i ; j++ ){
        cout<< " ";
    }
    cout<< "*"<<endl ;
   }
   
}

//    *
//   **
//  ***
// ****
void rightAlignedTrianglePattern() {
    cout<< "____________"<<endl;
    int num=5;
    for (int i = 1; i <= num; i++) {
        // Print leading spaces
        for (int j = 1; j <= num - i; j++) {
            cout << " ";
        }
        // Print stars
        for (int k = 1; k <= i; k++) {
            cout << "*";
        }
        // Move to the next line
        cout << endl;
    }
}

// *****
// *   *
// *   *
// *   *
// *****
void hollowSquarePattern() {
     cout<< "____________"<<endl;
    int size=5;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            // Print stars on the border of the square
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

//    *
//   ***
//  *****
// *******
void midAlignedTrianglePattern() {
    cout<< "____________"<<endl;
    int num=5;
    for (int i = 1; i <= num; i++) {
        // Print leading spaces
        for (int j = 1; j <= num - i; j++) {
            cout << " ";
        }
        // Print stars
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << "*";
        }
        // Move to the next line
        cout << endl;
    }
}

// *******
//  *****
//   ***
//    *
//   ***
//  *****
// *******

void hourglassPattern() {
    cout<< "____________"<<endl;

    int num=5;
    // Print the top half of the hourglass
    for (int i = num; i >= 1; i--) {
        // Print leading spaces
        for (int j = 0; j < num - i; j++) {
            cout << " ";
        }
        // Print stars
        for (int k = 0; k < 2 * i - 1; k++) {
            cout << "*";
        }
        cout << endl;
    }

    // Print the bottom half of the hourglass
    for (int i = 2; i <= num; i++) {
        // Print leading spaces
        for (int j = 0; j < num - i; j++) {
            cout << " ";
        }
        // Print stars
        for (int k = 0; k < 2 * i - 1; k++) {
            cout << "*";
        }
        cout << endl;
    }
}

void diamondPattern() {
    cout<< "____________"<<endl;

    int num=5;
    // top of diamond
      for (int i = 0; i <= num; i++) {
        // Print leading spaces
        for (int j = 0; j < num - i; j++) {
            cout << " ";
        }
        // Print stars
        for (int k = 0; k < 2 * i - 1; k++) {
            cout << "*";
        }
        cout << endl;
    }

    // another half
      for (int i = num; i >= 1; i--) {
        // Print leading spaces
        for (int j = 0; j < num - i; j++) {
            cout << " ";
        }
        // Print stars
        for (int k = 0; k < 2 * i - 1; k++) {
            cout << "*";
        }
        cout << endl;
    }
    }


int main() {
   rowColPattern();
   upTrianglePattern();
   downTrianglePattern();
   upNumTrianglePattern();
   downNumTrianglePattern();
   upcountTrianglePattern();
   downcountTrianglePattern();
   upnextNumTrianglePattern();
   slantedStarPattern();
   rightAlignedTrianglePattern();
   hollowSquarePattern();
   midAlignedTrianglePattern();
   hourglassPattern();
   diamondPattern();

  return 0;
}