// yt-codebeauty
#include <iostream>
using std::string;

class Employee{
private:
    string Name;
    string Company;
    int Age;

    // private is the default, if nothing defined
    // need to define setter and getter method for this
 public :
    void setName(string name) {
        Name = name;
    }
    string getName(){
        return Name;
    }

    void setCompany(string company) {
        Company = company;
    }
    string getCompany(){
        return Company;
    }

    void setAge(int age ) {
        // wecan add validator/password with condition which we received from args
        if(age >=18 )
        Age = age;
    }
    int getAge(){
        return Age;
    }
    
    void IntroduceYOurself(){
        std::cout<<"Namme -"<< Name << std::endl;

        std::cout<<"company -"<< Company<< std::endl;

        std::cout<<"age -"<< Age << std::endl;
    }

    Employee(string name, string company, int age) {
        Name = name; 
        Company = company;
        Age = age;

    }
};

int main(){


    Employee employee1 = Employee("ganesh"," yt" , 24);
    employee1.IntroduceYOurself();

    Employee employee2 = Employee("abc","y1-2" , 21);
    employee2.IntroduceYOurself();

    employee1.setAge(39);
    std::cout<<employee1.getName()<<" is "<<employee1.getAge()<<" at "<<employee1.getCompany()<<std::endl;

}
