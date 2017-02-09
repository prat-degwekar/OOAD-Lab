#include <iostream>
#include <algorithm>

using namespace std;

void fsort(int arr[] , int a ) 	//sorts arr[a] to arr[a+5]
{
	sort(arr+a , arr+a+5);
}

void swap(int &a , int &b)
{
	int c = a;
	a=b;
	b=c;
}

void runthru(int arr[], int n)	//does mid+ operation from 0 to n
{
	int si = (n/2);
	int ei = si+5;
	for(int i = 0 ; i<n ; i++)
	{
		//if arr[i] belongs to mid , gel where it belongs(@bel)
		//swap arr[bel] and arr[si] , then swap arr[i] and arr[bel] , then 5 sort (arr[si] to arr[ei])
		if(arr[i] > arr[si] && arr[i] < arr[ei])
		{
			int bel = si;
			/*if(arr[i] > arr[si+1])for(int i=0 ; i<100 ; i++)
		cout<<arr[i]<<" , ";
				bel++;
			if(arr[i] > arr[si+2])
				bel++;
			if(arr[i] > arr[si+3])
				bel++;
			if(arr[i] > arr[si+4])
				bel++;
			//found @bel*/

			//swap(arr[si] , arr[bel]);
			swap(arr[i] , arr[bel]);
			fsort(arr , si);
		}
	}

}

int main()
{
	int arr[100]={0};

	//creation of testing array

	for(int i=0 ; i<100 ; i++)
		arr[i] = i;	
	swap(arr[5] , arr[51]);
	swap(arr[8] , arr[53]);

	//created array

	//start by sorting mid 5

	int si = (100/2);
	fsort(arr , si);

	//sort mid 5

	//aray print

	cout<<"before : ";

	for(int i=0 ; i<100 ; i++)
		cout<<arr[i]<<" , ";

	cout<<endl<<endl<<"then : ";
	runthru(arr , 100);

	//generated mid+

	for(int i=0 ; i<100 ; i++)
		cout<<arr[i]<<" , ";

	//gg	
	cout<<"yello"<<endl;
	return 0;
}