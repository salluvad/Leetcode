class Solution {
  public:
    vector <int> bottomView(Node *root) {
       if (root == NULL)
        return {};
 
    // Initialize a variable 'hd' with 0
    // for the root element.
    int hd = 0;
 
    // TreeMap which stores key value pair
    // sorted on key value
    map<int, int> m;
 
    // Queue to store tree nodes in level
    // order traversal
    queue<pair<Node * ,int>> q;
 
    // Assign initialized horizontal distance
    // value to root node and add it to the queue.
    
    q.push({root,0});  // In STL, push() is used enqueue an item
 
    // Loop until the queue is empty (standard
    // level order loop)
    while (!q.empty())
    {
        auto temp = q.front().first;
        auto hd = q.front().second;
        q.pop();   // In STL, pop() is used dequeue an item
 
     
 
        // Put the dequeued tree node to TreeMap
        // having key as horizontal distance. Every
        // time we find a node having same horizontal
        // distance we need to replace the data in
        // the map.
        m[hd] = temp->data;
 
        // If the dequeued node has a left child, add
        // it to the queue with a horizontal distance hd-1.
        if (temp->left != NULL)
        {
          
            q.push({temp->left,hd-1});
        }
 
        // If the dequeued node has a right child, add
        // it to the queue with a horizontal distance
        // hd+1.
        if (temp->right != NULL)
        {
            
            q.push({temp->right,hd+1});
        }
    }
 
    // Traverse the map elements using the iterator.
    vector<int> ans ;
    for (auto i = m.begin(); i != m.end(); ++i)
        ans.push_back(i->second); 
        
    return ans;
    }
