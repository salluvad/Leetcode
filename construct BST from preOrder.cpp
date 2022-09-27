
class Solution {
public:
    TreeNode* bstUtil(vector<int>& pre,int& preIndex,int key,int min ,int max){
        if(preIndex>=pre.size()){
            return NULL;
        }
        
        TreeNode* root = NULL;
        
        if(key>min and key<max){
            root = new TreeNode(key);
            preIndex++;
            
            if(preIndex<pre.size()){
                root->left = bstUtil(pre,preIndex,pre[preIndex],min,key);
            }
            if(preIndex<pre.size()){
                root->right = bstUtil(pre,preIndex,pre[preIndex],key,max);
            }
        }
        
        return root;
        
    }

TreeNode* bstFromPreorder(vector<int>& preorder) {
    if(preorder.size()==0){
        return NULL;
    }
    int preIndex = 0;
    return bstUtil(preorder,preIndex,preorder[0],INT_MIN,INT_MAX);
}
    
    
};
