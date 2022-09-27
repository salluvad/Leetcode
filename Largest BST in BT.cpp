class Solution {

public:
    struct Info { 
    int size;   
    int max;   
    int min;
    // Size of largest BST which
    // is subtree of current node
    int ans;  
    bool isBST;
   };

    struct Info largestBSTSubtree_util(TreeNode* root) {
       // base case 
        if(root == NULL){
            return {0,INT_MIN,INT_MAX,0,true};  
        }
        //leaf node
        if(root->left == NULL and root->right == NULL){
            return {1,root->val,root->val,1,true};
        }
        
        //get the size from left and right , post order 
        Info left = largestBSTSubtree_util(root->left); 
        Info right = largestBSTSubtree_util(root->right); 
        
        //fill the return struct
        Info ret;
        ret.size = 1+(left.size+right.size);
        
        //check if its BST or not
        if(left.isBST and right.isBST and left.max < root->val and right.min>root->val){
            ret.min = min(root->val , left.min);
            ret.max = max(root->val,right.max);
            ret.ans = left.ans+right.ans+1;
            ret.isBST = true;
            return ret;
        }
        
        //if not BST
        ret.ans = max(left.ans,right.ans);
        ret.isBST = false;
        
        return ret;
        
    }
    
     int largestBSTSubtree(TreeNode* root) {
         return largestBSTSubtree_util(root).ans ;
     }
};
