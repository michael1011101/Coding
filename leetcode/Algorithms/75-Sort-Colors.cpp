class Solution {
public:
    void sortColors(vector<int>& nums) {
        int _size = nums.size();
        if(_size <= 1)  return;
        int head, tail, now;
        // set three pointers, head points 0, tail points 2, now points 1
        // if now points 0, swap the head one and now, head++, now++,
        // if now points 2, swap the tail one and now, tail--,
        // if now points 1, now++
        head = 0;
        tail = _size - 1;
        now = 0;
        
        while(now <= tail){
            if(nums[now] == 0)  swap(nums[head], nums[now]), head++, now++;
            else if(nums[now] == 2)  swap(nums[tail], nums[now]), tail--;
            else if(nums[now] == 1)  now++;
        }
    }
};

