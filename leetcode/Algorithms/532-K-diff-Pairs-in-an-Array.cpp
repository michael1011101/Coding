class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int _size = nums.size();
        if(_size <= 1) return 0;
        int slow, fast;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(slow = 0, fast = 1; slow<_size && fast<_size; slow++){
            while(fast<=slow || (fast<_size && nums[fast] < k+nums[slow])) fast++;
            if(fast >= _size) break;
            if(fast > slow && nums[fast]-k == nums[slow]) ans++;
            while(slow<_size && nums[slow] == nums[slow+1]) slow++;
        }
        return ans;
    }
};

