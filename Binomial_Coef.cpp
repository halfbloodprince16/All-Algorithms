#include"bits/stdc++.h"
using namespace std;

int bin_coef(int n,int k)
{
	if(k==0||k==n)
	{
		return 1;
	}
	return bin_coef(n-1,k-1)+bin_coef(n-1,k);
	
}

int main(int argc, char const *argv[])
{
	int n,k;
	cout<<"Binomail Coeff.";
	cin>>n>>k;
	cout<<bin_coef(n,k);
	return 0;
}