#include <iostream>
#include <string>
using namespace std;

typedef struct Bt_node {
	int data=0;
	Bt_node *left_child = NULL;
	Bt_node *right_child = NULL;

} Bt_node;

void Preorder_traversal(struct Bt_node *node)
{
	if (node != NULL) {
		cout << node->data <<" -> ";
		Preorder_traversal(node->left_child);
		Preorder_traversal(node->right_child);
	}
	
}

void inorder_traversal(struct Bt_node* node)
{
	if (node != NULL) {
		inorder_traversal(node->left_child);
		cout << node->data << " -> ";
		inorder_traversal(node->right_child);
	}
}

void postorder_traversal(struct Bt_node* node)
{
	if (node != NULL) {
		postorder_traversal(node->left_child);
		postorder_traversal(node->right_child);
		cout << node->data << " -> ";
	}
}
int node_count(struct Bt_node* node) 
{

	static int count = 0;

	if (node != NULL)
	{
		count++;
		node_count(node->left_child);
		node_count(node->right_child);
	}
	return count;
}

int Leaf_count(struct Bt_node* node)
{
	static int leaf_count = 0;

	if (node != NULL)
	{
		Leaf_count(node->left_child);
		if (node->left_child == NULL && node->right_child == NULL)
		{
			leaf_count++;
		}
		Leaf_count(node->right_child);
	}
	return leaf_count;
}
int main()
{
	Bt_node *root=new Bt_node, *node1 = new Bt_node, * node2 = new Bt_node, * node3 = new Bt_node, * node4 = new Bt_node, * node5 = new Bt_node;
	root->data = 5;
	node1->data = 7;
	node2->data = 9;
	node3->data = 2;
	node4->data = 6;
	node5->data = 8;
	root->left_child = node1;
	node1->left_child = node2;
	node2->right_child = node3;
	root->right_child = node4;
	node4->left_child = node5; //책의 예제와 같은 linkedlist를 이용한 tree 생성
	
	Preorder_traversal(root);
	cout << endl;
	inorder_traversal(root);
	cout << endl;
	postorder_traversal(root);
	cout << endl;

	int result = node_count(root);
	cout << result <<endl;

	result = Leaf_count(root);
	cout << result << endl;

	return 0;
}
