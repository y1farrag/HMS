#hospital_project
#include <iostream>
#include <unordered_set>
#include<cctype>
#include<string.h>
#include<string>
#include<iomanip>
#include <chrono>
using namespace std;
class person
{
protected: 
    string name;
    int age;
    string gender; 
    string phoneNumber;
public:
    person(string n = " ", string gen = " ", int ag = 0, string pn = " "): name(n),age(ag),gender(gen), phoneNumber(pn){}
    
    getName(){
        return n;
    }
    getGender(){
        return gen;
    }
    getAge(){
        return ag;
    }
    getPhoneNumber(){
        return pn;
    }
};
class doctor :public person
{
private:
    string speclization;    
    string slot;
public:
doctor(string sp = " ", string sl = " "):speclization(sp),slot(sl){}
string getSp()
{
    return sp;
}
string getSlot(){
    return slot;
}
void displaySlot(){
    cout<< "slot is at : "<< slot << endl;
}
string getDetalis(){
    return slot;  //temprory//
}
 void updateSlot(){
slot is // need to be edit it//
}
};
class appoinment :
{
    private:
    int id;
    doctor doctor;
    doctor slot;

    public:
    appoinment(string i=" ",doctor dr = " ", doctor sl=" "):id(i),docotr(dr),slot(sl){}
    int getId(){
        return id;

    }
    string getDoctor(){
        return doctor;
    }
    string 
    
};