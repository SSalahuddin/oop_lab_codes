/*
Author: Sumayyea Salahuddin
Date: 19th October, 2022
Topic: Array of objects in C++ Object-Oriented Programming (OOP)
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

const int SIZE = 3;                 //stores the size of an an object array

int main(){
    //Print total number of Objects before creating objects
    cout << "Initial Stage count: " << Complex::getCount() << endl << endl; 
    
    //First Complex class object, calls no-argument constructor automatically to set 0+i0
    Complex C[SIZE];                //array of complex objects
    double r, i;

    for(int num=0; num<SIZE; num++){
        cout << "Enter real and imaginary values: ";
        cin >> r >> i;
        C[num].setRe(r);
        C[num].setIm(i);
    }

    for(int num=0; num<SIZE; num++){
        if(C[num].getIm()>=0)
            { cout << "\nComplex Number, C" << num+1 << ": " << C[num].getRe() << "+i" << C[num].getIm(); }
        else
            { cout << "\nComplex Number, C" << num+1 << ": " << C[num].getRe() << "-i" << -C[num].getIm(); }
    }

    //Print total number of Objects after creating objects
    cout << "\n\nFinal Stage count: " << Complex::getCount() << endl << endl; 

    return 0;
}
