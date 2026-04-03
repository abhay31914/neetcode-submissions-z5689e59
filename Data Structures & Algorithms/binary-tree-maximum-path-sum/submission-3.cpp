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

    int maxPathSum1(TreeNode* root, int& maxSum) {

        if(root == nullptr) return 0;

        int leftSum = maxPathSum1(root->left, maxSum);
        int rightSum = maxPathSum1(root->right, maxSum);

        int max1 = max(root->val+ rightSum, root->val+ leftSum);
        int max2 = max(max1, root->val+ leftSum + rightSum);
        int max3 = max(max2, root->val);
        maxSum = max(maxSum, max3);

        return max(root->val, max1);
    }

    int maxPathSum(TreeNode* root){

        int maxSum = INT_MIN;
        
        maxPathSum1(root, maxSum);
        return maxSum;
    }

};

