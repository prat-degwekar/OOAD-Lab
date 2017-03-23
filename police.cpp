#include <iostream>
#include <queue>
using namespace std;

bool graph[1000][1000];

bool vis[27];

queue<int> q;
queue<bool> stat;

int count = 0;
int count2 = 0;

void bfs(int node , bool parity , int n)     //start with parity 1
{
   if(vis[node]==1)
      return;
   vis[node] = 1;

   if(parity == 1)
   	count++;

   for(int i=0 ; i<n ; i++)
   {
      if(graph[node][i] == 1)
      {
	 	q.push(i);
	 	stat.push(!parity);
	  }
   }
}

void bcheck(int n)
{
	bfs(0 , 0 , n);
	bool parity = 0;
	while(!q.empty())
	{
		bfs(q.front() , stat.front() , n);
		q.pop();
		stat.pop();
	}
}

void bfs2(int node , bool parity , int n)     //start with parity 1
{
   if(vis[node]==1)
      return;
   vis[node] = 1;

   if(parity == 1)
      count2++;

   for(int i=0 ; i<n ; i++)
   {
      if(graph[node][i] == 1)
      {
      q.push(i);
      stat.push(!parity);
     }
   }
}

void bcheck2(int n)
{
   bfs2(0 , 1 , n);
   bool parity = 1;
   while(!q.empty())
   {
      bfs2(q.front() , stat.front() , n);
      q.pop();
      stat.pop();
   }
}

void init()
{
   for(int i = 0 ; i<27 ; i++)
      for(int j = 0 ; j<27 ; j++)
	 graph[i][j] = 0;

   for(int i = 0 ; i<27 ; i++)
      vis[i] = 0;

}

void complement(int n)
{
   for(int i=0 ; i<n ; i++)
   {
      for(int j=0 ; j<n ; j++)
      {
         graph[i][j] = ~graph[i][j];
      }
   }
}

int clique(int n)
{
   complement(n);
   bcheck(n);
   bcheck2(n);
   int min = count;
   if(count2 < min)
      min = count2;
   int res = n - min;
   return res;
}
   

int main()
{
   cout<<"kk"<<endl;

   int n = 5;

   init();

   /*graph[0][1] = 1;
   graph[1][0] = 1;

   graph[1][2] = 1;
   graph[2][1] = 1;

   graph[1][3] = 1;
   graph[3][1] = 1;

   graph[3][4] = graph[4][3] = 1;

   graph[3][5] = graph[5][3] = 1;

   graph[5][6] = graph[6][5] = 1;

   graph[5][7] = graph[7][5] = 1;
   */

   //graph[0][1] = graph[1][0] = graph[1][2] = graph[2][1] = graph[2][3] = graph[3][2] = graph[3][4] = graph[4][3] = 1;

   //graph[0][1] = graph[1][0] = graph[0][2] = graph[2][0] = graph[1][2] = graph[2][1] = graph[2][3] = graph[3][2] = graph[1][3] = graph[3][1] = graph[0][3] = graph[3][0] = 1;

   graph[0][1] = graph[1][0] = graph[1][2] = graph[2][1] = graph[2][3] = graph[3][2] = graph[0][4] = graph[4][0] = graph[4][5] = graph[5][4] = graph[5][6] = graph[6][5] = 1;

   for(int i=0 ; i<8 ; i++)
   {
   	for(int j=0 ; j<8 ; j++)
   		cout<<graph[i][j]<<" ";
   	cout<<endl;
   }

   //bfs(0 , 1 , 8);
   bcheck(8);

   init();

   graph[0][1] = graph[1][0] = graph[1][2] = graph[2][1] = graph[2][3] = graph[3][2] = graph[0][4] = graph[4][0] = graph[4][5] = graph[5][4] = graph[5][6] = graph[6][5] = 1;

   bcheck2(8);

   cout<<"count = "<<count<<endl;
   cout<<"count2 = "<<count2<<endl;

   return 0;
}
