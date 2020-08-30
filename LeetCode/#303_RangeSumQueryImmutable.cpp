class NumArray {
public:
    NumArray(vector<int>& nums) {
        if(nums.size() > 0){
            prefixArr.push_back(nums[0]);
            for(int i = 1; i < nums.size(); i++){
                prefixArr.push_back(nums[i] + prefixArr[i-1]); 
            }
        }
    }
    
    int sumRange(int i, int j) {
        if (i >= 0 && j < prefixArr.size()){
            if (i > 0){
                return prefixArr[j] - prefixArr[i - 1];    
            }
            else{
                return prefixArr[j];   
            }
        }
        return -1;
    }
private:
    vector<int> prefixArr;
};


