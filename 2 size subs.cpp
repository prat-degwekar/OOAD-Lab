#include <iostream>

using namespace std;

void prod(int a[] , int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j = i+1 ; j<n ; j++)
        {
            cout<<a[i]<<" , "<<a[j]<<endl;
        }
    }
}

int main()
{
    int a[]={1,4,2,6,8};
    prod(a,5);
    return 0;
}
