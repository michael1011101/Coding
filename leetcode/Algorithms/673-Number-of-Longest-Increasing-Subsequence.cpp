//dp[i]表示以nums[i]结尾的最长上升子序列的长度
//cnt[i]表示以nums[i]结尾的LIS的个数
//最后将dp[i]  ==  maxlen时 cnt[i]的值求和

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int _size = nums.size();
        if(_size <= 1) return _size;
        
        vector<int> dp(_size, 1), cnt(_size, 1);	
        int maxlen = 0;
        int ans = 0;
        for(int i=1; i<_size; ++i){
            for(int j=i-1; j>=0; --j){
                if(nums[i] > nums[j]){
                    if(dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                        cnt[i] = cnt[j];
                    }
                    else if(dp[j]+1 == dp[i]){
                        cnt[i] += cnt[j];
                    }
                }
            }
            maxlen = max(maxlen, dp[i]);
        }
        
        for(int i=0; i<_size; ++i){
            if(dp[i] == maxlen) ans += cnt[i];
        }
        return ans;
    }
};

