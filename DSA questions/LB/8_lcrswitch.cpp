#include<iostream>
using namespace std;

void normalSwitch() {
    
     int num=2;
    char ch = '1';
    cout<< endl;
    switch(num || ch){
        case 1: cout<< "first" << endl;
                break;
        case 2: cout<< "second" << endl;
                break;  
        case '1': cout<< "character" << endl;
                break;

        default:cout<<"it is default case"<<endl;    
        // default not mandatory
        // in cases it takes only int and char not float and string  
        }
}

void simpleCalculator(){
    cout<<"\n";
    int m , n;
    char ch;
    cout<<"enter value for m : "<< endl;
    cin>> m ;
    cout<<"enter value for n : "<< endl;
    cin>> n ;
    cout<<"enter value for operator : "<< endl;
    cin>> ch ;

    switch(ch){
        case '+': cout<< "result:"<< m+n << endl;
                break;
        case '-': cout<<  "result:"<< m-n << endl;
                break;  
        case '*': cout<< "result:"<< m*n << endl;
                break;
        case '%': cout<< "result:"<< m%n << endl;
                break;
        case '/': cout<< "result:"<< m/n << endl;
                break;

        default:cout<<"it is default case"<<endl;   
    }
}

int main(){
    normalSwitch() ;
    simpleCalculator();

     return 0;
    }
     
        

   
