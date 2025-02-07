class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>color;
        unordered_map<int,int>balls;
        vector<int>ans;
        for(auto q : queries){
            int index = q[0];
            int colour = q[1];
            if(balls[index]!=0){
                color[balls[index]]--;
                if(color[balls[index]]==0)color.erase(balls[index]);
            }
            balls[index] =colour;
            color[colour]++;
            ans.push_back(color.size());
        }
        return ans;
    }
};