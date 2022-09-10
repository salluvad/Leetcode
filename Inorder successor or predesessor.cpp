TreeNode* inorderSucc(TreeNode*root , TreeNode*p){
 TreeNode* suc = NULL:
  
  while(root!=NULL){
  if(p->val >root->val){
      root = root->roght;
  }else{   
   suc = root;
   root=root->left;
  }
  }
  return suc;
}
