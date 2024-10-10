class NumArray {
public:
    vector<int> nums;  

    NumArray(vector<int>& nums) {
        this->nums = nums;  
    }
    
    int sumRange(int l, int r) {
        int sum = 0;
        while( l <= r){
            sum += nums[l];
            l++;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */