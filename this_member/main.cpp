#include <iostream>
using namespace std;
class MyClass {
public:
    static void staticFun() {
        cout << "This is a static function." << endl;
    }
};
class Account {
public:
    static int num;
    void setHour(int num);
};
//void Time::setHour(int num) {
//    this-> num = num;
// cout << "The hour is: " << num << endl;
//}
void myself(int n){
    cout << "Number " << n << endl;
    ++n;
    if (n == 4) return;
    else myself(n);
}
int Account::num = 100;
int main() {
    cout << Account::num << endl;
    MyClass::staticFun();
    MyClass obj;
    obj.staticFun();
    int num = 10, result;
    result = num++ - 3;
    cout << result << "," << num << endl;
    num = 10;
    result = ++num - 3;
    cout << result << "," << num << endl;
    myself(1);
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.