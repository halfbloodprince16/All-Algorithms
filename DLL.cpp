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
struct node 
{
	int data;
	node *next;
	node *prev;
};
struct node *head=NULL;

void insert()
{
	int data;
	cout<<"Enter Data";
	cin>>data;
	node *temp = new node();
	temp->data = data;
	temp->prev = head;
	temp->next = head;
	head = temp;
}
void display()
{
	cout<<"\n";
	node *p = head;
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<"\n";
}

void insert_in_bw()
{
	int data,pos;
	cout<<"Enter Data";
	cin>>data;
	cout<<"Enter Position";
	cin>>pos;
	if(pos<0){cout<<"Enter correct posn bitch";return;}
	if(pos == 1)
	{
		node *temp = new node();
		temp->data = data;
		temp->prev = head;
		temp->next = head;
		head = temp;
		return;
	}

	node *p = head;
	int cnt=1;
	while(cnt <= pos-2)
	{
		cnt++;
		p = p->next;
	}

	node *temp = new node();
	temp->data = data;
	temp->next = p->next;
	p->next = temp;
	temp->prev = p;
	temp->next->prev = temp;

}

void del()
{
	int pos;
	node *p = head;
	int cnt=1;
	cout<<"Enter Position:";
	cin>>pos;
	if(pos == 1)
	{
		head= p->next;
		free(p);
		return;
	}
	while(cnt < pos)
	{
		cnt++;
		p = p->next;
	}
	//cout<<p->data;	
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
}

int main(int argc, char const *argv[])
{
	int ch;
	do
	{
		cout<<"1:Insert\n2:Display\n3:Insert in Between\n4:Delete\n5:Reverse";
		cin>>ch;
		switch(ch)
		{
			case 1:insert();break;
			case 2:display();break;
			case 3:insert_in_bw();break;
			case 4:del();break;
			/*case 5:reverse();break;*/
		}
	}
	while(ch!=6);
	
	return 0;
}