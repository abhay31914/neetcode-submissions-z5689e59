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

    void findEle(TreeNode* root, int k, int& count, int& result){

        if(!root || count > k) return;

        findEle(root->left, k, count, result);

        count += 1;
        if(count == k) result = root->val;

        findEle(root->right, k, count, result);

    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int result = -1;

        findEle(root, k, count, result);

        return result;
        
    }
};
