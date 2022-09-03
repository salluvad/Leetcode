class LRU {
  
 private:
  int cap;
  //DLL
  list<pair<int,int>> DLL;
  unorderd_map<int , list<pair<int,int>>::iterator> hmap;
  
  public:
  LRU(int capacity): cap(capacity);
  
  int get(int key){
    if(hmap.fond(key)!=hmap.end()){
      put(key,hmap[key]->second);
      return hmap[key]-<second;
  }
    return -1;
  }
  
  void put(int key , int value){
    if(hmap.find(key)!=hmap.end()) { // if its already present
      DLL.erase(hmap[key]);
    } else if(DLL.size()>=cap){
        //remove the last node from DLL and clear the entry of hmap
      hmap.erase(DLL.back().first);      
      DLL.pop_back();
    }   
   DLL.insert(DLL.begin(),{key,value});
    hmap[key] = DLL.begin();
  }
  
  
}
