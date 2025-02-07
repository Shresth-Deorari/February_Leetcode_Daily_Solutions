class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        int first = -1, second = -1;
        for(int i = 0;i<s1.size(); i++){
            if(s1[i] != s2[i]){
                count++;
                if(count>2)return false;
                if(first==-1)first = i;
                else second = i;
            }
        }
        if(count==0)return true;
        if(count == 1)return false;
        swap(s1[first], s1[second]);
        return s1==s2;
    }
};