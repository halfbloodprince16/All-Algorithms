#include"bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
vector<int>v;
vector<int>u;
priority_queue<int>pq;
std::map<int,int> m;
const int N=1e6+10;
/*--------------------------hbp16@hbp16-Inspiron-3543:-$------------------------------*/

int main(int argc, char const *argv[])
{
	fast;
	int n,k,i,j;

	int v,e,a,b;
	cin>>v>>e;

	int graph[100][100];
	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			if(i==j)
			{
				graph[i][j] = 0;
			}
			else
				graph[i][j] = N;
		}
	}
	for(i=0;i<e;i++)
	{
		cin>>a>>b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	int col[v],id,ucol[v];

	for(i=1;i<=v;i++)
	{
		cin>>col[i];
	}
	cin>>id;
	for(i=1;i<=v;i++)
	{
		if(col[i]==id)
		{
			ucol[i] = i;
		}
		else
			ucol[i] = -1;
	}


	int dis[v][v];

	for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			dis[i][j] = graph[i][j];
		}
	}

	for(k=1;k<=v;k++)
	{
		for(i=1;i<=v;i++)
		{
			for(j=1;j<=v;j++)
			{
				if(dis[i][k]+dis[k][j] < dis[i][j])
				{
					dis[i][j] = dis[i][k]+dis[k][j];
				}
			}
		}
	}

	/*for(i=1;i<=v;i++)
	{
		for(j=1;j<=v;j++)
		{
			cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}
*/
	int ans=N;
	for(i=1;i<=v-1;i++)
	{
		for(j=i+1;j<=v;j++)
		{
			if(ucol[i]!=-1 && ucol[j]!=-1)
			{
				if(dis[ucol[i]][ucol[j]] < ans)
				{
					ans = dis[ucol[i]][ucol[j]];
				}
				//cout<<ucol[i]<<" "<<ucol[j]<<endl;
			}
		}
	}

	cout<<ans;

	return 0;
}