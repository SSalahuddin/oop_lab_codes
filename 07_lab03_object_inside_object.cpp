/*
Author: Sumayyea Salahuddin
Date: 19th October, 2022
Topic: Objects within Objects in C++ Object-Oriented Programming (OOP)
*/

#include<iostream>
using namespace std;

//class Date with three data members and nine member functions
class Date{
    private:                                        //access specifier: private
        int hour, min, sec;                         //class data members

    public:                                         //access specifier: public
        Date();                                     //constructor: no-argument
        Date(int h, int m, int s);                  //constructor: three-argument or overloaded

        void setHr(int h);                          //sets hour part of Date
        void setMin(int m);                         //sets min part of Date
        void setSec(int s);                         //sets sec part of Date
        int getHr() const;                          //gets hour part of Date
        int getMin() const;                         //gets min part of Date
        int getSec() const;                         //gets sec part of Date

        void showDate() const;                      //displays class data members to user
};

Date::Date(){ hour = 0; min = 0; sec = 0; }
Date::Date(int h, int m, int s){ 
    if(h>0 && h<13){ 
        hour = h;
    }else{
        cout << "Invalid hour entered! Setting to zero!" << endl;
    } 

    if(m>=0 && m<60){ 
        min = m;
    }else{
        cout << "Invalid minute entered! Setting to zero!" << endl;
    } 

    if(s>=0 && s<60){ 
        sec = s; 
    }else{
        cout << "Invalid minute entered! Setting to zero!" << endl;
    } 
}
void Date::setHr(int h){ 
    if(h>0 && h<13){ 
        hour = h;
    }else{
        cout << "Invalid hour entered!" << endl;
    } 
}
void Date::setMin(int m){ 
    if(m>=0 && m<60){ 
        min = m;
    }else{
        cout << "Invalid minute entered!" << endl;
    } 
}
void Date::setSec(int s){ 
    if(s>=0 && s<60){ 
        sec = s; 
    }else{
        cout << "Invalid minute entered!" << endl;
    } 
}
int Date::getHr() const{ return hour; }
int Date::getMin() const{ return min; }
int Date::getSec() const{ return sec; }
void Date::showDate() const{ cout << hour << ":" << min << ":" << sec << endl; }

//class Patient with two data members and three member functions
class Patient{
    private:                                        //access specifier: private
        static int number;                          //class data members
        string name;
        Date d;

    public:                                         //access specifier: public
        Patient();                                  //constructor: no-argument
        Patient(string n, Date dd);                 //constructor: two-argument or overloaded
        void showPatient() const;                   //displays class data members to user
};

int Patient::number = 0;

Patient::Patient(){ 
    number++;
    name="";
}

Patient::Patient(string n, Date dd){  
    number++;
    name = n;
    d = dd;
    /*d.setHr(dd.getHr());                            
    d.setMin(dd.getMin());
    d.setSec(dd.getSec());*/
}

void Patient::showPatient() const{ 
    cout << "Patient Number: " << number << endl; 
    cout << "Patient Name: " << name << endl;     
    cout << "Patient Visit Date: ";
    d.showDate(); 
}

int main(){   
    Date d1(5, 30, 45);
    Patient p1("Ali Zia", d1);                      //date object d1 is within patient object p1
    p1.showPatient();

    cout << endl;

    Date d2(5, 45, 01);
    Patient p2("Wajid Salam", d2);                    //date object d2 is within patient object p2
    p2.showPatient();

    return 0;
}
