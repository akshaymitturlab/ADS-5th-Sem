#include <bits/stdc++.h> 
using namespace std; 

class Node { 
	public: 
	int data; 
	Node* next; 
}; 

Node *reversek (Node *head, int k) { 
	Node* current = head; 
	Node* next = NULL; 
	Node* prev = NULL; 
	int count = 0; 
	
	while (current != NULL && count < k) { 
		next = current -> next; 
		current -> next = prev; 
		prev = current; 
		current = next; 
		count++; 
	} 
	
	if (next != NULL) head -> next = reversek(next, k); 

	return prev; 
} 

void insert(Node** head, int val) { 
	Node* node = new Node(); 
	node -> data = val; 
	node -> next = *head;	 
	*head = node; 
} 

void print(Node *node) { 
	while (node != NULL) { 
		cout << node -> data << " "; 
		node = node -> next; 
	} 
} 

int main() { 
	Node* head = NULL; 
  cout << "Enter Number of Values and K \n";
  int n, k;
  cin >> n >> k;

  while (n--) {
    int val;
    cin >> val;
    insert(&head, val);
  }

	cout << "Given linked list \n"; 
	print(head); 
	head = reversek(head, k); 

	cout << "\nReversed Linked list \n"; 
	print(head); 

	return 0; 
} 
