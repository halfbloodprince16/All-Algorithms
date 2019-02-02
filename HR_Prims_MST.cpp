#include"bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
priority_queue<int>pq;
std::map<int,int> m;
const int N=1e6+10;
/*--------------------------hbp16@hbp16-Inspiron-3543:-$------------------------------*/

struct graph
{
	int u,v,w;

};

bool isaldone(map<int,bool> &m,int n)
{
	for(int i=1;i<=n;i++)
	{
		if(m[i]==false)
		{
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	fast;
	int v,e,i,j,a,b,c;
	cin>>v>>e;
	graph g[e];
	int vis[v];
	for(i=1;i<=v;i++)
	{
		vis[i] = N;
	}
	for(i=0;i<e;i++)
	{
		g[i].w=-1;
	}
	std::map<int,bool>m;
	for(i=0;i<v;i++)
	{
		m[i+1] = false;
	}

	for(i=0;i<2*e;i=i+2)
	{
		cin>>a>>b>>c;
		g[i].u = a;
		g[i].v = b;
		g[i].w = c;
		g[i+1].u = g[i].v;
		g[i+1].v = g[i].u;
		g[i+1].w = g[i].w;
	}

	for(i=0;i<2*e-1;i++)
	{
		for(j=i+1;j<2*e;j++)
		{
			if(g[i].u==g[j].u && g[i].v==g[j].v)
			{
				int k = min(g[i].w,g[j].w);
				g[i].w = k;
				g[j].u=g[j].v=g[j].w=-1;
			}
		}
	}
	int head,wt=0;
	cin>>head;
	vis[head] = N;
	m[head] = true;
	/*cout<<"Initial:";
	for(i=1;i<=v;i++)
	{
		cout<<vis[i]<<" ";
	}
	cout<<endl;*/
	int vv=v;
	while(!isaldone(m,v))
	{
		for(i=0;i<2*e;i++)
		{
			if(g[i].u == head && m[g[i].v]==false)
			{
				vis[g[i].v] = min(g[i].w,vis[g[i].v]);
			}
		}
		/*cout<<"Then:";
		for(i=1;i<=v;i++)
		{
			cout<<vis[i]<<" ";
		}
		cout<<endl;*/
		int min=N,id;
		for(i=1;i<=v;i++)
		{
			if(vis[i]<min)
			{
				min = vis[i];
				id=i;
			}
		}
		wt += vis[id];
		vis[id]=N;
		head = id;
		m[id] = true;
		//cout<<"Head:"<<head<<endl;
		

	}
	cout<<wt;
	/*for(i=1;i<=v;i++)
	{
		cout<<vis[i]<<endl;
	}*/
	return 0;
}

