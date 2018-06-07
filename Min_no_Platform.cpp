#include"bits/stdc++.h"
using namespace std;

std::vector<pair<int,int>>v;
vector<int>u;
std::vector<pair<int,int>>::iterator itr;

int main(int argc, char const *argv[])
{
	int n,m;
	cout<<"Enter no. trains arriving and departing: ";
	cin>>n>>m;
	int i,j;
	int x[n],y[m];
	int haha;
	for(i=0;i<n;i++)
	{
		cin>>haha;
		v.push_back(make_pair(haha,0));
	}
	for(i=0;i<m;i++)
	{
		cin>>haha;
		v.push_back(make_pair(haha,1));
	}
	
	sort(v.begin(),v.end());
	//cout<<v;
	int ans=0;
	for(itr=v.begin();itr!=v.end();itr++)
	{
		if(itr->second == 0)
		{
			ans++;
			u.push_back(ans);
		}
		else if(itr->second == 1)
		{
			ans--;
		}
	}
	cout<<*max_element(u.begin(),u.end());
	return 0;
}