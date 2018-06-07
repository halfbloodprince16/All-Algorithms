#include"bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int x[11]={1,2,5,10,20,50,100,200,500,1000,2000};
	int n,i,flg=0;
	cout<<"Enter Amount";
	cin>>n;
	while(n>0)
	{
		for(i=0;i<11;i++)
		{
			if(n < x[i])
			{
				n = n-x[i-1];
				cout<<x[i-1]<<endl;
				flg=1;
				break;
			}
		}
		if(flg==0)
		{
			n = n-2000;
			cout<<"2000"<<endl;
		}
		flg=0;
	}
	return 0;
}