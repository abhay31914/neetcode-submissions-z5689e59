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

    int maxSum = INT_MIN;

    int maxPathSum1(TreeNode* root) {

        if(root == nullptr) return 0;

        int leftSum = maxPathSum1(root->left);
        int rightSum = maxPathSum1(root->right);

        int max1 = max(root->val+ rightSum, root->val+ leftSum);
        int max2 = max(max1, root->val+ leftSum + rightSum);
        int max3 = max(max2, root->val);
        maxSum = max(maxSum, max3);

        return max(root->val, max1);
    }

    int maxPathSum(TreeNode* root){        
        maxPathSum1(root);
        return maxSum;
    }

};

