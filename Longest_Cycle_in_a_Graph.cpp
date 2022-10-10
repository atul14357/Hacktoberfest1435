class Solution {
public:
    int cycleLen  ;
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<vector<int>> dist( n ,vector<int> (2,-1));
        cycleLen = -1;
        for(int i=0; i < n ; i++){
            if(dist[i][0] == -1){
                dfs(0 , i , edges , dist, i );
            }
        }
        return cycleLen;
    }
    
    void dfs(int d , int node , vector<int> &edges , vector<vector<int>> &dist ,int  timer ){
        if(node == -1) return;
        if(dist[node][0] != -1){
            if(dist[node][1] == timer) {
                cycleLen = max(cycleLen , d - dist[node][0]);
            }
            return;
        }
        
        dist[node][0] = d;
        dist[node][1] = timer;
        dfs(d +1 , edges[node] , edges , dist , timer);
    }
};
