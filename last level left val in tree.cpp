class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        // use reverse order BFS from right to LEft    
       queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            root=q.front(); // get the value before pop coz pop will not return anyy val
            q.pop();
            if (root->right) {
                q.push(root->right);
            }
            if(root->left) q.push(root->left);
        }
        return root->val;
    }
};
