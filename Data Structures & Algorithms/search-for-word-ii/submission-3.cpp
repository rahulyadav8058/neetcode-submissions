class Solution {
public:

    struct TrieNode {
        TrieNode* child[26];
        string word;

        TrieNode() {
            for(int i = 0; i < 26; i++)
                child[i] = NULL;

            word = "";
        }
    };

    TrieNode* root = new TrieNode();

    void insert(string word) {
        TrieNode* node = root;

        for(char c : word) {
            int x = c - 'a';

            if(node->child[x] == NULL)
                node->child[x] = new TrieNode();

            node = node->child[x];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board,
             int i, int j,
             TrieNode* node,
             vector<string>& ans) {

        char c = board[i][j];

        if(c == '#') return;

        if(node->child[c - 'a'] == NULL)
            return;

        node = node->child[c - 'a'];

        if(node->word != "") {
            ans.push_back(node->word);
            node->word = "";
        }

        board[i][j] = '#';

        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};

        for(int k = 0; k < 4; k++) {
            int nr = i + dx[k];
            int nc = j + dy[k];

            if(nr >= 0 && nr < board.size() &&
               nc >= 0 && nc < board[0].size()) {

                dfs(board, nr, nc, node, ans);
            }
        }

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        for(string word : words)
            insert(word);

        vector<string> ans;

        int m = board.size();
        int n = board[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dfs(board, i, j, root, ans);
            }
        }

        return ans;
    }
};