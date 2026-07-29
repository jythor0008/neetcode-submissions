class Solution {
public:
    string minWindow(string s, string t) {
        // will need a set to check membership
        // if we encounter a char not in t then we can move the window until after the current char
        // if is in char then we need to check if it can complete the string
        unordered_map<char, int> count;
        for(char& c : t){
            count[c]++;
        }

        int l = 0;
        int matched = 0;
        string res;
        int shortest = INT_MAX;
        unordered_map<char, int> current;
        for(int r = 0; r<s.size(); r++){
            char ch = s[r];
            current[ch]++;
            if(count.count(ch) && current[ch] == count[ch])
                matched++;
             
            while(matched == count.size()) {
                if(r-l+1 < shortest){
                    shortest = r-l+1;
                    res = s.substr(l, r-l+1);
                }

                // shift left and see if we can shrink it
                current[s[l]]--;
                if(count.count(s[l]) && current[s[l]] < count[s[l]]) matched--;
                l++;
            }
        }

        return res;

    }
};
