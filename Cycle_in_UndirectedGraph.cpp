//Cycle_in_UndirectedGraph.cpp
#include"bits/stdc++.h"
using namespace std;

std::vector<pair<int,int>> v;
std::vector<pair<int,int>>::iterator itr;
std::stack<int>s;
std::map<int,bool>m;

void dfs()
{
	int parent=-1;//starting parent node as -1
	int i,j,flg=0;
	s.push(1);//choose a head
	cout<<s.top(); m[s.top()] = true;
	while(!s.empty())
	{
		for(itr = v.begin() ; itr!= v.end() ;itr++)
		{
			if(itr->first == s.top() && m[itr->second] == false)
			{
				s.push(itr->second);
				cout<<s.top(); m[s.top()] = true;
				flg=1;
				parent = itr->first;
				break;
			}
			if(itr->first == s.top() && m[itr->second] == true && parent != itr->second)
			{
				cout<<"CYCLE FOUND";
				return ;
			}
		}
		if(flg==0)
		{
			s.pop();
		}
		flg=0;
	}
}

int main(int argc, char const *argv[])
{
	v.push_back(make_pair(1,0));
	v.push_back(make_pair(0,2));
	v.push_back(make_pair(2,0));
	v.push_back(make_pair(0,3));
	v.push_back(make_pair(3,4));


	m.insert(pair<int,bool>(0,false));
	m.insert(pair<int,bool>(1,false));
	m.insert(pair<int,bool>(2,false));
	m.insert(pair<int,bool>(3,false));
	m.insert(pair<int,bool>(4,false));
	dfs();
	return 0;
}