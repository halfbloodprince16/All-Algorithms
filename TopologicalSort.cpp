#include"bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
vector<pair<char,char>>v;
vector<pair<char,char>>::iterator itr;
vector<char>u;
vector<char>::iterator it;
priority_queue<int>pq;
std::map<char,bool> m;
std::stack<char>s;
const int N=1e6+10;
/*--------------------------hbp16@hbp16-Inspiron-3543:-$------------------------------*/

void topsort()
{
	int i,j;
	m['a'] = true; //we visit 'a' as it is  a head
	char k = 'a';
	u.push_back('a');
	int flg=0;
	for(itr=v.begin();itr!=v.end();itr++)
	{
		if(itr->first == k && m[itr->second] == false)
		{
			u.push_back(itr->first);
			m[itr->first] = true;
			k = itr->second;
			flg=1;
		}
		if(flg==0)
		{
			for(itr=v.begin();itr!=v.end();itr++)
			{
				if(itr->first==false)
				{
					k = itr->first;
				}
			}
		}
		flg=0;
	}

	for(it=u.begin();it!=u.end();it++)
	{
		cout<<*it<<"->";
	}
}

int main(int argc, char const *argv[])
{
	fast;
	ll n,k,i,j;
	ll hash[101]={};
	
	v.push_back(make_pair('a','b'));
	v.push_back(make_pair('a','f'));
	v.push_back(make_pair('d','c'));
	v.push_back(make_pair('d','h'));
	v.push_back(make_pair('d','i'));
	v.push_back(make_pair('d','e'));
	v.push_back(make_pair('e','i'));
	v.push_back(make_pair('g','a'));
	v.push_back(make_pair('g','b'));
	v.push_back(make_pair('g','c'));
	v.push_back(make_pair('i','c'));
	v.push_back(make_pair('j','e'));


	m.insert(pair<char,bool>('a',false));
	m.insert(pair<char,bool>('b',false));
	m.insert(pair<char,bool>('c',false));
	m.insert(pair<char,bool>('d',false));
	m.insert(pair<char,bool>('e',false));
	m.insert(pair<char,bool>('f',false));
	m.insert(pair<char,bool>('g',false));
	m.insert(pair<char,bool>('h',false));
	m.insert(pair<char,bool>('i',false));
	m.insert(pair<char,bool>('j',false));
	topsort();
	return 0;
}