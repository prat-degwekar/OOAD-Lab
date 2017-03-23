#include <iostream>
#include <algorithm>

using namespace std;

void input(int *weight , int* profit , float *pbyw , int n)									//input acceptance function
{
	for(int i=0 ; i<n ; i++)
		cin>>weight[i];

	for(int i=0 ; i<n ; i++)
		cin>>profit[i];

	for(int i=0 ; i<n ; i++)
		pbyw[i] = (float)(profit[i])/(float)(weight[i]);
}

int max(int a , int b)
{
	if(b>a)
		return b;
	return a;
}

void dp(int *weight , int* profit , int n , int w)											//working state
{
	int **m = new int*[n+1];																//maximize array
	for(int i=0 ; i<=n ; i++)
	{
		m[i] = new int[w+1];
	}

	//key => m[n,w] = max(m[i-1,w] , p + m[i-1,w-wi])

	for(int i=0 ; i<=n ; i++)
	{
		m[i][0] = 0;																		//base cases
	}

	for(int i=0 ; i<=w ; i++)
		m[0][i] = 0;

	//dp start

	for(int i=1 ; i<=n ; i++)
	{
		for(int j=1 ; j<=w ; j++)
		{
			if(j<weight[i-1])
				m[i][j] = m[i-1][j];
			else
				m[i][j] = max(m[i-1][j] , profit[i-1] + m[i-1][j-weight[i-1]]);
		}
	}

	cout<<"dp result : "<<m[n-1][w-1]<<endl;

	for(int i=0 ; i<=n ; i++)																//print
	{
		for(int j=0 ; j<=w ; j++)
			cout<<m[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

void greed(int* weight , int* profit , float* pbyw , int n , int w)							//fractional knapsack
{
	//to sort pbyw
	int* positions = new int[n];
	for(int i=0 ; i<n ; i++)
		positions[i] = i;

	sortit(pbyw , positions , n);
	int* sweight = new int[n];																//sorted weight array
	int* sprofit = new int[n];																//sorted profit array

	for(int i=0 ; i<n ; i++)
	{
		sweight[i] = weight[positions[i]];													//sorted weight at pos i = weight at original position positions[i]
		sprofit[i] = profit[positions[i]];													//ditto for profit	
	}


	//greedy gg start here
	int W=0;																				//total weight rememberance
	float prof = 0;
	for(int i=0 ; i<n ; i++)
	{
		if(sweight[i] + W <= w)
		{
			W += sweight[i];
			prof += sprofit[i];
		}
		else
		{
			prof += sprofit[i] * (w-W);
			W = w;
			break;
		}
	}
}

void container(int* weight , int n , int w)
{
	sort(weight , weight + n);
	int count = 0 , W = 0;																	//count : self explan. , W = total weight of knapsack used till iteration i
	for(int i=0 ; i<n ; i++)
	{
		if(weight[i] + W <= w)
		{
			count++;
			W += weight[i];
		}
	}

	cout<<"container answer = "<<count<<endl;
}

int main()
{
	int n=0 , w=0;
	cin>>n;
	cin>>w;
	int *weight = new int[n];																//weight array
	int *profit = new int[n];																//profit array
	float *pbyw = new float[n];																//profit per weight array
	input(weight , profit , pbyw , n);
	dp(weight , profit , n , w);
	//greed1(weight , profit , pbyw , n , w);
	container(weight , n , w);
	return 0;
}