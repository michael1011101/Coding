class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        
        int left = 0;
        int right = tmp.size()-1;
        while(left <= right && nums[left] == tmp[left]) left++;
        while(left <= right && nums[right] == tmp[right]) right--;
        
        return right - left + 1;
    }
};

