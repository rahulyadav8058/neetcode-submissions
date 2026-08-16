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

class Solution {
   public:
    void dfs(TreeNode* node, int &  count, int k, int & ans) {
        if (node == nullptr) return ;
        dfs(node->left, count, k, ans);
        count ++;
        if(count == k){ans = node->val;}
         dfs(node->right, count, k, ans);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int count =0;
        dfs(root, count, k, ans);
        return ans;
    }
};
