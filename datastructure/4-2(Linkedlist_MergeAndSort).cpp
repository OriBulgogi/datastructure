#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* link;
};

Node* create_linkedlsit(int arr[], int n) { // 최초 a, b 리스트 생성함수
	Node* head = NULL;

	for (int i = 0; i < n; i++) {
		Node* new_node = (Node*)malloc(sizeof(Node));
		new_node->data = arr[i];
		new_node->link = NULL;
		if (head == NULL) {
			head = new_node;
		}
		else {
			new_node->link = head;
			head = new_node;
		}
	}
	return head;
}

Node* attach(int data, Node* p) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->link = NULL;
	if (p != NULL) p->link = temp;
	return temp;
}

void print_node(Node* print_node) {
	while (print_node != NULL) {
		cout << print_node->data << "->";
		print_node = print_node->link;
	}
	cout << "NULL \n ";
}
int main() {
	int a[] = { 10, 20, 30 };
	int b[] = { 27, 25, 15 };
	Node* A = create_linkedlsit(a, 3);
	Node* B = create_linkedlsit(b, 3);
	Node* C = NULL;
	Node* head;

	Node* temp = A;
	int item = 25;
	int p = 2; //20-30사이 삽입 
	for (int i = 0; i < p - 1) {
		temp = temp->link;
	}
	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->data = item;
	new_node->link = temp->link;
	temp->link = new_node;
	printf(A.data);

	
	if (A->data < B->data) {
		C = attach(A->data, C);
		A = A->link;
	}else {
		C = attach(B->data, C);
		B = B->link;
	}
	head = C;
	while (A != NULL && B != NULL) {
		if (A->data < B->data) {
			C = attach(A->data, C);
			A = A->link;
		}
		else {
			C = attach(B->data, C);
			B = B->link;
		}
	}
	while (A != NULL) {
		C = attach(A->data, C);
		A = A->link;
	}
	while (B != NULL) {
		C = attach(B->data, C);
		B = B->link;
	}
	cout << "merge list :";
	print_node(head);
	return 0;
}