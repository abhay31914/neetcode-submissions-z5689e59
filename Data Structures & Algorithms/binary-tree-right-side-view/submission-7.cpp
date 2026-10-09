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

    void view(TreeNode* root, vector<int>& result, int& level, int depth = 0){

        if(!root) return;

        if(depth == level){
            result.push_back(root->val);
            level +=1;
        }
        view(root->right, result, level, depth+1);
        view(root->left, result, level, depth+1);

    }

    vector<int> rightSideView(TreeNode* root) {

        vector<int> result;
        int level = 0;

        view(root, result, level);

        return result;

        
        
    }
};
