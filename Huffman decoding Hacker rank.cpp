
/// given a huffman tree , and string s , traverse the string and print the node values if its leaf .



void decode_huff(node * root, string s) {
    string result = "";
    node* temp = root ;
    for(auto ch:s){
        if(ch == '0'){
            temp = temp->left;
        } else {
            temp = temp->right;
        }
        //check if its leaf
        if(temp->left == NULL and temp->right == NULL){
            result.push_back(temp->data);
            cout << result;
            result = "";
            temp = root;   
        }
    }
}
