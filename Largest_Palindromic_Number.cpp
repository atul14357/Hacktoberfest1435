class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> freq(10, 0);
        for(int i=0; i< num.size(); i++){
            freq[ num[i] - '0']++;
        }
        
        
        string left = "", right = "";
        for(int i=9; i>=0; i--){
            if(freq[i] > 1){
                string tem (freq[i]/2 , (i + '0') );
                left+= tem;
                right += tem;
                freq[i]%=2;
            }
        }
        string middle = "";
        for(int i=9; i>= 0; i--){
            if(freq[i] > 0){
                middle.push_back( (i+ '0') );
                break;
            } 
        }
        int i = 0;
        while(i < left.size() && left[i] == '0'){
            i++;
        }
        left= left.substr(i);
        right= right.substr(i);
        
        
        reverse(right.begin(), right.end());
        string ans = left + middle + right;
        if(ans.size() == 0) return "0";
        return ans;
    }
};
