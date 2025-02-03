class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int longest = 1;
        int inc = 1, dec = 1;
        for(int i = 0;i<nums.size()-1; i++){
            if(nums[i]<nums[i+1])inc++;
            else inc = 1;
            if(nums[i]>nums[i+1])dec++;
            else dec = 1;
            longest = max({longest,inc,dec});
        }
        return longest;
    }
};