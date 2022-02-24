//
//  main.cpp
//  quicksort
//
//  Created by William Crupi on 2/23/22.
//

#include <iostream>

void swap(int v[], int i, int j) {
    int temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
void quicksort(int v[], int n){
    int i, last;
    if ( n <=1 )
        return;
    swap(v, 0,rand() % n);
    last = 0;
    for (i = 1; i < n; i++)
        if (v[i] < v[0])
            swap(v, ++last, i);
    swap(v,0,last);
    quicksort(v,last);
    quicksort(v+last+1,n-last-1);
}
int main(int argc, const char * argv[]) {
    int v[7] = { 16, 2, 77, 40, 12071, 99, 3 };
    int n = 8;
    quicksort(v,n);
    for (int i = 1; i < n; i++)
        printf("%d ",v[i]);
     printf("\n");
    return 0;
}
