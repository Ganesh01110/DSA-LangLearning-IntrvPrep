#include <iostream>
#include <string>
using namespace std;

// Encapsulation: Data members are private, and they are accessed through public methods
class Person {
private:
    string name;  // Private data member (encapsulation)
    int age;

public:
    // Constructor: Initializes the object with given values
    Person(string n, int a) : name(n), age(a) {}

    // Getter methods to access private data members
    string getName() const { return name; }
    int getAge() const { return age; }

    // Setter methods to modify private data members
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }

    // Virtual function for demonstrating polymorphism
    virtual void displayInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Inheritance: Student inherits from Person class
class Student : public Person {
private:
    string studentID;

public:
    // Constructor: Calls the base class constructor to initialize name and age
    Student(string n, int a, string id) : Person(n, a), studentID(id) {}

    // Function overriding (Polymorphism): displayInfo function is overridden
    void displayInfo() const override {
        cout << "Student Name: " << getName() << ", Age: " << getAge() << ", Student ID: " << studentID << endl;
    }
};

// Abstraction: Class that provides abstract behavior
class Course {
public:
    // Pure virtual function making this class abstract
    virtual void courseDetails() const = 0;  // Abstraction
};

// Derived class that implements the pure virtual function of Course
class MathCourse : public Course {
public:
    void courseDetails() const override {
        cout << "Math course involves Algebra, Calculus, and Geometry." << endl;
    }
};

// Polymorphism: Function overloading example
class Calculator {
public:
    // Function overloading with different signatures
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
};

// Operator Overloading: Example for overloading "+" operator
class Complex {
private:
    int real, imag;

public:
    // Constructor
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Overloading "+" operator
    Complex operator + (const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }

    // Function to display complex number
    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    // Demonstrating encapsulation and inheritance
    Person person("Alice", 30);
    person.displayInfo();

    Student student("Bob", 20, "S1234");
    student.displayInfo();

    // Demonstrating abstraction
    MathCourse math;
    math.courseDetails();

    // Demonstrating polymorphism: Function Overloading
    Calculator calc;
    cout << "Sum of integers: " << calc.add(10, 20) << endl;
    cout << "Sum of doubles: " << calc.add(5.5, 3.2) << endl;

    // Demonstrating operator overloading
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 + c2;  // Using overloaded "+" operator
    cout << "Sum of complex numbers: ";
    c3.display();

    return 0;
}


/*
Encapsulation:

The data members name and age in the Person class are private. They are accessed and modified using public getter and setter methods, which ensures that the internal details are hidden from outside.
Inheritance:

The Student class inherits from the Person class. It reuses the Person attributes and adds its own (studentID). The displayInfo function is overridden to provide specific behavior.
Polymorphism:

Function Overloading: The Calculator class demonstrates overloading of the add function, which accepts different types of parameters (int, double).
Function Overriding: The Student class overrides the displayInfo function of the Person class to display additional information.
Virtual Function: The base class Person has a virtual function displayInfo to support dynamic polymorphism.
Abstraction:

The Course class is an abstract class (it contains a pure virtual function courseDetails). This ensures that any class inheriting from Course must implement this function.
Operator Overloading:

The Complex class demonstrates overloading the + operator to add two complex numbers.
*/
