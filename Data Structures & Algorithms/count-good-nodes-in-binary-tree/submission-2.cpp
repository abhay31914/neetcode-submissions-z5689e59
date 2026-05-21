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

    int check(TreeNode* root, int high){

        if(!root) return 0;

        int cur = root->val >= high ? 1: 0;

        high = max(high, root->val);

        return cur + check(root->left, high) + check(root->right, high);        
    }

    int goodNodes(TreeNode* root) {

        return check(root, -150);
        
    }
};
