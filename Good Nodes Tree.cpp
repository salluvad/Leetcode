/////

Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.


//////



class Solution {
public:
    int recur(TreeNode* root , int& count ,int max_val){
        if(root == NULL){
            return 0;
        }
        if(root->val>=max_val){
            count++;
            max_val = root->val;
        }
       
        
        recur(root->left,count,max_val);
        recur(root->right,count,max_val);
        
        return count;
    }
    int goodNodes(TreeNode* root) {
        //. do a preorder traversal (any order is fine)  , we need to send max value down to validate the good node condition
        int max_val = INT_MIN;
        int count =0;
        return recur(root,count,max_val);
    }
};
