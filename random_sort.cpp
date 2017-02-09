#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int sorted(int arr[] , int n)
{
	for(int i=0 ; i<n-1 ; i++)
	{
		if(arr[i] > arr[i+1])
			return 0;
	}

	return 1;
}

int check(int a[] , int n)
{
	for(int i=0 ; i<n ; i++)
	{
		if(a[i]==a[n])
			return 0;
	}

	return 1;
}

void shuffle(int arr[] , int n)
{
	int a[n];
	for(int i=0 ; i<n ; i++)
		a[i] = i;

	//shuffle routine
	srand(time(NULL) + arr[0] + arr[1] + arr[2]);
	for(int i=0 ; i<20 ; i++ , srand(rand()));
		srand(rand() + 200);

	for(int i=0 ; i<n ; i++)
	{
		a[i] = rand()%n;
		while(!check(a , i))
		{
			a[i] = rand()%n;
		}
	}

	for(int i=0 ; i<n ; i++)
		a[i] = arr[a[i]];

	for(int i=0 ; i<n ; i++)
		arr[i] = a[i];
}

int main()
{

	int arr[7] = {6,9,7,2,4,7,1};
	int ar[7] = {6,9,7,2,4,7,1};
	shuffle(arr , 7);

	for(int i=0 ; i<7 ; i++)
		cout<<arr[i]<<" ; ";
	cout<<endl;
	int c=0;
	/*while(!sorted(arr , 7))
	{
		shuffle(arr , 7);
	}*/
	for(int j=0 ; j<500000 ; j++)
	{
		for(int i=0 ; i<7 ; i++)
			arr[i] = ar[i];
		bool fl=0;
		for(int i=0 ; i<10 ; i++)
		{
			if(!sorted(arr , 7))
				{
					shuffle(arr , 7);
				}
			else
				{
					fl=1;
					break;
				}
		}
		if(fl==1)
		{
			c++;
			fl=0;
		}
		cout<<j<<" ";
	}

	for(int i=0 ; i<7 ; i++)
		cout<<arr[i]<<" / ";
	cout<<endl<<"c = "<<c<<endl;
	float per = (float)(c/500000.0)*100;
	cout<<"percentage = "<<per<<endl;
	return 0;
}
