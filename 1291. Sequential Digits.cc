class Solution {
public:

    int nDig(int n){
        int count = 0;
        while(n != 0){
            n/=10;
            count++;
        }
        return count;
    }

    vector<int> sequentialDigits(int low, int high) {
        int minDig = nDig(low);
        int maxDig = nDig(high);
        //cout << minDig << " " << maxDig << endl;
        string s = "123456789";

        vector<int> res;

        for(int i=minDig; i<=maxDig; ++i){
            for(int j=0; j<9-(i-1); ++j){
                string s2 = s.substr(j, i);
                int aux = stoi(s2);
                if(aux >= low && aux <= high) res.push_back(aux);
            }
        }

        return res;
    }
};