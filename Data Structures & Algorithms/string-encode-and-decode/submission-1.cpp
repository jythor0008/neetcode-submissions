class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(string &str : strs){
            int size = str.size();
            res += to_string(size) + "#" + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        int size = s.size();
        while( i < size){
            string count = "";
            while(s[i] != '#'){
                count += s[i++];
            }
            int num = stoi(count);
            i++; // Get rid of the #
            string word = "";
            while(num > 0){
                word += s[i++];
                num--;
            }
            res.push_back(word);
        }
        return res;
    }
};
