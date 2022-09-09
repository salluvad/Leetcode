/*

If we observe, we are moving in a reverse postorder way : i.e  right, left, root. 
We take a reference variable (say prev) to store the previous node( initialized to NULL).
Whenever we visit a node, we set the right child to the prev and left child to NULL. 
Next we assign this current node to prev.
We perform the above two operations on all the nodes in the traversal.

*/

class Solution {
  node * prev = NULL;
  public:
    void flatten(node * root) {
      if (root == NULL) return;

      flatten(root -> right);
      flatten(root -> left);

      root -> right = prev;
      root -> left = NULL;
      prev = root;
    }

};
