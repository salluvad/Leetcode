//same as height 
//we start post order traversal 
// and  at each node we calc.height and diametre 

Start traversing the tree recursively and do work in Post Order.
In the Post Order of every node , calculate diameter and height of the current node.
If current diameter is maximum then update the variable used to store the maximum diameter.
Return height of current node to the previous recursive call.
  
  
  
  class Solution {
private:
    int find_dia(TreeNode* root,int& dia){
        if(root==NULL){
            return 0;
        }
         int lh = find_dia(root->left,dia);
         int rh = find_dia(root->right,dia);
        
        dia = max(dia,lh+rh);
        
        return 1+max(lh,rh);
        
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0 ;
        
        // we use the height method and at each node we calc dia as left height + right height
        if(root == NULL){
            return 0;
        }
        
        find_dia(root,dia);
        return dia;
    }
};
