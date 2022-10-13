Algo :
find the Lowest COmmon Ansc and cal distance to each of the nodes and add them 

//
// Returns level of key k if it is present in
// tree, otherwise returns -1

int findLevel(Node* root, int k, int level)
{
    if (root == NULL)
        return -1;
    if (root->key == k)
        return level;
 
    int left = findLevel(root->left, k, level + 1);
    if (left == -1)
        return findLevel(root->right, k, level + 1);
    return left;
}

// 

int findDistance(Node* root, int a, int b)
{
    // Your code here
    Node* lca = LCA(root, a, b);   // LCA code
 
    int d1 = findLevel(lca, a, 0);
    int d2 = findLevel(lca, b, 0);
 
    return d1 + d2;
}
  

  
