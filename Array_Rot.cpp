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
void leftrotate(ll x[],ll n)
{
	ll temp = x[0];
	ll i,j;
	for(i=0;i<n-1;i++)
	{
		x[i] = x[i+1];
	}
	x[n-1] = temp;
}
void rightrotate(ll x[],ll n)
{
	ll temp = x[n-1];
	ll i,j;
	for(i=n-1;i>0;--i)
	{
		x[i] = x[i-1];
	}
	x[0] = temp;
}
void display(ll x[],ll n)
{
	ll i;
	for(i=0;i<n;i++)
	{
		cout<<x[i]<<" ";
	}
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	fast;
	ll n,k,i,j;
	cout<<"Enter Array Lenght"<<endl;
	cin>>n;
	cout<<"Enter Array Elements"<<endl;
	ll x[n];
	for(i=0;i<n;i++)
	{
		cin>>x[i];
	}
	ll ch;
	do
	{
		cout<<"Press 1:left rotate\n2:right rotate\n3:display"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1 : leftrotate(x,n);break;
			case 2 : rightrotate(x,n);break;
			case 3 : display(x,n);break;
		}
	}
	while(ch!=4);
	
	return 0;
}