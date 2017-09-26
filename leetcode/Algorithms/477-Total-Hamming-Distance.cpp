class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> bitOneNum(30, 0);
        int _size = nums.size();
        int ans;
        int tmp;

        for(int i=0, j=0; i<_size; ++i, j=0){
            tmp = nums[i];
            while(tmp){
                if(tmp&1)   bitOneNum[j]++;
                tmp >>= 1;
                j++;
            }
        }

        ans = 0;
        for(int i=0; i<30; ++i){
            ans += bitOneNum[i]*(_size - bitOneNum[i]);
        }

        return ans;
    }
};

