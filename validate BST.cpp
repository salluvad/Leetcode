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
    TreeNode* buildtree(vector<int>&A,long &i,long bound){
        // base case 
        if(i==A.size() || A[i]>bound){
            return NULL;
        }
        TreeNode* root = new TreeNode(A[i++]);
        root->left=  buildtree(A,i ,root->val);
        root->right =  buildtree(A,i , bound);
        
        return root;
    }
    
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // we need to keep track of upper bound ad its is a binmary search tree we will make use of that porperty ]
        long i = 0 ;
        return buildtree(preorder,i , INT_MAX);
    }
};
