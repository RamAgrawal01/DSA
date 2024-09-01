#include<iostream>
using namespace std;

class Animal{
    //properties
public:
    int age=15;
    string name="ramesh";

    //behaviours
    void eat(){
        cout<<"Eating"<<endl;
    }
    void sleep(){
        cout<<"Sleeping night"<<endl;
    }
};

int main(){
    //object creation

    //static
    // Animal ramesh;
    // cout<<"Age of Ramesh is: "<<ramesh.age<<endl;
    // cout<<"Age of Ramesh is: "<<ramesh.name<<endl;
    // ramesh.eat();
    // return 0;

    //object creatiion using dynamic memory
    Animal* suresh = new Animal;
    (*suresh).age = 16;
    (*suresh).name="billli";

    //aternate - dynammic
    suresh->age = 17;
    suresh->name = "kutta";
    suresh->sleep();
}
