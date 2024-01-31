class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //Slow Solution O(n^2)
        /*
        vector<int> res(temperatures.size(), 0);
        for(int i=0; i<temperatures.size(); ++i){
            int currentTemp = temperatures[i];
            bool found = false;
            int count = 1;
            for(int j=i+1; j<temperatures.size() and !found; ++j){
                int futureTemp = temperatures[j];
                if(futureTemp > currentTemp) found = true;
                else count += 1;
            }
            if(found) res[i] = count;
        }
        return res;
        */
        vector<int> res(temperatures.size(), 0);
        stack<int> tempValues;
        stack<int> tempIndices;
        for(int i = 0; i<temperatures.size(); ++i){
            while(!tempValues.empty()){
                if(temperatures[i] > tempValues.top()){
                    res[tempIndices.top()] = i - tempIndices.top();
                    tempValues.pop(); tempIndices.pop();
                }
                else break;
            }
            tempValues.push(temperatures[i]); tempIndices.push(i);

        }
        return res;
    }
};