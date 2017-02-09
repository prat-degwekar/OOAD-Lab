#include <iostream>
#include <stdlib.h>

using namespace std;

void sort1(int a[] , int n);

void sort2(int a[] , int n);

void sort3(int a[] , int n);

int main()
{
    int a[7]={0};
    for(int i=0 ; i<7 ; i++)
        a[i] = rand();
    for(int i=0 ; i<7 ; i++)
        cout<<a[i]<<" , ";
    cout<<endl;
    return 0;
}
