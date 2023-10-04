#include<iostream>
using namespace std;

class node {
	public:
		int data;
		node*next;
		
		node(int val) {  //constructor where we'll send a val(value) and we want this value to go in our data field
			data=val;
			next=NULL;
		}
};
//insert node at head ie.beg
void insertAtHead(node* &head, int val) {
	node* n=new node(val);
	n->next=head;
	head=n;
}

//tail=insert at end
void insertAtTail(node* &head, int val) {

	node* n=new node(val);
	
	if(head==NULL) {
		head=n; //first node
		return;
	}
	
	node* temp=head;
	while(temp->next!=NULL) {
		temp=temp->next;
	}
	temp->next=n;
	
}
//print linked list
void display(node* head) {
		node* temp=head;
		while(temp!=NULL) {
			cout<<temp->data<<"->"; //printing temp data
			temp=temp->next;
		}
		cout<<"NULL"<<endl;
}
bool search(node* head, int key) {
	node* temp=head;
	while(temp!=NULL) {
		if(temp->data==key) {
			return true;
		}
		temp=temp->next;
	}
	return false;
}
//delete first node (we can't use n-1)
void deleteAtHead(node* &head) {
	node* todelete=head;
	head=head->next;
	delete todelete;
}

//delete last node (n-1)
void deletion(node* &head, int val) {
	
	if(head==NULL) {  //if the list is empty
		return;
	}
	
	//if only one node is present
	if(head->next==NULL) {
		deleteAtHead(head);
		return;
	}
	
	node* temp=head;
	while(temp->next->data!=val) {
		temp=temp->next;
	}
	node* todelete=temp->next;
	temp->next=temp->next->next;
	
	delete todelete;
}

int main() {
	
	node* head=NULL;
	insertAtTail(head,1);
	insertAtTail(head,2);
	insertAtTail(head,3);
	display(head);
	
	insertAtHead(head,4);
	display(head);
	
	cout<<search(head,3)<<endl;
	
	deletion(head,3);
	display(head);
	
	deleteAtHead(head);
	display(head);
	
	return 0;
}
