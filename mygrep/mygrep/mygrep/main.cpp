//
//  main.cpp
//  mygrep
//
//  Created by William Crupi on 12/5/21.
//

#include <iostream>
#include <string>
#include <bitset>

using namespace std;
int lessequal(string s, string t)
{
    return s.compare(t);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "fuck my ass";
    string t = "fuck my ass";
    int leq;
    leq = lessequal(s,t);
    if (leq < 0)
        cout << s << " is smaller than " << t << endl;
    if (leq == 0)
        cout << s << " is equal to " << t << endl;
    else
        cout << "Strings didn't match " << endl;
   
    cout << "Hello, World!\n";
    int subkey = 0b10011100;
    int bitoff = 0b10111100;
    int bitoff_and_7;
    subkey >>= (bitoff & 0x7);
    bitoff_and_7 = (bitoff & 0x7);
    bitset<8> y(bitoff_and_7);
    cout << y << '\n';
    bitset<8> x(subkey);
    cout << x << '\n';
    
    return 0;
}

