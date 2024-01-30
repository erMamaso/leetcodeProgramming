class Solution {
public:

    void addPartialSolToSols(vector<vector<string>>& sols, vector<int>& partialSol){
        int n = partialSol.size();
        vector<string> v;
        
        for(int i=0; i<n; ++i){
            int posQueen = partialSol[i];
            std::string s(n, '.');
            s[partialSol[i]] = 'Q';
            v.push_back(s);
        }
        sols.push_back(v);
    }

    bool interfere(vector<int>& queenArray){
        int newQueenRow = queenArray.size()-1;
        for(int i=0; i<newQueenRow; ++i){
            //same col?
            if(queenArray[i] == queenArray[newQueenRow]) return true;
            //in diag?
            if((queenArray[newQueenRow]+(newQueenRow-i) == queenArray[i]) || (queenArray[newQueenRow]-(newQueenRow-i) == queenArray[i])) return true;
        }
        return false;
    }

    void solver(int n, int row, vector<vector<string>>& sols, vector<int>& partialSol){
        if(row == n){
            addPartialSolToSols(sols, partialSol);
        }
        for(int i = 0; i<n; ++i){
            partialSol.push_back(i);
            if(interfere(partialSol)) partialSol.pop_back();
            else{
                solver(n, row+1, sols, partialSol);
                partialSol.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        //OBVIOUS BASE CASES
        if(n == 1){
            return {{"Q"}};
        }
        if(n == 2 || n == 3){
            return {};
        }
        vector<vector<string>> sols;
        vector<int> partialSol;
        solver(n, 0, sols, partialSol);
        return sols;
        //return {{}};
    }
};