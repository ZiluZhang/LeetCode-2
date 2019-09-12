class NumArray {
public:
    vector<int> sum = {0};
    NumArray(vector<int>& nums) {
        int cur = 0;
        for (int n:nums) {
            cur += n;
            sum.push_back(cur);
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j+1] - sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */