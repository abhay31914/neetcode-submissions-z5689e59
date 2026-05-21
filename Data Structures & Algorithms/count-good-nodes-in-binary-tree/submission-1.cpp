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

    bool isValid(vector<int> path, int val){
        for(auto x: path){
            if(x > val) return false;
        }
        return true;
    }

    void check(TreeNode* root, vector<int>& path, int& count){

        if(!root) return;

        if(isValid(path, root->val)) count++;

        path.push_back(root->val);
        check(root->left, path, count);
        check(root->right, path, count);
        path.pop_back();
    }

    int goodNodes(TreeNode* root) {

        vector<int> path;

        int count = 0;

        check(root, path, count);

        return count;
        
    }
};
