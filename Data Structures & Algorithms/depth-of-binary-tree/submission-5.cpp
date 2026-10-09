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
    int maxDepth(TreeNode* root) {

       int count = 0;

       queue<TreeNode*> q;

       if(root) q.push(root);

       while(!q.empty()){
        int n = q.size();

        for(int i = 0; i< n; i++){
            TreeNode* ft = q.front();
            q.pop();

            if(ft->left) q.push(ft->left);
            if(ft->right) q.push(ft->right);
        }
        count++;
       }

    return count;       
    }
};
