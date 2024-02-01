class Solution {
public:
    bool isCorrect(vector<int>& nums, int pos0, int k){
        if(nums[pos0+2]-nums[pos0+1] > k) return false;
        if(nums[pos0+2]-nums[pos0+0] > k) return false;
        if(nums[pos0+1]-nums[pos0+0] > k) return false;
        return true;
    }

    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i<nums.size(); i += 3){
            if(isCorrect(nums, i, k)){
                res.push_back({nums[i], nums[i+1], nums[i+2]});
            }
            else return {};
        }
        return res;
    }
};