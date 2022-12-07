class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;   //int size = 0  // we don't need a stack , maintain a size variable and inc and dec according to this logic 
        
        for(char &ch : s) {
            if(ch == '[')        st.push(ch);   // size++
            else if(!st.empty()) st.pop();      //size--
        }       
        return (st.size()+1)/2;   // (size+1)/2
    }
}
