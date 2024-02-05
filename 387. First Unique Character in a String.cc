class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> hm;
        for(int i = 0; i<s.size(); ++i) hm[s[i]]++;
        for(int i = 0; i<s.size(); ++i) if(hm[s[i]] == 1) return i;
        return -1;

    }
};