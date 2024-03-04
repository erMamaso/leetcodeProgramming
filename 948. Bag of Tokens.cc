class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int iLeft  = 0;
        int iRight = tokens.size()-1;
        int maxCount = 0;
        int count = 0;
        sort(tokens.begin(), tokens.end());
        //cout << iLeft << " " << iRight << endl;
        while(iLeft <= iRight){
            if(tokens[iLeft] <= power){
                power -= tokens[iLeft];
                ++iLeft;
                ++count;
                if(count >= maxCount) maxCount = count;
                
            }
            else if(count > 0){
                power += tokens[iRight];
                --iRight;
                --count;
            }
            else break;
        }
        return maxCount;
    }
};