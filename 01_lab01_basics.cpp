/*
Author: Sumayyea Salahuddin
Date: 5th October, 2022
Topic: Basics of Object-Oriented Programming in C++
*/

#include<iostream>
using namespace std;

//class Complex with two data members and four member functions
class Complex{
    private:                //access specifier: private
        double re, im;      //class data members
    public:                 //access specifier: public
        //constructor: no-argument
        //special class function
        Complex(){
            cout << "\nI'm inside no-argument constructor...\n";
            re = 0.0;
            im = 0.0;
        }
        //constructor: two-argument or overloaded
        //special class function
        Complex(double r, double i){
            cout << "\nI'm inside overloaded constructor...\n";
            re = r;
            im = i;
        }
        //normal C++ function but part of Class
        //gets user data and stores in class data members
        void getComplex(double r, double i){
            re = r;
            im = i;
        }
        //another normal C++ function but part of Class
        //displays class data members to user
        void showComplex(){
            if(im>=0){
                cout << re << "+i" << im << endl;
            }
            else{
                cout << re << "-i" << -im << endl;
            }
        }
};

int main(){
    //First Complex class object, calls no-argument constructor automatically to set 0+i0
    Complex C1;      
    cout << "Complex Number, C1: ";       
    C1.showComplex();
    
    C1.getComplex(2,3);     //updates C1 object and stores 2+i3
    cout << "Updated Complex Number, C1: ";       
    C1.showComplex();       //show the updated complex number

    //Second Complex class object, calls overloaded constructor automatically to set -0.5+i6.75
    Complex C2(-0.5,6.7);   
    cout << "Complex Number, C2: ";       
    C2.showComplex();

    //Third Complex class object, again calling overloaded constructor automatically to set -2.67-i8.6
    Complex C3(-2.67,-8.6);   
    cout << "Complex Number, C3: ";       
    C3.showComplex();
    cout << endl;

    return 0;
}
