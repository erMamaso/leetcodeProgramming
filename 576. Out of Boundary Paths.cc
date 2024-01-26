class Solution {
public:
    //int dp
    bool outOfBound(int row, int col, int m, int n){
        if(row < 0 || col < 0 || row >= m || col >= n) return true;
        return false;
    }

    int findPaths2(int m, int n, int maxMove, int row, int col, vector<vector<vector<long long> > >& dp){
        long long mod = 1e9+7;
        if(outOfBound(row, col, m, n)) return 1;
        if(maxMove == 0) return 0;
        if(dp[row][col][maxMove] != -1) return dp[row][col][maxMove];

        long long resUP     = findPaths2(m, n, maxMove-1, row-1, col, dp)%(mod);
        long long resDOWN   = findPaths2(m, n, maxMove-1, row+1, col, dp)%(mod);
        long long resLEFT   = findPaths2(m, n, maxMove-1, row, col-1, dp)%(mod);
        long long resRIGHT  = findPaths2(m, n, maxMove-1, row, col+1, dp)%(mod);

        dp[row][col][maxMove] = (resUP + resDOWN + resLEFT + resRIGHT)%(mod);
        return dp[row][col][maxMove];
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long long> > > dp(m+1, vector<vector<long long> >(n+1, vector<long long>(maxMove+1, -1)));
        return findPaths2(m, n, maxMove, startRow, startColumn, dp);
    }
};