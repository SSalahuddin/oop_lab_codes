/*
Author: Sumayyea Salahuddin
Date: 15th October, 2022
Topic: Basics of Object-Oriented Programming in C++
*/

#include<iostream>
using namespace std;

//class Complex with two data members and seven member functions
class Complex{
    private:                                        //access specifier: private
        double re, im;                              //class data members
    public:                                         //access specifier: public
        Complex();                                  //constructor: no-argument
        Complex(double r, double i);                //constructor: two-argument or overloaded

        void setRe(double r);                       //sets real part of Complex number
        void setIm(double i);                       //sets imaginary part of Complex number
        double getRe();                             //gets real part of Complex number
        double getIm();                             //gets imaginary part of Complex number
        
        void showComplex();                         //displays class data members to user
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

void Complex::setRe(double r){
    re = r;
}

void Complex::setIm(double i){
    im = i;
}

double Complex::getRe(){
    return re;
}

double Complex::getIm(){
    return im;
}

int main(){
    //First Complex class object, calls no-argument constructor automatically to set 0+i0
    Complex C1;
    cout << "Complex Number, C1: ";
    C1.showComplex();

    //Calls the getRe() class function to set the real part of a Complex number
    C1.setRe(2);
    cout << "Complex Number, C1 after setting re part: ";
    C1.showComplex();

    //Calls the getIm() class function to set the imaginary part of a Complex number
    C1.setIm(4);
    cout << "Complex Number, C1 after setting im part: ";
    C1.showComplex();
    cout << endl;

     //Second Complex class object, calls overloaded constructor automatically to set -0.5+i6.75
    Complex C2(-0.5,6.7);
    cout << "Complex Number, C2: " << C2.getRe() << "+i" << C2.getIm() << endl;    //calls the get functions
    cout << endl;

    return 0;
}
