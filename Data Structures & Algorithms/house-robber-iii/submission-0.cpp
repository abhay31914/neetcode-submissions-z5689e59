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

    pair<int, int> getVal(TreeNode* root){

        if(root == nullptr){
            return {0, 0};
        }

        auto leftVal = getVal(root->left);
        auto rightVal = getVal(root->right);

        int WtNode = root->val + leftVal.second + rightVal.second;

        int WoNode= max(leftVal.first, leftVal.second) + max(rightVal.first, rightVal.second);

        return {WtNode, WoNode};
    }

    int rob(TreeNode* root) {

        pair<int, int> result = getVal(root);

        return max(result.first, result.second);
       
    }
};