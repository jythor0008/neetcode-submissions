class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int res = 0, l = 0;
        int maj = 0;
        for(int r = 0; r < s.size(); r++){
            count[s[r] - 'A']++;
            maj = max(maj, count[s[r]-'A']);
            while(r-l+1 - maj > k){
                count[s[l]-'A']--;
                l++;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
