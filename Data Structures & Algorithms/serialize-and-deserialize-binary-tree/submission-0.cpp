/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
   public:
    string dfs(TreeNode* root) {
        if (root == nullptr) return "N";
        string str = "";
        str = to_string(root->val) + "," + dfs(root->left) +"," + dfs(root->right);
        return str;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) { 
        return dfs(root); }

    TreeNode* dfs(string& data, int& i) {
        if (i >= data.size()) return nullptr;
        string str;
        while (i != data.size() && data[i] != ',') {
            str += data[i];
            i++;
        }
        i++;
        if (str == "N") return nullptr;
        TreeNode* root = new TreeNode(stoi(str));

        // if (root == nullptr) return "N";
        // string str = "";
        root->left = dfs(data, i);
        root->right = dfs(data, i);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i =0;
        return dfs(data, i);
    }
};
