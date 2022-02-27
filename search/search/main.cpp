//
//  main.cpp
//  search
//
//  Created by William Crupi on 2/24/22.
//
//  Code journey
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define NELMS(array) (sizeof array) / sizeof (array[0])

using namespace  std;

typedef struct Nameval NAMEVAL;
struct Nameval {
//    char * name;
    string name;
    int value;
};
int lookup(string name, Nameval tab[], int ntab){
    int low, high, mid, cmp;
 
    low = 0;
    high = ntab-1;
    while (low <= high) {
        mid = (low + high)/2;
        cmp = name.compare(tab[mid].name);
        if (cmp < 0)
            high = mid-1;
        else if (cmp > 0)
            low = mid + 1;
        else
            return mid;
    }
    return 0;
}

Nameval htmlchars[] = {
    "AElig",  0x00c6,
    "Aacute", 0x00c1,
    "Acirc",  0x00c2,
    "zeta",   0x03b6,
};

int main(int argc, const char * argv[]) {
    int half;
    printf("The HTML table has %lu words\n", NELMS(htmlchars));
    cout << "Hello, World!\n";
    half = lookup("Acirc", htmlchars, NELMS(htmlchars));
    cout << "htmlchars = " << htmlchars[half].name << "\n";
    printf("half = %d\n", half);
    return 0;
}
