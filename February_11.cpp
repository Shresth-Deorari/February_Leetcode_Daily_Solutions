class Solution {
    vector<int> calculateLps(string &part){
        vector<int>lps(part.size(), 0);
        int prefix = 0;
        for(int i = 1; i< part.size();){
            if(part[i] == part[prefix]){
                lps[i] = ++prefix;
                i++;
            }
            else if(prefix!=0){
                prefix = lps[prefix-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
        return lps;
    }
public:
    string removeOccurrences(string s, string part) {
        vector<int>lps = calculateLps(part);
        stack<char>st;

        vector<int>patternIndexes(s.length()+1, 0);

        for(int i = 0, ind = 0;i<s.length(); i++){
            char curr = s[i];
            st.push(curr);
            if(s[i] == part[ind]){
                patternIndexes[st.size()] = ++ind;
                if(ind == part.size()){
                    int temp = part.size();
                    while(temp--)st.pop();
                }
                ind = st.empty()?0:patternIndexes[st.size()];
            }
            else{
                if(ind !=0 ){
                    i--;
                    ind = lps[ind-1];
                    st.pop();
                }
                else{
                    patternIndexes[st.size()] = 0;
                }
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};