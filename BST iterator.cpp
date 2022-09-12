**
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
class BSTIterator {
    // we use a a stack and keep pushing all left elements , in the constructor push all the left elements from the root
    // while doimng next operation , if it has right , push all the elemnets of the right into stack , basically we are doing 
    //in order traversal in steps to take o(H) avg space
    
stack<TreeNode*> s;
void pushleft(TreeNode* node){
    
    for(;node!=NULL ;node=node->left){
        s.push(node);
    }
    
}
public:
    BSTIterator(TreeNode* root) {
        pushleft(root);
    }
    
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        pushleft(temp->right);
        return temp->val;     
    }
    
    bool hasNext() {
        return !s.empty();
    }
};
