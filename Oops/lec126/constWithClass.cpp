#include<iostream>
using namespace std;

class abc{
    int x;
    int *y;

    public:
        abc(){
            x=0;
            y=new int(0);
        }
        int getX()const{
            return x;
        }
        void setX(int _val){
            x= _val;
        }
        int getY() const{
           
            return *y;
        }
        void setY(int _val){
            *y= _val;
        }
        

};

void print(const abc &a){
    // all function should be const
    cout<<a.getX() << " "<<a.getY()<<endl;
}

int main(){

    abc a;
    cout<<a.getX()<<endl;
    cout<<a.getY()<<endl;
}