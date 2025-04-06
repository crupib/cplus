#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class House{
public:
    int height;
    int width;
    string color;
    string size;
};

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
/*
    House myHouse;
    myHouse.height = 100;
    myHouse.width = 200;
    myHouse.color = "white";
    myHouse.size = "Big";
    cout << "About the house: " << endl;
    cout << "Height: " << myHouse.height << endl;
    cout << "Width: " << myHouse.width << endl;
    cout << "Color: " << myHouse.color << endl;
    cout << "Size: " << myHouse.size << endl;
    string fruit[3] = {"apple", "banana", "cherry"};
    for (const auto &i: fruit)
        cout << i << " ";
    cout << endl;
    char str[] = "good";
    for (int i = 0; i < 4; i++)
        cout << str[i];
    cout << endl;
    char ch = 'C';
    cout.put(ch) << endl;
//    char c;
//    cin.get(c);
//    cout << c << endl;
//    string myString;
//    cout << "Please enter a sentence: " << endl;
//    getline(cin, myString);
//    cout << myString << endl;
    ofstream fileObj("../myFile.txt");
 //   string myString1 = "C++ is a very good Language.";
 //   fileObj << myString1 << endl;
 //   fileObj.close();
 //   cout << "Write to file successfully!" << endl;
 */
    char ch;
    ifstream fileObj("../myFile.txt");
    while (!fileObj.eof()) {
        fileObj.get(ch);
        cout << ch;
    }
//    getline(fileObj1,myString1);
//    cout << myString1 << endl;
    fileObj.close();
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.