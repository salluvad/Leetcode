// recursively check left and righ sub trees if root data is same 
// 

bool areIdentical(node * node1, node * node2) {
  if (node1 == NULL && node2 == NULL)
    return true;
  else if (node1 == NULL || node2 == NULL)
    return false;

  return ((node1 -> data == node2 -> data) && 
          isIdentical(node1 -> left, node2 -> left) && 
          isIdentical(node1 -> right, node2 -> right));
}
