// yt-codebeauty
#include <iostream>
using std::string;

class Employee{
    public :
    string Name;
    string Company;
    int Age;

    void IntroduceYOurself(){
        std::cout<<"Namme -"<< Name << std::endl;

        std::cout<<"company -"<< Company<< std::endl;

        std::cout<<"age -"<< Age << std::endl;
    }

    // rules for constructor
    // 1->no return type
    // 2->same nme as class
    // 3-> need to b epublic but it is not always true
    // goal of this constructor to create object for this class
    Employee(string name, string company, int age) {
        Name = name; 
        Company = company;
        Age = age;
    }
};

int main(){

    // Employee employee1; //here also a constructor revoked without even defining , it can be shown if comment out next 3 lines.->called default constructor
    // // when a constructor made by us the default constructor stops by default
    // employee1.Name= "ganesh";
    // employee1.Company="yt";
    // employee1.Age=23;

    Employee employee1 = Employee("ganesh"," yt" , 24);
    employee1.IntroduceYOurself();

    Employee employee2 = Employee("abc","y1-2" , 21);
    employee2.IntroduceYOurself();
//  there is a better way to contrucct object , as it will be a problem if we want to create multiple object
}
