//Given the root of a binary tree, return the zigzag level order traversal of Binary Tree. 
//(i.e., from left to right, then right to left for the next level and alternate between).

// we use a variable to indicate the direction 

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        // we do regular level order treversal with a varible which indicates the dir
        if(root == NULL){
            return {};
        }
        vector<vector<int>> ans;
        int leftToright = 1;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);   
            int index = 0;
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                leftToright?index = i :index = size-1-i;
                temp[index] = node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);                
            }
        leftToright = !leftToright ;
        ans.push_back(temp);
        }
        return ans;
    }
};
