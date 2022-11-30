class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL){
            return root2;
        }
        if(root2 == NULL){
            return root1;
        }
        TreeNode* root3 = new TreeNode((root1?root1->val:0)+(root2?root2->val:0));
        root3->left = mergeTrees(root1->left,root2->left);
        root3->right = mergeTrees(root1->right,root2->right);
        
        return root3;
        
    }
};
