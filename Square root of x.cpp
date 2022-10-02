class Solution {
public:
    long long multiply (int num , int k){
        long long ans = 1;
        for(int i = 0;i<k;i++){
            ans= ans*num;
        }
        return ans;
    }
    int mySqrt(int x) {
        //square root lies between 0 and x
        long long low = 0,high =x;
        long long ans=0;
        while(low<=high){
            long long mid = (low+high)/2;
            long long temp = multiply(mid,2);
            if(temp==x){
                return mid;
            } else if (temp<x){
                low= mid+1;
                ans = mid;
            } else{
                high = mid-1;
            }
        }
        return ans;
    }
};
