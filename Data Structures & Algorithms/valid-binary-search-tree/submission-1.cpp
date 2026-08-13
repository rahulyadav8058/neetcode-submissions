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
    bool func(TreeNode* node, int maxi ,int mini){
        if(node==nullptr)return true;
        if(node->val >= maxi || node->val<= mini)return false;

        if(func(node->left,node->val,mini)==false)return false;
        if(func(node->right,maxi,node->val)==false)return false;

        return true;
    }
    bool isValidBST(TreeNode* root) {
        return func(root,INT_MAX,INT_MIN);
    }
};
