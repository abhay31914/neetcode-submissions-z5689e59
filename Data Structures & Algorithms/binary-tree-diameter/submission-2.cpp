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
    int maxPath(TreeNode* root, int& maxDiam){

        if(!root) return 0;

        int lPath = maxPath(root->left, maxDiam);
        int rPath = maxPath(root->right, maxDiam);

        maxDiam = max(maxDiam, lPath + rPath);

        return 1 + max(lPath, rPath);

    }

    int diameterOfBinaryTree(TreeNode* root) {

        int diam = 0;

        maxPath(root, diam);

        return diam;
        
    }
};
