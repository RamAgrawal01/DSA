#include<iostream>
using namespace std;

class Animal{
    public:
    void speak(){
        cout<<"Speaking: "<<endl;
    }
};
class Dog:public Animal{
    public:
    void speak(){
        cout<<"barking: "<<endl;
    }
};

int main(){
    // Dog a;
    // a.speak();

    //upcasting
    // Animal* a = new Dog();
    // a->speak(); 

    //downcasting
    Dog* a =(Dog*) new Animal();
    a->speak();
}