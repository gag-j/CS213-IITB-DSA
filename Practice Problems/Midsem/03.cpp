#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
};

// void push(Node** n, int new_data){	
// 	Node* last = *n;
// 	Node* new_node = new Node();
// 	new_node->data = new_data;
// 	new_node->next = NULL;
// 	while ((last)->next != NULL){
// 		(last) = (last)->next;
// 	}
// 	(last)->next = new_node;
// }

// void push(Node** head_ref, int new_data) 
// { 
//     /* allocate node */
//     Node* new_node = new Node(); 
  
//     /* put in the data */
//     new_node->data = new_data; 
  
//     /* link the old list off the new node */
//     new_node->next = (*head_ref); 
  
//     /* move the head to point to the new node */
//     (*head_ref) = new_node; 
// } 

void push(Node** n,int new_data){
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*n);
	(*n) = new_node;
}  

Node* newNode(int key){ 
    Node* temp = new Node; 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 

Node* cycle(Node** n){
	Node* slow = new Node();
	Node* fast = new Node();

	slow = *n;
	fast = *n;

	slow = slow->next;
	fast = fast->next->next;

	while (fast!=NULL && fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) break;
	}
	if (slow != fast) return NULL;

	slow = *n;
	while (slow!=fast){
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

int main() { 
    Node* head = newNode(1); 
    head->next = newNode(2); 
    head->next->next = newNode(3); 
    head->next->next->next = newNode(4); 
    head->next->next->next->next = newNode(5); 

    head->next->next->next->next->next = head->next->next; 
  
    Node* res = cycle(&head); 
    if (res == NULL) 
        cout << "No Loop"; 
    else
        cout << "Loop starting at data " << res->data; 
  
    return 0; 
}  