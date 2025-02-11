class Solution {
    long long nc2(long long n){
        return (n*(n-1))/2;
    }
public:
    long long countBadPairs(vector<int>& nums) {
        if(nums.size()==1)return 0;
        long long count = nc2(nums.size());
        unordered_map<int,int>mp;
        for(int i = 0;i<nums.size(); i++){
            mp[nums[i] - i]++;
        }
        for(auto i : mp){
            if(i.second>1)count -= nc2(i.second);
        }
        return count;
    }
};