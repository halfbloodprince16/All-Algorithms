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
};
struct node *head=NULL;
ll size=0;
void insert()
{
	int data;
	cout<<"Enter data";
	cin>>data;
	node *temp = new node();
	size++;
	temp->data = data;
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
	cout<<"Enter Data:";
	cin>>data;
	cout<<"Enter Position:";
	cin>>pos;
	if(pos > size || pos < 0){cout<<"wrong posn bitch";return;}
	int cnt=1;
	node *p = head;
	while(cnt <= pos-2)
	{
		cnt++;
		p = p->next;
	}
	//cout<<cnt;
	//cout<<p->data;
	node *temp = new node();
	node *t;
	temp->data = data;
	size++;
	t = p->next;
    p->next = temp;
    temp->next = t;
}

void del()
{
	int pos;
	cout<<"Enter Position:";
	cin>>pos;
	if(pos > size || pos < 0){cout<<"wrong posn bitch";return;}
	int cnt=1;
	node *p = head;
	if(pos == 1)
	{
		head = p->next;
		free(p);
		size--;
		return;
	}
	while(cnt < pos-1)
	{
		cnt++;
		p = p->next;
	}
	node *t;
	t = p->next->next;
	free(p->next);
	p->next = t;
	size--;
	cnt=1;
	return;
}

void reverse()
{
    node *current = head;
    node *prev = NULL, *next = NULL;


    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
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
			case 5:reverse();break;
		}
	}
	while(ch!=6);
	
	return 0;
}