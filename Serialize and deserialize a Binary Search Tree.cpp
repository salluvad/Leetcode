// pre order and queue

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/608304/C%2B%2B-solution-using-queue-and-preorder-traversal

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //we will use pre order traversal for storing the nodes in serial order , seperated by comma as delimiter
        if(!root){
            return "N,";
        }
        return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //push the constructed string into a queue and deserialize it in an helper func.
         queue<string> q;
        string s;
        for(int i=0;i<data.size();i++){
            if(data[i]==','){
                q.push(s);
                s="";
                continue;
            }
            else {
                s+=data[i];
            }      
        }
        if(s.size()!=0)q.push(s);
        return deserialize_helper(q);
    }
    TreeNode* deserialize_helper(queue<string> &q) {
        string s = q.front();
        q.pop();
        if(s=="N"){
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(s));
        root->left=deserialize_helper(q);
        root->right=deserialize_helper(q);
        return root;      
    }
};
