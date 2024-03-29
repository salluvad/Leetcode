// C program to delete a BST
#include <stdio.h>
#include <stdlib.h>

// Given Node node
struct node {
	int key;
	struct node *left, *right;
};

// Function to create a new BST node
struct node* newNode(int item)
{
	struct node* temp
		= (struct node*)malloc(
			sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// Function to insert a new node with
// given key in BST
struct node* insert(struct node* node, int key)
{
	// If the tree is empty, return a new node
	if (node == NULL)
		return newNode(key);

	// Otherwise, recur down the tree
	if (key < node->key) {
		node->left = insert(node->left, key);
	}
	else if (key > node->key) {
		node->right = insert(node->right, key);
	}

	// Return the node pointer
	return node;
}

// Function to do inorder traversal of BST
void inorder(struct node* root)
{
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

// Function to delete the BST
struct node* emptyBST(struct node* root)
{
	struct node* temp;
	if (root != NULL) {

		// Traverse to left subtree
		emptyBST(root->left);

		// Traverse to right subtree
		emptyBST(root->right);

		printf("Released node:%d \n", root->key);
		temp = root;

		// Require for free memory
		free(temp);
	}
	return root;
}

// Driver Code
int main()
{
	/* Let us create following BST 
			50 
		/	 \ 
		30	 70 
		/ \ / \ 
	20 40 60 80 
*/
	struct node* root = NULL;

	// Creating the BST
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	printf("BST before deleting:\n");
	inorder(root);

	// Function Call
	root = emptyBST(root);

	return 0;
}
