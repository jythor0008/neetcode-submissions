class Solution {
public:
    string longestPalindrome(string s) {
        int idx = -1;
        int len = 0;

        for(int i=0; i<s.size(); i++){
            // odd case
            int l = i, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(r-l+1 > len){
                    len = r - l + 1;
                    idx = l; 
                }
                l--; r++;
            }

            // even case
            l = i, r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(r-l+1 > len){
                    len = r - l + 1;
                    idx = l; 
                }
                l--; r++;
            }
        }

        return idx == -1 ? "" : s.substr(idx, len);
        
    }
};
