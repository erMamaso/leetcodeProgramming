class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        int nminus1 = 2;
        int nminus2 = 1;
        int aux;
        for(int i=3; i<=n; ++i){
            aux = nminus1 + nminus2;
            nminus2 = nminus1;
            nminus1 = aux;
        }
        return aux;
    }
};