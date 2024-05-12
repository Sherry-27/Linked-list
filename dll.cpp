#include<iostream>
 using namespace std;
 
 class Node {
 	public:
 	int data;
 	Node* next;
 	Node* prev;
 	Node (int d) {
 		this->data = d;
 		this->prev = NULL;
 		this->next = NULL;
	 }
	 
	~Node (){
    	int value = this -> data;
    	if(this->next!=NULL){
    		delete next;
    		this->next = NULL;
		}
		cout<<"memory is free for node with data: "<<value<<endl;
	}
	

};

 void InsertAtHead(Node* &head, int d) {
 	Node* temp = new Node(d);
 	temp-> next = head;
 	head->prev = temp;
 	head = temp;
 	
 }
 
 void InsertAtTail(Node* &tail, int d) {
 	Node* temp = new Node(d);
 	tail-> next = temp;
 	temp->prev = tail;
 	tail = temp;
}

void print(Node* head){
	Node* temp = head;
	
	while(temp != NULL){
		cout<< temp->data<<" ";
		temp = temp->next;
	}
	cout<<endl;
}

int getLength(Node* head){
	int len =0;
	Node* temp = head;
	
	while(temp != NULL){
		len++;
		temp = temp->next;
	}
	return len;
}

void InsertAtPosition(Node* &tail, Node* &head, int position, int d){
 	if(position==1){
 		InsertAtHead(head,d);
 		return;
	 }
 	Node* temp = head;
 	int cnt = 1;
 	while(cnt<position-1){
 		temp = temp->next;
 		cnt++; 
	 }
	 if(temp->next==NULL){
	 	InsertAtTail(tail, d);
	 	return;
	 }
	 Node* nodeToInsert = new Node(d);
	 nodeToInsert-> next = temp-> next;
	 temp-> next->prev = nodeToInsert;
	 temp-> next = nodeToInsert;
	 nodeToInsert->prev = temp;
	 
 }

 void deleteNode(int position, Node* &head){
 	if(position == 1){
 		Node* temp = head; 
 		temp->next->prev=NULL;
 		head = temp -> next;
 		temp->next = NULL;
 		delete temp;	
	 }
	 else
	 {
	 	Node* curr = head;
	 	Node* prev = NULL;
	 	int cnt =1;
	 	while(cnt<position) {
	 		prev = curr;
	 		curr = curr->next;
	 		cnt++;
		 }
		 
		 curr -> prev = NULL;
		 prev -> next = curr -> next;
		 curr -> next = NULL;
		 delete curr;
	 }
 }

int main(){
	Node* node1= new Node(10);
	Node* head = node1;
	Node* tail = node1;
	print (head);
	//cout << getLength(head)<<endl;
	
	InsertAtHead(head, 12);
 	
 	print(head);
 	
 	InsertAtHead(head, 27 );
 	
 	print(head);
	
	InsertAtHead(head, 17);
 	
 	print(head);
 	
 	InsertAtTail(tail, 71);
 	
 	print(head);
 	
 	InsertAtPosition(tail, head, 2, 101);
 	
 	print(head);
	
	InsertAtPosition(tail, head, 4, 900);
 	
 	print(head);
	
	InsertAtPosition(tail, head, 5, 151);
 	
 	print(head);
	
	deleteNode(2, head);
	
 	print(head);
 	
	
	return 0;
}
