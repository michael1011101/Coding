class NumArray {
private:
    vector<int> sum;
public:
    NumArray(vector<int> nums) {
        int _size = nums.size();
        int num = 0;
        sum.push_back(num);
        for(int i=0; i<_size; ++i){
            num += nums[i];
            sum.push_back(num);
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j+1] - sum[i];
    }
};

