class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        for(auto i : s){
            if((i-'0')<=9 && !st.empty()){
                cout<<i<<endl;
                st.pop();
            }
            else st.push(i);
        }
        string ans;
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};