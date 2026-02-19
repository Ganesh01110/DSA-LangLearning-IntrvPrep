#include<iostrem>

using namespace std;

int main() {
    int m=12;
    int count=0;

    for(int i=1;i<=m;i++){
        if(m%i == 0) {
            count++;
        }
    }

    if (count == 2) {
        cout<< "itt is a prime number" << endl;
    }
    elseif{
         cout<< "itt is not a prime number" << endl;
    }

}