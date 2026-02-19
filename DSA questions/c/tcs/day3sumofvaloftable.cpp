// given an integer we need to findout the sum of values of that table.
// input:10 op:550

#include <iostream>

int main(){
    int a = 10;
    int sum=0;
    for(int i=0;i<=10;i++){
       
        int multiply=i*a;

        sum += multiply ;
    }

    std::cout << "total output" << sum ;
}