#include "bits/stdc++.h"
using namespace std;

std::vector<pair<int,int>>v;
std::vector<pair<int,int>>::iterator itr;
std::stack<int>s;
std::map<int,bool>m;

void dfs()
{
    s.push(1);
    cout<<"1->";
    m[1] = true;
    int flg=0;
    while(!s.empty())
    {
        for(itr=v.begin();itr!=v.end();itr++)
        {
            if(itr->first == s.top() && m[itr->second]==false)
            {
                s.push(itr->second);
                cout<<itr->second<<"->"; 
                m[itr->second]=true;
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
}

int main() 
{
	v.push_back(make_pair(1,2));
	v.push_back(make_pair(1,3));
	v.push_back(make_pair(2,1));
	v.push_back(make_pair(2,4));
	v.push_back(make_pair(2,5));
	v.push_back(make_pair(3,1));
	v.push_back(make_pair(3,5));
	v.push_back(make_pair(4,2));
	v.push_back(make_pair(4,5));
	v.push_back(make_pair(4,6));
	v.push_back(make_pair(5,2));
	v.push_back(make_pair(5,3));
	v.push_back(make_pair(5,4));
	v.push_back(make_pair(5,6));
	v.push_back(make_pair(6,4));
	v.push_back(make_pair(6,5));
	
	m.insert(pair<int,bool>(1,false));
	m.insert(pair<int,bool>(2,false));
	m.insert(pair<int,bool>(3,false));
	m.insert(pair<int,bool>(4,false));
	m.insert(pair<int,bool>(5,false));
	m.insert(pair<int,bool>(6,false));
	dfs();
}
