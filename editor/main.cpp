#include <iostream>
#include <fstream>
using namespace std;
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    char data;
    ifstream fileObj("./demoFile.txt");
    if (!fileObj) {
        cout << "File is not existing" << endl;
        return -1;
    }
    else {
        while(!fileObj.eof()) {
            fileObj.get(data);
            cout << data;
        }
    }
    fileObj.close();
    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.