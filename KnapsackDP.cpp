#include"bits/stdc++.h"
using namespace std;
typedef long long int ll;

/*--------------------------hbp16@hbp16-Inspiron-3543:-$------------------------------*/
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
	for(i=0;i<n;i++)
	{
		cin>>w[i];
	}
	cout<<"Enter Profit per atom :";

	for(i=0;i<n;i++)
	{
		cin>>p[i];
	}

	ll v[n+1][m+1];

	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0 || j==0)
			{
				v[i][j] = 0;
			}
			else if(w[i-1] <= j)
			{
				v[i][j] = max(p[i-1]+v[i-1][j-w[i-1]],v[i-1][j]);
			}
			else
			{
				v[i][j] = v[i-1][j];
			}
		}
	}
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			cout<<v[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}