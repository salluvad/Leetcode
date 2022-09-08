//striver

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
          if(root==NULL){
              return 0;
          }
        int res = 0 ;
        
        queue<pair<TreeNode*,int>> q;
        
        q.push({root,0});      // push root at index 0 , so left will be 2*i+1 ,2*i+2;
        
        while(!q.empty()){
            int size = q.size();
            int curr_min = q.front().second;
            int leftindex,rightindex;
            // to prevent overflow , we manage th index , we get the min index for alevel and  subtarct it form all indexex to make them zero based for that level
            for(int i = 0 ; i<size;i++){
                int curr_index=q.front().second-curr_min;
                TreeNode* temp = q.front().first;
                q.pop();
                if(i==0) leftindex = curr_index;
                if(i==size-1) rightindex = curr_index;            // size is right-left+1
                
                if (temp -> left)
                   q.push({temp -> left,curr_index * 2LL + 1});
                
                if (temp -> right) 
                    q.push({temp -> right,curr_index * 2LL + 2});
                
                                                    
            }
            res = max(res, rightindex - leftindex + 1);
        }
        return res;
    }
}
