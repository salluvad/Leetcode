//
You are given the root of a binary tree containing digits from 0 to 9 only.

Each root-to-leaf path in the tree represents a number.

For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer will fit in a 32-bit integer.

A leaf node is a node with no children.



class Solution {
public:
    int recur(TreeNode* root, int cur){
        if(root == NULL){
            return 0;
        }
        cur = cur*10+(root->val);
        //if leaf
        if(root->left == NULL and root->right == NULL){
            return cur;
        } 

        return recur(root -> left, cur) + recur(root -> right, cur); 
    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        return recur(root,0);
    }
};
