#include"bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
vector<int>v;
vector<int>u;
priority_queue<int>pq;
std::map<int,int> m;
const int N=1e6+10;
#define INF 99999
/*--------------------------hbp16@hbp16-Inspiron-3543:-$------------------------------*/

void display(int dist[][10],int V) 
{ 
    printf ("Shortest distances"
            " between every pair of vertices \n"); 
    for (int i = 0; i < V; i++) 
    { 
        for (int j = 0; j < V; j++) 
        { 
            if (dist[i][j] == INF) 
                printf("%7s", "INF"); 
            else
                printf ("%7d", dist[i][j]); 
        } 
        printf("\n"); 
    } 
}

void floydwarshalldp(int graph[][10],int v)
{
	int dis[10][10];
	int i,j,k;

	for(i=0;i<v;i++)
	{
		for(j=0;j<v;j++)
		{
			dis[i][j] = graph[i][j];
		}
	}

	for(k=0;k<v;k++)
	{
		for(i=0;i<v;i++)
		{
			for(j=0;j<v;j++)
			{
				if(dis[i][k]+dis[k][j] < dis[i][j])
				{
					dis[i][j] = dis[i][k]+dis[k][j];
				}
			}
		}
	}
	display(dis,v);
}

int main(int argc, char const *argv[])
{
	fast;
	ll n,k,i,j;
	string s;
	ll hash[101]={};
	int V=4;
	int graph[10][10] = { {0,   5,  INF, 10}, 
                      {INF, 0,   3, INF}, 
                      {INF, INF, 0,   1}, 
                      {INF, INF, INF, 0} 
                      }; 
    floydwarshalldp(graph,V);
	return 0;
}

