#include"bits/stdc++.h"
using namespace std;

typedef pair<char,int>ipair;
vector<pair<int,ipair>>v;
std::vector<pair<int,pair<char,int>>>::iterator itr,it;

int main(int argc, char const *argv[])
{
	int n;
	cout<<"Enter no. of jobs to be scheduled";
	cin>>n;

	char a;
	int i,j,b,c;
	int size=0;
	for(i=0;i<n;i++)
	{
		cin>>a>>b>>c;
		v.push_back({b,{a,c}});
		size = max(size,b);
	}
	sort(v.begin(),v.end(),greater<pair<int,pair<char,int>>>());
	/*for(itr=v.begin();itr!=v.end();itr++)
	{
		cout<<itr->second.first<<itr->second.second<<itr->first<<endl;
	}*/
	char ans[size];
	int id;
	for(i=0;i<size;i++)
	{
		ans[i] = '$';
	}
	for(itr=v.begin();itr!=v.end();itr++)
	{
		if(ans[itr->second.second-1] == '$')
		{
			ans[itr->second.second-1] = itr->second.first;
			id = itr->second.second; 
		}
		else
		{
			while(id>0)
			{
				if(ans[id-1] == '$')
				{
					ans[id-1] = itr->second.first;
					cout<<itr->second.first;
					break;
				}
				else
				{
					id--;
				}
			}
		}

	}
	for(i=0;i<size;i++)
	{
		if(ans[i]!='$')
			cout<<ans[i];
	}
	return 0;
}