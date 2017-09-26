class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // using bfs to achieve subsets
        vector<vector<int> > ans;
        int _size = nums.size();
        ans.push_back(vector<int>());
        for(int i=0; i<_size; ++i){
            for(int j=0; j<(1<<i); ++j){
                vector<int> tmp = ans[j];
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
        }
        
        return ans;
    }
};

