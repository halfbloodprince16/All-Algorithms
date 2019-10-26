#include"bits/stdc++.h"
using namespace std;

std::vector<pair<int,int>>v;
std::vector<pair<int,int>>::iterator itr;
std::queue<int>q;
std::map<int,bool>m;

int main(int argc, char const *argv[])
{
	int k,a,b,flg=0;
	cout<<"Enter No of Edges:"; cin>>k;

	for(int i=0;i<k;i++)
	{
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}

	cout<<"Enter Head"; cin>>a;
	q.push(a);
	cout<<a<<" ";
	m[a] = true;

	while(!q.empty())
	{
		int k = q.front();
		q.pop();
		m[k] = true;
		
		for(itr=v.begin();itr!=v.end();itr++)
		{
			if(itr->first == k and m[itr->second] == false)
			{
				q.push(itr->second);
				cout<<itr->second<<" ";
				m[itr->second] = true;
			}
		}
	}
	return 0;
}