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

    void getSmall(TreeNode* root, int k, int& count, int& result){

        if(!root || count >= k) return;

        getSmall(root->left, k, count, result);

        count += 1;
        if(k == count){
            result = root->val;
            return;
        }
        getSmall(root->right, k, count, result);
    }

    int kthSmallest(TreeNode* root, int k) {

        int result = -1;
        int count = 0;

        getSmall(root, k, count, result);

        return result;
        
    }
};
