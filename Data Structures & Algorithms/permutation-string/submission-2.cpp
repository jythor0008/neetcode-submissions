class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> c1(26,0), c2(26,0);
        int size = s1.size();
        for(int i = 0; i < size; i++){
            c1[s1[i] - 'a']++;
        }

        int l = 0;
        for(int r=0; r<s2.size(); r++){
            c2[s2[r] - 'a']++;
            if(r-l+1 == size){
                // check if its a permutation
                if(c1 == c2) return true;

                // shift left
                c2[s2[l] - 'a']--;
                l++;
            }
        }

        return false;

    }
};
