struct Node{
  Node* links[26];
  bool is_end = false;
  //methods
  bool containskey(char ch){
      if(links[ch-'a']!=NULL){
          return true;
      } else return false;
  }
 
  void put(char ch,Node* node){
      links[ch-'a']=node;
  }
    
  Node* get(char ch){
      return links[ch-'a'];
  }  

  void setEnd(){
      is_end = true;
  }

  bool isEnd(){
      return is_end;
  }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i<word.size();i++){
            if(!node->containskey(word[i])){
                node->put(word[i],new Node());
            }
            node = node->get(word[i]);   // move to next node
        }
        //set end of word
        node->setEnd();
    }
    
    bool search(string word) {
        Node * node = root;
        for(int i = 0 ;i<word.size();i++){
            if(!node->containskey(word[i])){
                return false;
            }
            node = node->get(word[i])  ;      
            }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0 ;i<prefix.size();i++){
            if(!node->containskey(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
