#include <iostream>
#include <string>
using namespace std;

typedef struct Bt_node {
	Bt_node* left_child = NULL;
	int data = 0;
	Bt_node* Right_child = NULL;
};

int BST_min(Bt_node* root) //left node 场
{
	Bt_node* temp = root;
	while (temp->left_child != NULL) {
		temp = temp->left_child;
	}
	//int result= temp->data;
	return temp->data;
}

int BST_max(Bt_node* root, int key) //right node 场
{
	Bt_node* temp = root;
	while (temp->Right_child != NULL)
	{
		temp = temp->Right_child;
	}
	return temp->data;
}

Bt_node* BST_search_recursive(Bt_node* root, int key)// O(h)
{
	if (root == NULL)
		return NULL;
	if (key == root->data)
		return root;
	if (key < root->data)
		BST_search_recursive(root->left_child, key);
	if (key < root->data)
		BST_search_recursive(root->Right_child, key);
	return BST_search_recursive(root->Right_child, key);
}

Bt_node* BST_search_iteration(Bt_node* root, int key)// O(h)
{
	Bt_node* node = root;

	while (root != NULL)
	{
		if (key == root->data)
			return root;
		if (key < root->data)
			node = root->Right_child;
		else
			node = root->left_child;
	}
	return NULL;
}

Bt_node* BST_insert(Bt_node* root, int key) // O(h)
{
	Bt_node* node = root;
	Bt_node* parent_node = NULL;
	Bt_node* new_node = new Bt_node;
	new_node->data = key;

	if (node == NULL) {
		root = new_node;
		return root;
	}
	while (node != NULL)
	{
		parent_node = node;
		if (key < node->data)
			node = node->left_child;
		else
			node = node->Right_child;
	}
	if (parent_node->data < key)
		parent_node->Right_child = new_node;
	else
		parent_node->left_child = new_node;

	return root;
}

Bt_node* BST_delete(Bt_node* root, int key)
{
	Bt_node* curr = new Bt_node;
	curr = root;
	Bt_node* parent = new Bt_node;
	Bt_node* child = new Bt_node;
	Bt_node* successor = NULL;
	int k_value = 0;

	while (curr != NULL && curr->data != key)
	{
		parent = curr;
		if (key < curr->data)
			curr = curr->left_child;
		else
			curr = curr->Right_child;
	}
	if (curr == NULL)//昏力且单捞磐 x
		return NULL;

	if ((curr->left_child) == NULL && (curr->Right_child == NULL)) {
		if (curr != root) {
			if (parent->left_child = curr)
				parent->left_child = NULL;
			else
				parent->Right_child = NULL;
		}
		else
			root = NULL;

		delete curr;
	}

	else if ((curr->left_child == NULL) || (curr->Right_child == NULL))
	{
		if (curr->left_child == NULL)
			child = curr->Right_child;
		else
			child = curr->left_child;

		if (curr != root) {
			if (curr = parent->left_child)
				parent->left_child = child;
			else
				parent->Right_child = child;
		}
		else
			root = child;
		delete curr;
	}
	else {
		successor = curr->Right_child;
		while (successor->left_child != NULL)
		{
			successor = successor->left_child;
		}
		k_value = successor->data;
		BST_delete(root, successor->data);
		curr->data = k_value;
	}
	return root;
}



/*
if (root = NULL)
return NULL;
if (key = root->data)
return node;
*/
int main(void)
{
	Bt_node* root = NULL;

	BST_insert(root, 50);

	int eof = 10;
	while (eof)
	{
		BST_insert(root, eof);
		eof--;
	}


	return 0;
}