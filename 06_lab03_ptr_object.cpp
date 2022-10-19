/*
Author: Sumayyea Salahuddin
Date: 19th October, 2022
Topic: Pointer object & its usage in C++ Object-Oriented Programming (OOP)
*/

#include<iostream>
using namespace std;

//class Complex with three data members and nine member functions
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

        ~Complex();                                 //destructor
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
        std::cout << re << "+i" << im << endl;
    }else{
        std::cout << re << "-i" << -im << endl;
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

Complex::~Complex(){
    cout << "Destroyed object" << endl;   
}

int main(){
    //Print total number of Objects before creating objects
    std::cout << "Initial Stage count: " << Complex::getCount() << endl << endl; 
    
    //First Complex class object, calls no-argument constructor automatically to set 0+i0
    Complex *C = new Complex();                //complex object pointer
    double r, i;

    std::cout << "Enter real and imaginary values: ";
    cin >> r >> i;
    C->setRe(r);
    C->setIm(i);

    if(C->getIm()>=0)
        { std::cout << "\nComplex Number, C: " << C->getRe() << "+i" << C->getIm(); }
    else
        { std::cout << "\nComplex Number, C: " << C->getRe() << "-i" << -C->getIm(); }

    //Print total number of Objects after creating objects
    std::cout << "\n\nFinal Stage count: " << Complex::getCount() << endl << endl; 

    delete C;

    return 0;
}
