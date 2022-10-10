
/*
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
*/


class Solution {
public:
    int dp[2001][2001];
    int minCut(string s) {
        
        memset(dp, -1, sizeof dp);
        return fun(s, 0, s.size() - 1);
    }
    
    int fun(string &s, int i, int j) {
        if(i == j) return 0;
        if(isPalin(s, i, j)) return dp[i][j] = 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int mn = INT_MAX;
        for(int k = i; k < j; k++) {
            
            if(isPalin(s, i, k)) {
                int y = fun(s, k + 1, j);
                mn = min(mn, y + 1);
            }
        }
        return dp[i][j] = mn;
    }
    
    int isPalin(string &s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) 
                return 0;
            i++, j--;
        }
        return 1;
    }
};
