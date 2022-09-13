//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    // when returning from the leaf nodes ,we need to retun info whether if its a bst , max and mim value and current sum and total sum 
struct Info
{
   
    int max; // Min value in subtree
    int min; // Max value in subtree
    bool isBST; // If subtree is BST
    int sum;    // sum rooted at that node
    int curr_max;
};    
public:
    Info maxSumBST_Util(TreeNode* root, int & maxsum) {
        if(root == NULL){
            return {INT_MIN,INT_MAX,true,0,0};
        }
        //leaf
        if (root->left == NULL && root->right == NULL) {
            maxsum= max(maxsum,root->val);
            cout << "max sum" << maxsum<< endl;
            return {root->val,root->val,true,root->val,maxsum};
        }
        //get the values from left and right sub trees
         // Store information about the left subtree
        Info L = maxSumBST_Util(root->left, maxsum);
 
    // Store information about the right subtree
        Info R = maxSumBST_Util(root->right, maxsum);
        
        //check if these values are valid for a BST
         Info BST;
 
    // If the subtree rooted under the current node
    // is a BST
         if (L.isBST && R.isBST && L.max < root->val && R.min > root->val) {
 
           BST.max = max(root->val, max(L.max, R.max));
           BST.min = min(root->val, min(L.min, R.min));
 
            maxsum = max(maxsum, R.sum + root->val + L.sum);
             BST.sum = R.sum + root->val + L.sum;
 
             // Update the current maximum sum
             BST.curr_max = maxsum;
 
             BST.isBST = true;
             return BST;
            }
        
         // If the whole tree is not a BST then
    // update the current maximum sum
    BST.isBST = false;
    BST.curr_max = maxsum;
    BST.sum = R.sum + root->val + L.sum;
 
    return BST;
    }
    
    int maxSumBST(TreeNode* root){
        int maxsum = INT_MIN;
        Info ans = maxSumBST_Util(root,maxsum);
        return (ans.curr_max<0)?0:ans.curr_max;
    }
};
