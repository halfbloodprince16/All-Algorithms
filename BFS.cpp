#include"bits/stdc++.h"
using namespace std;

std::vector<pair<int,int>> v;
std::vector<pair<int,int>>::iterator itr;
std::queue<int>q;
std::map<int,bool>m;

void bfs()
{
	int i,j,k;
	q.push(2);//choose a head

	while(!q.empty())
	{
		k = q.front(); q.pop();
		cout<<k<<" "; m[k] = true;

		for(itr = v.begin() ; itr!= v.end() ;itr++)
		{
			if(itr->first == k && m[itr->second] == false)
			{
				q.push(itr->second);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	v.push_back(make_pair(0,1));
	v.push_back(make_pair(0,2));
	v.push_back(make_pair(1,2));
	v.push_back(make_pair(2,0));
	v.push_back(make_pair(2,3));
	v.push_back(make_pair(3,3));

	m.insert(pair<int,bool>(0,false));
	m.insert(pair<int,bool>(1,false));
	m.insert(pair<int,bool>(2,false));
	m.insert(pair<int,bool>(3,false));
	bfs();
	return 0;
}