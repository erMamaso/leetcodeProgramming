class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        std::unordered_map<int, int> hm;
        std::unordered_map<int, int>::const_iterator it;
        for(int i=0; i<nums.size(); ++i) ++hm[nums[i]];
        int maximum = 0;
        for(auto it=hm.begin(); it != hm.end(); ++it){
            if(it->second > maximum) maximum = it->second;
        }
        int count = 0;
        for(auto it=hm.begin(); it != hm.end(); ++it){
            if(it->second == maximum) ++count;
        }
        
        return count*maximum;
    }
};