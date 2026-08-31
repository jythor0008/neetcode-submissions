class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for(int i=0; i<s.size(); i++){
            res += countPalin(i, i, s); // count all odd palindromes
            res += countPalin(i, i+1, s); // count all even palindromes
        }

        return res;
    }

    int countPalin(int l, int r, string& s){
        int cnt = 0;
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            cnt++;
            l--; r++;
        }
        return cnt;
    }
};
