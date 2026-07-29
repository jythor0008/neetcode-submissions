class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> c1, c2;
        int size = s1.size();
        for(int i = 0; i < size; i++){
            c1[s1[i]]++;
        }

        int l = 0;
        for(int r=0; r<s2.size(); r++){
            c2[s2[r]]++;
            if(r-l+1 == size){
                // check if its a permutation
                int matched = 0;
                for(auto& [k,v ] : c1){
                    if(c2[k] == v) matched++;
                }
                if(matched == c1.size()) return true;

                // shift left
                c2[s2[l]]--;
                l++;
            }
        }

        return false;

    }
};
