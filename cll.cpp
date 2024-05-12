#include<iostream>
 using namespace std;
 
 class Node {
 	public:
 	int data;
 	Node* next;
 	Node (int d) {
 		this->data = d;
 		this->next = NULL;
	 }
	 
	~Node (){
    	int value = this -> data;
    	if(this->next!=NULL){
    		delete next;
    		next = NULL;
		}
		cout<<"Memory is free for node with data: "<<value<<endl;
	}

};
void InsertNode(Node* &tail, int element, int d) {
 	if(tail == NULL){
 		Node* newNode = new Node(d);
 	    tail = newNode;
 	    newNode -> next = newNode;
 }
    else {
    	Node* curr = tail;
    	while(curr->data!=element){
    		curr = curr->next;
		}
		Node* temp = new Node(d);
		temp->next=curr->next;
		curr->next= temp;
	}
 

 }
 
 void print(Node* tail){
	Node* temp = tail;
	do {
		cout<< tail->data<<" ";
		tail=tail->next;		
	} while(tail!=temp);
	
	cout<<endl;
}

void deleteNode(int value, Node* &tail){
 	if(tail == NULL){
 		cout<< "list is empty, please check again"<< endl;
 		return;
 		
	 }
	 else
	 {
	 	Node* prev = tail;
	 	Node* curr = prev->next;
	 	
	 	while(curr->data!=value) {
	 		prev = curr;
	 		curr = curr->next;
		 }
		 prev -> next = curr -> next;
		 curr -> next = NULL;
		 delete curr;
	 }
 }

int main(){
	
	Node* tail = NULL;
	
	InsertNode(tail, 5,3);
 	
 	print(tail);
 	
 	InsertNode(tail, 3, 5);
 	
 	print(tail);
	
	InsertNode(tail, 5, 7);
 	
 	print(tail);
 	
 	InsertNode(tail, 7, 9);
 	
 	print(tail);
	
// 	InsertAtPosition(tail, head, 2, 101);
// 	
// 	print(head);
//	
//	InsertAtPosition(tail, head, 4, 900);
// 	
// 	print(head);
//	
//	InsertAtPosition(tail, head, 5, 151);
// 	
// 	print(head);
//	
	deleteNode(5, tail);
	
 	print(tail);
// 	
//	
	return 0;
}

