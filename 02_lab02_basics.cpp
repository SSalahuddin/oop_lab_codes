/*
Author: Sumayyea Salahuddin
Date: 12th October, 2022
Topic: Basics of Object-Oriented Programming in C++
*/

#include<iostream>
using namespace std;

//class Complex with two data members and five member functions
class Complex{
    private:                                        //access specifier: private
        double re, im;                              //class data members
    public:                                         //access specifier: public
        Complex();                                  //constructor: no-argument
        Complex(double r, double i);                //constructor: two-argument or overloaded
        void showComplex();                         //displays class data members to user
        void addComplex(Complex c1, Complex c2);    //takes two Complex objects and sum them
        Complex negComplex();                       //returns negate of Complex number as an object
};

Complex::Complex(){
    re = 0.0; im = 0.0;
}

Complex::Complex(double r, double i){
    re = r; im = i;
}

void Complex::showComplex(){
    if(im>=0){
        cout << re << "+i" << im << endl;
    }else{
        cout << re << "-i" << -im << endl;
    }
}

void Complex::addComplex(Complex c1, Complex c2){
    re = c1.re + c2.re;
    im = c1.im + c2.im;
}

Complex Complex::negComplex(){
    Complex temp;
    temp.re = -re;
    temp.im = -im;
    return temp;
}

int main(){
    //First Complex class object, calls overloaded constructor automatically to set 2+i4
    Complex C1(2,4);
    cout << "Complex Number, C1: ";
    C1.showComplex();

     //Second Complex class object, calls overloaded constructor automatically to set -0.5+i6.75
    Complex C2(-0.5,6.7);
    cout << "Complex Number, C2: ";
    C2.showComplex();

    //Third Complex class object, calling no-argument constructor automatically to set 0+i0
    Complex C;
    C.addComplex(C1,C2);                //adds object C1 & C2 and stores sum in calling object C
    cout << "Complex Number, C = C1 + C2: ";
    C.showComplex();

    //Fourth Complex class object, calling no-argument constructor automatically to set 0+i0
    Complex Result;
    Result = C1.negComplex();           //negates object C1 and stores it in Result object
    cout << "Complex Number, Result: ";
    Result.showComplex();
    cout << endl;

    return 0;
}
