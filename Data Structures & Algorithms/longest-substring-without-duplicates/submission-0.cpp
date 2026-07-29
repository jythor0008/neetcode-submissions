class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int l = 0;
        unordered_set<char> counter;
        for(int r = 0; r<s.size(); r++){
            while(counter.count(s[r])){
                counter.erase(s[l++]);
            }
            res = max(res, r-l+1);
            counter.insert(s[r]);
        }
        return res;
    }
};
