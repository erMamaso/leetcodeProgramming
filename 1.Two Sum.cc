class Solution {
public:
    /*
    //Slow Solution
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        for(int i=0; i<nums.size(); ++i){
            for(int j=i+1; j<nums.size(); ++j){
                if(nums[i]+nums[j] == target){
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> hmap;

        for(int i=0; i<nums.size(); ++i){
            if(hmap.count(target-nums[i])){
                res.push_back(hmap[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            hmap[nums[i]] = i;
        }
        return res;
    }
};