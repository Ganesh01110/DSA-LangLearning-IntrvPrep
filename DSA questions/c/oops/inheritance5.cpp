//types of inheritance

// 1
// C++ program to demonstrate how to implement the Single
// inheritance
#include <iostream>
using namespace std;

// base class
class Vehicle {
public:
    Vehicle() { cout << "This is a Vehicle\n"; }
};

// sub class derived from a single base classes
class Car : public Vehicle {
public:
    Car() { cout << "This Vehicle is Car\n"; }
};

// main function
int main()
{
    // Creating object of sub class will
    // invoke the constructor of base classes
    Car obj;
    return 0;
}


// 2
// C++ program to illustrate the multiple inheritance
#include <iostream>
using namespace std;

// first base class
class Vehicle {
public:
    Vehicle() { cout << "This is a Vehicle\n"; }
};

// second base class
class FourWheeler {
public:
    FourWheeler() { cout << "This is a 4 Wheeler\n"; }
};

// sub class derived from two base classes
class Car : public Vehicle, public FourWheeler {
  public:
    Car() { cout << "This 4 Wheeler Vehical is a Car\n"; }
};

// main function
int main()
{
    // Creating object of sub class will
    // invoke the constructor of base classes.
    Car obj;
    return 0;
}


// 3
// C++ program to implement Multilevel Inheritance
#include <iostream>
using namespace std;

// base class
class Vehicle {
public:
    Vehicle() { cout << "This is a Vehicle\n"; }
};

// first sub_class derived from class vehicle
class fourWheeler : public Vehicle {
public:
    fourWheeler() { cout << "4 Wheeler Vehicles\n"; }
};

// sub class derived from the derived base class fourWheeler
class Car : public fourWheeler {
public:
    Car() { cout << "This 4 Wheeler Vehical is a Car\n"; }
};

// main function
int main()
{
    // Creating object of sub class will
    // invoke the constructor of base classes.
    Car obj;
    return 0;
}


// 4

// C++ program to implement Hierarchical Inheritance
#include <iostream>
using namespace std;

// base class
class Vehicle {
public:
    Vehicle() { cout << "This is a Vehicle\n"; }
};

// first sub class
class Car : public Vehicle {
public:
    Car() { cout << "This Vehicle is Car\n"; }
};

// second sub class
class Bus : public Vehicle {
public:
    Bus() { cout << "This Vehicle is Bus\n"; }
};

// main function
int main()
{
    // Creating object of sub class will
    // invoke the constructor of base class.
    Car obj1;
    Bus obj2;
    return 0;
}




// 5
// C++ program to illustrate the implementation of Hybrid Inheritance
#include <iostream>
using namespace std;

// base class
class Vehicle {
public:
    Vehicle() { cout << "This is a Vehicle\n"; }
};

// base class
class Fare {
public:
    Fare() { cout << "Fare of Vehicle\n"; }
};

// first sub class
class Car : public Vehicle {
  public:
  Car() { cout << "This Vehical is a Car\n"; }
};

// second sub class
class Bus : public Vehicle, public Fare {
  public:
  Bus() { cout << "This Vehicle is a Bus with Fare\n"; }
};

// main function
int main()
{
    // Creating object of sub class will
    // invoke the constructor of base class.
    Bus obj2;
    return 0;
}




