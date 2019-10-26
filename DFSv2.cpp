#include"bits/stdc++.h"
using namespace std;

std::vector<pair<int,int>>v;
std::vector<pair<int,int>>::iterator itr;
std::stack<int>s;
std::map<int,bool>m;

int main(int argc, char const *argv[])
{
	int k;
	int a,b;
	int flg=0;
	cout<<"Enter No.of Edges"; cin>>k;

	for(int i=0;i<k;i++)
	{
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}

	cout<<"Enter Start Node:";
	cin>>a;
	s.push(a);
	m[a] = true;
	cout<<a;
	while(s.empty() == false)
	{
		for(itr=v.begin();itr!=v.end();itr++)
		{
			if(itr->first == s.top() and m[itr->second] == false)
			{
				s.push(itr->second);
				cout<<s.top();
				m[itr->second] = true;
				flg=1;
				break;
			}
		}
		if(flg==0)
		{
			s.pop();
		}
		flg=0;
	}
	

	return 0;
}