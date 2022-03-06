//
//  main.cpp
//  growing_array
//
//  Created by William Crupi on 3/5/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
typedef struct Namevel Namevel;
struct Namevel
{
    string name;
    int value;
};

struct NVtab
{
    int nval;         // current number of values
    int max;          // allocated number of values
    Namevel *namevel; // array of name-value pairs
} nvtab;

enum
{
    NVINIT = 1,
    NVGROW = 2
};

// addname: add new name and value to nvtab
int addname(Namevel newname)
{
    Namevel *nvp;
    if (nvtab.namevel == NULL) // first time
    {
        nvtab.namevel = (Namevel *)malloc(NVINIT * sizeof(Namevel));
        if (nvtab.namevel == NULL)
            return -1;
        nvtab.max = NVINIT;
        nvtab.nval = 0;
    }
    else if (nvtab.nval >= nvtab.max) // grow
    {
        nvp = (Namevel *)realloc(nvtab.namevel, (NVGROW * nvtab.max) * sizeof(Namevel));
        if (nvp == NULL)
            return -1;
        nvtab.max *= NVGROW;
        nvtab.namevel = nvp;
    }
    nvtab.namevel[nvtab.nval] = newname;
    return nvtab.nval++;
}

// delname: remove first matching nameval from nvtab
int delname(string name)
{
    int i;
    for (i = 0; i < nvtab.nval; i++)
    {
        if (nvtab.namevel[i].name.compare(name) == 0)
        {
            memmove(nvtab.namevel + i, nvtab.namevel + i + 1, (nvtab.nval - (i + 1)) * sizeof(Namevel));
            nvtab.nval--;
            return 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    Namevel nv;
    nv.name = "abc";
    nv.value = 1;
    addname(nv);
    nv.name = "def";
    nv.value = 2;
    addname(nv);
    nv.name = "ghi";
    nv.value = 3;
    addname(nv);
    nv.name = "jkl";
    nv.value = 4;
    addname(nv);
    nv.name = "mno";
    nv.value = 5;
    addname(nv);
    nv.name = "pqr";
    nv.value = 6;
    addname(nv);
    nv.name = "xyz";
    nv.value = 7;
    addname(nv);
    nv.name = "cba";
    nv.value = 8;
    addname(nv);
    nv.name = "edf";
    nv.value = 9;
    addname(nv);
    printf("%s %d\n", nvtab.namevel->name.c_str(), nvtab.namevel->value);
    printf("%s %d\n", nvtab.namevel[1].name.c_str(), nvtab.namevel[1].value);
    printf("%s %d\n", nvtab.namevel[2].name.c_str(), nvtab.namevel[2].value);
    printf("%s %d\n", nvtab.namevel[8].name.c_str(), nvtab.namevel[8].value);
    printf("nval: %d max: %d\n", nvtab.nval, nvtab.max);
    //string delstring = "abc";
    delname("abc");
 //   printf("nval: %d max: %d\n", nvtab.nval, nvtab.max);
    return 0;
}
