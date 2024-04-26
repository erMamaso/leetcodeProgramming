class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        //Creamos memo, una matrix del mismo tamaño que acumulará siempre el minimo
        //acumulado en grid[i][j]
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size()));
        for(int i = 0; i<grid.size(); ++i) for(int j = 0; j<grid[0].size(); ++j){
            //El minimo en la primera fila es la primera fila.
            if(i == 0) memo[i][j] = grid[i][j];
            else{
                //Un minimo, siempre sera el primero a poder escoger. Siempre con k != j
                int minimum;
                if(j != 0) minimum = memo[i-1][0];
                else minimum = memo[i-1][1];
                memo[i][j] = grid[i][j] + minimum;

                //Iteramos para ver el minimo ya acumulado en memo[i-1] con k != j
                for(int k = 0; k<grid[i-1].size(); ++k){
                    if(k != j){
                        if(memo[i-1][k]+grid[i][j] < memo[i][j]) memo[i][j] = memo[i-1][k] + grid[i][j];
                    }
                }
            }
        }
        
        //Buscamos el minimo en la ultima fila de memo.
        int res = memo[memo.size()-1][0];
        for(int j = 0; j<memo[memo.size()-1].size(); ++j){
            if(memo[memo.size()-1][j] < res) res = memo[memo.size()-1][j];
        }
        return res;
    }
};
