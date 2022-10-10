class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> bit(32 , 0);
        int ans = 0;
        int n = nums.size();
        int f1 = 1 ,f2 = 1, i =0 , j= 0;
        while(f1 || f2){
            f1 = 0;
            f2 = 0;
            
            
            while(i < n && check(bit) ) {
                f1 = 1;    
                int num = nums[i];
                for(int d=31; d>=0; d--){
                    if(((num>>d)&1)) bit[d]++;
                }
                
                if(check(bit)){
                    ans = max(ans , i- j + 1);
                }
                i++;
            }
            
            while( j < i && !(check(bit))) {
                f2 = 1;
                int num = nums[j];
                for(int d=31; d>=0; d--){
                    if(((num>>d)&1)) bit[d]--;
                }
                j++;
            }
            
        }
        return ans;
    }
    
    bool check(vector<int> &v){
        for(int i: v){
            if(i >= 2) return 0;
        }
        return 1;
    }
};
