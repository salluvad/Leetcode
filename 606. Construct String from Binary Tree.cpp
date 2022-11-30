class Solution {
public:
    void recur(TreeNode* root , string & res){
        if(root == NULL){
            return ;
        }
        //preorder 
        res+=to_string(root->val);
        //if leaf node
        if(root->left == NULL and root->right==NULL){
            return;
        }

        res+="(";
        recur(root->left,res);
        res+=")";
       
        if(root->right){
          res+="(";
          recur(root->right,res);
          res+=")";
        }
        
    }
    string tree2str(TreeNode* root) {
        string res = "";
        recur(root,res);
        return res;
        
    }
};
