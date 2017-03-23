#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

/*inline void swap(int a , int b)		//definition of macro copy pasted into code due to inline issues...
{
	int temp = a;
	a = b;
	b = temp;
}*/

void insertion(int a[] , int p , int r)
{
	int i=p+1;
	for(i = p+1 ; i<=r ; i++)
	{
		int k = a[i];
		int j = i-1;
		for(j = i-1 ; j>=p ; j--)
		{
			if(a[j]>=k)
			{
				a[j+1] = a[j];
			}
			else
				break;
		}
		a[j+1] = k;
	}
}

int partition(int a[] , int p , int r)
{
	int pivot = a[r];

	int i = p-1;
	for(int j = p ; j<r ; j++)
	{
		if(a[j] < pivot)
		{
			//swap(a[i+1] , a[j]);
			int temp = a[i+1];
			a[i+1] = a[j];
			a[j] = temp;
			i++;
		}
	}
	//swap(a[i+1] , a[r]);
	int temp = a[i+1];
	a[i+1] = a[r];
	a[r] = temp;
	i++;
	return (i);
}

void qusort(int a[] , int p , int r)
{
	if(p>=r)
		return;
	if(p<r && (r-p)>20)
	{
		int q = partition(a , p , r);
		qusort(a , p , q-1);
		qusort(a , q+1 , r);
		return;
	}
	else		//not really required
	{
		insertion(a , p , r);
	}

}

int main()
{
	int a[8] = {-1 , 90 , 0 , 8 , 7 , 23 , 46 , -7};

	qusort(a , 0 , 7);

	cout<<"sorted array by proposed sorting technique : "<<endl;

	for(int i=0 ; i<8 ; i++)
		cout<<a[i]<<" , ";
	cout<<endl;
	clock_t t1;
	long double sec=0;
	t1 = clock();
	for(int i=0 ; i<100 ; i++)
	{
		int arr[1000]={0};
		srand(time(NULL));

		for(int j=0 ; j<1000 ; j++)
			arr[j] = rand();

		qusort(arr , 0 , 999);
	}

	sec += ((long double)clock() - (long double)t1)/CLOCKS_PER_SEC;

	cout<<"time taken = "<<sec<<" seconds.\n\n";

	return 0;
}