
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
                // If both n1 and n2 are smaller than root,
        // then LCA lies in left
        while(root!=NULL){
        if (root->val > p->val && root->val > q->val)
           root = root->left;
 
        // If both n1 and n2 are greater than root,
        // then LCA lies in right
        else if (root->val < p->val && root->val < q->val)
                root = root->right;
            else break;

        
    }
        return root;
    }   
};
