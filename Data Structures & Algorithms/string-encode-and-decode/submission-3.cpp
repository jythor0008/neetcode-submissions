class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(const string& str : strs){
            res += to_string(str.size()) + "#" + str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i =0;
        while( i < s.size()){
            // Read number of letter until #
            string len_string;
            while(i < s.size() && s[i] != '#'){
                len_string += s[i]; i++;
            }

            // This is the '#' so we add 1
            i++;

            int len = stoi(len_string);
            // Now we reach "length" number of chars
            string word = "";
            for(int j = 0; j < len; j++){
                word += s[i+j];
            }

            res.push_back(word);

            i += len;
        }
        return res;
    }
};
