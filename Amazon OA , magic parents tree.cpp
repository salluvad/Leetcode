Given a binary tree, count the total number of magic parents, where a node which is not NULL and has both left and right children and the sum of the number of nodes in the left subtree is odd and that of right subtree is even (or sum of nodes in the left subtree as even and right subtree as odd) should be considered as a magic parent. Node 1 is always the Root node

Input format:
The node_number string(representing the relative position of the node wrt root node,i.e node 1).

E.g:
This is representing a tree having a root node as 1 and 2 is the left child of node 1 and 3 is the right child of node 1 and 5 is the left child of node 3.

2 L
3 R
5 RL


// count the left and right nodes recurisvely 

int helper(Node* root, int& ans){
    if(!root) return 0;
    int left_nodes = helper(root->left, ans);
    int right_nodes = helper(root->right, ans);
    if(left_nodes > 0 && right_nodes > 0){
        if(left_nodes % 2 == 0 && right_nodes % 2 == 1) ans++;
        if(left_nodes % 2 == 1 && right_nodes % 2 == 0) ans++;
    }
    return 1 + left_nodes + right_nodes;
}

int count_magic_nodes(Node* root){
    int ans = 0;
    helper(root, ans);
    return ans;
}
