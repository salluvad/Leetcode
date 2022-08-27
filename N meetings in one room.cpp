// Greedy algo
/*https://takeuforward.org/data-structure/n-meetings-in-one-room/
here is one meeting room in a firm. You are given two arrays, start and end each of size N.For an index ‘i’,
start[i] denotes the starting time of the ith meeting while end[i]  will denote the ending time of the ith meeting. 
  Find the maximum number of meetings that can be accommodated if only one meeting can happen in the room at a  particular time. 
    Print the order in which these meetings will be performed.  
    */

//lets define a meeting structure 
struct meeting {
  int start;
  int end;
  ints pos; 
};

// a comaprator to sort the meetings based on end time/pos
class sloution {
 public:
  bool static comparator(struct meeting m1, struct meeting m2){
   if(m1.end<m2.end){
     return true;
  } else if(m1.emd>m2.end){
     return false;
   } else if(m1.pos<m2.pos){
     return true
   }
   return false;
    // print the max meetings 
    void max_meetings(int s[], int e[], int n) {
     //fill the meeting struture array
      
      struct meeting meet[n];
       for (int i = 0; i < n; i++) {
         meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i + 1;
      }
      // sort 
       sort(meet, meet + n, comparator);
      
      // creat a variable t keep track of end time 
      int limit=meet[0].end;
      vector<int> res; // to keep meeting ID's
      
      //schedule the first meeting
      res.push_back(meet[0].pos);
      
      //loop remaing meetings
      for(int i=1;i<n,i++){
        if(meet[i].start>limit){
          res.push_back(meet[i].pos);
         limit = meet[i].end;
        }
      }
       
      //print the res;
          for (int i = 0; i < res.size(); i++) {
         cout << res[i] << " ";
      }
    }
}
