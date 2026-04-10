class Solution {
public:
    bool isAnagram(string s, string t) {
        // If not same length, cannot be anagrams
        if(s.size() != t.size()) return false;

        vector<int> count(26, 0);
        for(char& c : s){
            count[c - 'a']++;
        }

        for(char& c : t){
            count[c - 'a']--;
            if(count[c - 'a'] < 0) return false;
        }

        return true;
    }
};
