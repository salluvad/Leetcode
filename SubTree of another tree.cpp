

///https://leetcode.com/problems/subtree-of-another-tree/

class Solution {
public:
    bool isIdentical(TreeNode* p,TreeNode* q) {
         if (p == NULL && q == NULL) return true;
 
         if (q == NULL || p == NULL) return false;
        
         return (p->val == q->val) and isIdentical(p->right, q->right) &&
                                        isIdentical(p->left, q->left);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       if(!root or ! subRoot){
           return root==subRoot;
       }
        
        return isIdentical(root,subRoot) or (root->left and isSubtree(root->left,subRoot)) or (root->right and isSubtree(root->right,subRoot));     
    }
};
