#include"bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
vector<pair<char,char>>v;
vector<pair<char,char>>::iterator itr;
vector<char>u;
vector<char>::iterator it;
priority_queue<int>pq;
std::map<char,bool> m;
std::stack<char>s;
const int N=1e6+10;
/*--------------------------hbp16@hbp16-Inspiron-3543:-$------------------------------*/

ll Knapsack(ll w[],ll p[] ,ll i,ll j,ll v[][100])
{
	if(v[i][j]<0)
	{
		if(j>=w[i])
		{
			v[i][j] = max(Knapsack(w,p,i-1,j,v),p[i]+Knapsack(w,p,i-1,j-w[i],v));
		}
		else
		{	
			v[i][j] = Knapsack(w,p,i-1,j,v);
		}
	}

	return v[i][j];
}


int main(int argc, char const *argv[])
{
	ll n,m,k,i,j;
	// n - no of atoms , m - size of sack , w[i] , p[i]
	cout<<"Enter No. of Atoms :";
	cin>>n;
	ll w[n],p[n];
	
	cout<<"Enter Sack Size :";
	cin>>m;
	cout<<"Enter Weights per atom :";
	for(i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	cout<<"Enter Profit per atom :";

	for(i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	
	ll v[100][100];
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0 || j==0)
			{
				v[i][j] = 0;
			}
			else
			{
				v[i][j] = -1;
			}
		}
	}

	Knapsack(w,p,n,m,v);

	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}