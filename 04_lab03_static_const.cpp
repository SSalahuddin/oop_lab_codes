/*
Author: Sumayyea Salahuddin
Date: 19th October, 2022
Topic: Usage of static and const components in C++ Object-Oriented Programming (OOP)
*/

#include<iostream>
using namespace std;

//class Complex with three data members and eight member functions
class Complex{
    private:                                        //access specifier: private
        double re, im;                              //class data members
        static int countObjects;                    //important: static data member
    
    public:                                         //access specifier: public
        Complex();                                  //constructor: no-argument
        Complex(double r, double i);                //constructor: two-argument or overloaded

        void setRe(double r);                       //sets real part of Complex number
        void setIm(double i);                       //sets imaginary part of Complex number
        double getRe() const;                       //gets real part of Complex number
        double getIm() const;                       //gets imaginary part of Complex number
        static int getCount();                      //gets countObject data member of Complex class

        void showComplex() const;                   //displays class data members to user
};

int Complex::countObjects = 0;                      //initialize static member of class Complex

Complex::Complex(){
    re = 0.0; im = 0.0; countObjects++;
}

Complex::Complex(double r, double i){
    re = r; im = i; countObjects++;
}

void Complex::showComplex() const{
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

double Complex::getRe() const{
    return re;
}

double Complex::getIm() const{
    return im;
}

int Complex::getCount(){
    return countObjects;
}   

int main(){
    //Print total number of Objects before creating objects
    cout << "Initial Stage count: " << Complex::getCount() << endl << endl; 
    
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

    //Print total number of Objects after creating objects
    cout << "Final Stage count: " << Complex::getCount() << endl << endl; 

    return 0;
}
