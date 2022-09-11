// for a given key fornd the maximum of smaller vaues than key .
// so go left once and keep going right


int floor(Node* root , int key){
 int floor = -1;
  if(root->val == key){
   floor = root->val;
    return floor;
  }
  if(key>root->val){
   floor = root->val;
    root= root->right;
  } else {
   root = root->left; 
  }
  return floor;
  
}
