class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        if(nums.size()<=1)
            return false;

        // Method 1
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])
                return true;
        }

        return false;


    }
};