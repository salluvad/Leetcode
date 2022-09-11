onlu node is given , go to right and go as left as possible
//if no right , its in the upper nodes , so follow the parent node as long as current node is its right node



    Node* inorderSuccessor(Node* node) {
           // the successor is somewhere lower in the right subtree
        if (node->right) {
            node = node->right;
            while (node->left) node = node->left;
            return node;   
        }
        
        // the successor is somewhere upper in the tree
        while (node->parent && node == node->parent->right) node = node->parent;
        return node->parent;
    }
};
