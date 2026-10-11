
#include <iostream>
using namespace std;

// Base class
class A {
public:
    void showA() {
        cout << "Class A" << endl;
    }
};

// a. Single Inheritance
class B : public A {
public:
    void showB() {
        cout << "Class B - Single Inheritance" << endl;
    }
};

// b. Multiple Inheritance
class C {
public:
    void showC() {
        cout << "Class C" << endl;
    }
};

class D : public A, public C {
public:
    void showD() {
        cout << "Multiple Inheritance" << endl;
    }
};

// c. Multilevel Inheritance
class E : public B {
public:
    void showE() {
        cout << "Class E - Multilevel Inheritance" << endl;
    }
};

// d. Hierarchical Inheritance
class F : public A {
public:
    void showF() {
        cout << "Class F - Hierarchical Inheritance" << endl;
    }
};

int main() {
    cout << "Single Inheritance:" << endl;
    B obj1;
    obj1.showA();
    obj1.showB();

    cout << "\nMultiple Inheritance:" << endl;
    D obj2;
    obj2.showA();
    obj2.showC();
    obj2.showD();

    cout << "\nMultilevel Inheritance:" << endl;
    E obj3;
    obj3.showA();
    obj3.showB();
    obj3.showE();

    cout << "\nHierarchical Inheritance:" << endl;
    F obj4;
    obj4.showA();
    obj4.showF();

    return 0;
}
