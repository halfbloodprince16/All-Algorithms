//Cycle_in_DirectedGraph.cpp
#include"bits/stdc++.h"
using namespace std;

std::vector<pair<int,int>> v;
std::vector<pair<int,int>>::iterator itr;
std::stack<int>s;
std::map<int,bool>m;
std::vector<int>w;
void dfs()
{
	int i,j,flg=0;
	s.push(2);//choose a head
	w.push_back(2);
	//cout<<s.top(); m[s.top()] = true;
	while(!s.empty())
	{
		for(itr = v.begin() ; itr!= v.end() ;itr++)
		{
			if(itr->first == s.top() && m[itr->second] == false)
			{
				s.push(itr->second);
				w.push_back(itr->second);
				//cout<<s.top(); m[s.top()] = true;
				flg=1;
				break;
			}
			if(itr->first == s.top() && m[itr->second] == true && find(w.begin(),w.end(),itr->second)!=w.end())
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
	v.push_back(make_pair(0,1));
	v.push_back(make_pair(1,2));
	v.push_back(make_pair(2,3));
	v.push_back(make_pair(3,0));
	/*v.push_back(make_pair(2,3));
	v.push_back(make_pair(3,3));*/

	m.insert(pair<int,bool>(0,false));
	m.insert(pair<int,bool>(1,false));
	m.insert(pair<int,bool>(2,false));
	m.insert(pair<int,bool>(3,false));
	dfs();
	return 0;
}