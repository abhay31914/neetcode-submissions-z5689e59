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
    void getmax(TreeNode* root, int& maxlen, int len){
        if(!root) return;

        maxlen = max(maxlen, len);

        getmax(root->left, maxlen, len+1);
        getmax(root->right, maxlen, len+1);

    }

    int maxDepth(TreeNode* root) {
        int maxlen = 0;
        int cur = 1;
        getmax(root, maxlen, cur);

        return maxlen;
        
    }
};
