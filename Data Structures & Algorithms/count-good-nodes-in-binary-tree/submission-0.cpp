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

    bool checkPath(vector<int>& arr, int x){
        for(int ele: arr){
            if(ele > x) return false;
        }
        return true;
    }

    void checkNode(TreeNode* root, vector<int>& arr, int& count){
        if(!root) return;

        if(checkPath(arr, root->val)) count++;
        arr.push_back(root->val);

        checkNode(root->left, arr, count);
        checkNode(root->right, arr, count);

        arr.pop_back();
    }

    int goodNodes(TreeNode* root) {

        vector<int> arr;
        int count = 0;

        checkNode(root, arr, count);

        return count;
        
    }
};
