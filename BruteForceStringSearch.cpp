#include"bits/stdc++.h"
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
typedef long long int ll;
vector<int>v;
vector<int>u;
priority_queue<int>pq;
std::map<int,int> m;
const int N=1e6+10;
/*--------------------------hbp16@hbp16-Inspiron-3543:-$------------------------------*/
int stringmatch(string s,int m,string ss,int n)
{
	int i,j;
	for(i=0;i<=m-n;i++)
	{
		j=0;
		while(j<n && ss[j] == s[i+j])
		{
			j++;
		}
		if(j==n){return i;}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	fast;
	ll n,k,i,j;
	string s,ss;
	ll hash[101]={};
	
	cin>>s>>ss;
	/*int chk = stringmatch(s,s.length(),ss,ss.length());
	cout<<chk;*/
	int f = s.find(ss);
	if(f!=string::npos)
	{
		cout<<f;
	}
	f = s.find(ss,f+1);
	if(f!=string::npos)
	{
		cout<<f;
	}
	return 0;
}