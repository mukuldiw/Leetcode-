#include<bits/stdc++.h>
using namespace std;

class node
{
	public:
		 int data;
		 node *next;
		 node(int x)
		 {
		 	data=x;
		 	next=NULL;
		 }
};
node* input()
{
	int data;
	node *head=NULL;
	cin>>data;
	while(data!=-1)
	{
		node *newnode= new node(data);
		if(head==NULL)
		{
			head= newnode;
		}
		else
		{
			node *temp = head;
			while(temp->next!=NULL)
			temp=temp->next;
			temp->next=newnode;
		}
		cin>>data;
	}
	return head;
}
node* print(node* head)
{
	node* temp=head;
	while(temp!=NULL)
	{
	
		
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int intersectPoint(node* head1,node* head2){
	int l1=0,l2=0;
	node* temp1 = head1;
	node* temp2 = head2;
	while(temp1){
		l1++;
		temp1 = temp1->next;
	}
	while(temp2){
		l2++;
		temp2 = temp2->next;
	}
	cout<<l1<<" "<<l2;
	node* temp;
	int x = 0;
	if(l1 > l2){
		temp1 = head1;
		temp2 = head2;
		x = l1-l2;
	}
	else { temp1 = head2; temp2 = head1; x = l2-l1; }
	
	while(x--){
		temp1 = temp1->next;
	}
	while(temp1){
		if(temp1->data == temp2->data)return temp1->data;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
}
int main() 
{
	node* head1=input();
//	print(head1);
	node* head2=input();
//	print(head2);
	cout<<"Intersection Point: "<<intersectPoint(head1,head2);
}
