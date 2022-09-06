class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> in;
        TreeNode* curr = root;
        
        while(1){
            if(curr!=NULL){
                s.push(curr);
                curr = curr->left;
            } else {
                if(s.empty()){
                    break;
                } else {
                    TreeNode* temp = s.top();
                    in.push_back(temp->val);
                    s.pop();
                    curr=temp->right;
                }
            }
        }
        return in;
    }
};
