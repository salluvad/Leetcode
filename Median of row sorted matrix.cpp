https://takeuforward.org/data-structure/median-of-row-wise-sorted-matrix/

int less_or_equal(vector<int>&res , int x)
  {
      int l=0;
      int h =res.size()-1;
      while(l<=h)
      {
          int mid = (l+h)/2;
          
          if(res[mid]<=x)
          {
              l=mid+1;
          }
          else
          {
              h =mid-1;
          }
          
          
      }
      
      return l;
  }
    int matrixMedian(vector<vector<int>>& matrix) {
        int l=0,h=1e6+1;
        int r=matrix.size();
        int c=matrix[0].size();
        while(l<=h)
    {
           int mid =(l+h)/2;
           
           int cnt =0;
           
           for( int i=0;i<r;i++)
           {
               cnt += less_or_equal(matrix[i],mid);
           }
           if((cnt<=r*c/2))
           {
               l=mid+1;
           }
           else
           {
               h =mid-1;
           }
       }
       return l;
    }
}
