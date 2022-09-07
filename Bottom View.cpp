// idewa is to add horizontal distance to each node
//hd of root is 0 , for left its hd-1 and for right its hd+1
// use a queue and do level order traversal , by pushing left and right nodes
//use a map which uses hd as key and node ans value

void bottomView (Node* root) {
  
  if(root == NULL){
    return ;
  }
  
  queue<Node*> q;
  map<int , int> m;
  
  int hd = 0 ;
  root->hd=0;
   
  q.push(root);
  
  while(1q.empty()){
    node* temp = q.front();
    q.pop();
    
    hd= temp->hd;
    m[hd]=temp->val;
    
     if (temp->left != NULL)
        {
            temp->left->hd = hd-1;
            q.push(temp->left);
        }
 
        // If the dequeued node has a right child, add
        // it to the queue with a horizontal distance
        // hd+1.
        if (temp->right != NULL)
        {
            temp->right->hd = hd+1;
            q.push(temp->right);
        }
  }
   for (auto i = m.begin(); i != m.end(); ++i)
        cout << i->second << " ";
}
