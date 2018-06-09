//Longest_Incre_Subsequence,
#include"bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int n,i,j,k;
	cin>>n;
	int x[n],l[n];
	for(i=0;i<n;i++)
	{
		cin>>x[i];
		l[i]=1;
	}
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(x[i] > x[j] && (l[i] < l[j]+1))
			{
				l[i] = l[j] +1;
			}
		}
	}
	cout<<*max_element(l,l+n);
	return 0;
}