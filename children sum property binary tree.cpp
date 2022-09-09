//problem
The children sum property is defined as, For every node of the tree, the value of a node is equal to the sum of values of its children(left child and right child).

Note: 

The node values can be increased by 1 any number of times but decrement of any node value is not allowed.
A value for a NULL node can be assumed as 0.
You are not allowed to change the structure of the given binary tree

//Algo
We perform a simple dfs traversal on the tree.
For the base case, if the node is pointing to NULL, we simply return.
At every node, first we find the sum of values of the children( For a NULL child, value is assumed to be 0).
If node’s value > sum of children node value, we assign both the children’s value to their parent’s node value.
Then we visit the children using recursion.
After we return to the node after visiting its children, we explicitly set its value to be equal to the sum of its values of its children.


void reorder(node * root) {
  if (root == NULL) return;
  int child = 0;
  if (root -> left) {
    child += root -> left -> data;
  }
  if (root -> right) {
    child += root -> right -> data;
  }

  if (child < root -> data) {
    if (root -> left) root -> left -> data = root -> data;
    else if (root -> right) root -> right -> data = root -> data;
  }

  reorder(root -> left);
  reorder(root -> right);

  int tot = 0;
  if (root -> left) tot += root -> left -> data;
  if (root -> right) tot += root -> right -> data;
  if (root -> left || root -> right) root -> data = tot;
}
void changeTree(node * root) {
  reorder(root);
}
