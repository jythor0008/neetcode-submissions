class Solution {
    struct Node{
        unordered_map<char,Node*> children;
        bool isEnd;
    };

    struct Trie{
        Node* root;

        Trie(){
            root = new Node();
        }

        void insert(string word){
            Node* cur = root;
            for(char &c : word){
                if(!cur->children.count(c)) cur->children[c] = new Node();
                cur = cur->children[c];
            }

            cur->isEnd = true;
        }

    };

    vector<string> res;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        for(string& word : words){
            t.insert(word);
        }

        string temp = "";
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                Node* cur = t.root;
                dfs(board, i, j, temp, cur);
            }
        }
        return res;
    }

    // this function tries to check if board[i][j] is part of our dictionary word in a trie
    void dfs(vector<vector<char>>& board, int i, int j, string& temp, Node* cur){
        int row = board.size(), col = board[0].size();
        if(i < 0 || j < 0 || i == row || j == col || board[i][j] == '#' || !cur->children.count(board[i][j])) return;

        // at this point we know that we have NOT visited this node, its a valid character that we are interested in

        char originalVal = board[i][j];
        temp += originalVal;
        board[i][j] = '#'; // mark as visited

        cur = cur->children[originalVal];
        // if this is a valid word then we insert it
        if(cur->isEnd){
            res.push_back(temp);
            cur->isEnd = false;
        } 

        // Continue searching for other words
        dfs(board, i+1, j, temp, cur);
        dfs(board, i-1, j, temp, cur);
        dfs(board, i, j+1, temp, cur);
        dfs(board, i, j-1, temp, cur);
        temp.pop_back();

        board[i][j] = originalVal; // undo visited
    }
};
