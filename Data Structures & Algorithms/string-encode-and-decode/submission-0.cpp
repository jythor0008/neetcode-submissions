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
        string count = "";
        while( i < size){
            char cur = s[i];
            if(cur == '#'){
                // Start decoding the number of characters
                int num = stoi(count);
                string word = "";
                i++;
                while(num > 0){
                    word += s[i++];
                    num--;
                }
                res.push_back(word);
                count = "";
            } else {
                // accumulate the digits
                count += cur;
                i++;
            }
        }
        return res;
    }
};
