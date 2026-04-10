class Solution {
public:
    bool isAnagram(string s, string t) {
        // If not same length, cannot be anagrams
        if(s.size() != t.size()) return false;

        unordered_map<char, int> hm;
        for(char& c : s){
            hm[c]++;
        }

        for(char& c : t){
            if(!hm.count(c)) return false;
            hm[c]--;
            if(hm[c] < 0) return false;
        }

        return true;
    }
};
