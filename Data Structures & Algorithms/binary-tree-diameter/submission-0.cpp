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
    int func(TreeNode* root,int & maxi ){
        if (root==nullptr)return 0;
        int left = func(root->left,maxi);
        int right = func(root->right,maxi);
        if(maxi < right + left){
            maxi = left + right;
        }
        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;
        int maxi =0;
        func(root,maxi);
        return maxi;
    }
};