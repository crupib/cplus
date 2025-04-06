#include <iostream>
#include <string>

using namespace std;
class Time {
private:
    int hour;
public:
    void setHour(int h){
        int hour = h;
        cout << "The hour is: " << hour << endl;
    }
};

class A {
protected:
    int myVariable;
};
class B: A {
public:
    void myMethod() {
        myVariable = 100;
        cout << myVariable << endl;
    }
};
class Computer {
public:
    void method1 (){
        cout << "I am from the base class!" << endl;
    }
};
class Laptop:public Computer{
public:
void method2() {
    cout << "I am from the derived class!" << endl;
}
};
class Vehicle {
public:
    void drive(){
        cout << "I am driving a car!" << endl;
    }
};
class MyClass {
public:
    MyClass() {
        cout << "Construction called" << endl;
    }
    ~MyClass(){
        cout << "Destructor called" << endl;
    }

};
class Flower {
private:
    string color = "The flower is red";
public:
    void show(){
        cout << color << endl;
    }
    string v1 = "";
    string v2 = "";
    void beautify() { cout << "Green" << endl;}
    Flower () { v1 = "Red"; v2 = "Yellow";};
};
int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.
    auto lang = "C++";
    cout << "Hello and welcome to " << lang << "!\n";
    basic_string str1 = "C++ is good";
    basic_string str2 = "good";
    int index;
    index = str1.find(str2, 0);
    cout << "The index of the str2 is: " << index << endl;
    for (int i = 1; i <= 5; i++)
        cout << "i = " << i << endl;
    basic_string str3 = "Flower is beautiful!";
    basic_string str4 = "very ";
    str3.insert(10,str4);
    cout << str3 << endl;
    basic_string mystring = "";
    //cout << "Please input something and press Enter key.";
    //cout << endl;
    //getline(cin, mystring);
    //cout << "You have inputted: " << mystring << endl;
    Flower obj;
    cout << obj.v1 << endl;
    cout << obj.v2 << endl;
    obj.beautify();
    obj.show();
    MyClass obj2;
    Laptop obj3;
    obj3.method1();
    obj3.method2();
    Vehicle car;
    car.drive();
    B obj4;
    obj4.myMethod();
    Time obj5;
    obj5.setHour(10);
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.