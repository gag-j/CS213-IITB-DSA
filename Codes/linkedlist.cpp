#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
};

void print_list(Node* n){
	while(n != NULL){
		cout << n->data << " ";
		n = n->next;
	}
	cout<<endl;
}

void push_front(Node** n,int new_data){
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*n);
	(*n) = new_node;
}

void push_after(Node* n, int new_data){
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (n)->next;
	(n)->next = new_node;
}

void push_back(Node** n, int new_data){	
	Node* last = *n;
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = NULL;
	while ((last)->next != NULL){
		(last) = (last)->next;
	}
	(last)->next = new_node;
}

void delete_key(Node** n, int key){
	Node* travel = *n;
	while (travel != NULL && travel->data != key){
		travel = travel->next;
	}
	if (travel == NULL) return;
	travel->data = travel->next->data;
	travel->next = travel->next->next;
}

void delete_node(Node** n, int position){
	Node* prev = new Node();
	prev = (*n);
	if (position == 0){
		prev->data = prev->next->data;
		prev->next = prev->next->next;
	}
	else{
		for(int i=0;i<position;i++){
			prev = prev->next;
		}
		prev->data = prev->next->data;
		prev->next = prev->next->next;
	}
}

int main(){
	Node* head = NULL;
	Node* second = NULL;
	Node* third = NULL;

	head = new Node(); 
    second = new Node(); 
    third = new Node();

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	print_list(head);
	push_front(&head,0);
	print_list(head);
	push_after(head->next,5);
	print_list(head);
	push_back(&head, 6);
	print_list(head);
	delete_key(&head, 7);
	print_list(head);
	delete_node(&head,1);
	print_list(head);
	return 0;
}

