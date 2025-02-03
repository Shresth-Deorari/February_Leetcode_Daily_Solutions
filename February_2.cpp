class Solution {
public:
    bool check(vector<int>& nums) {
        if(is_sorted(nums.begin(), nums.end()))return true;
        if(nums[0]<nums.back())return false;
        int i = 0;
        for(i = 0;i<nums.size()-1; i++){
            if(nums[i]>nums[i+1])break;
        }
        i++;
        for(;i<nums.size()-1; i++){
            if(nums[i]>nums[i+1])return false;
        }
        return true;
    }
};