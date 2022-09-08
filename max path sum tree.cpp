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
int maxsum(TreeNode* root, int & max){
    
    //get the max sum from left and right sub trees
    // ignore the negative values 
    // and at every nide return  node val + max(left , right sum);
    
    if(root == NULL){
        return 0;
    }
    
    int leftsum = std::max(0,maxsum(root->left,max));
    int rightsum = std::max(0,maxsum(root->right,max));
    max = std::max(max,root->val+leftsum+rightsum);
    
    return root->val+std::max(leftsum,rightsum);
    
}
public:
    int maxPathSum(TreeNode* root) {
        // we use recurision and method of finding the height approach
        int max = INT_MIN;
        maxsum(root,max);
        return max;
        
    }
};
