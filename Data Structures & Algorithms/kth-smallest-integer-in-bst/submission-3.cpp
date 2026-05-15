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
    int kthSmallest(TreeNode* root, int k) {

        int count = 0;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* temp = root->left;

        while(!s.empty() || temp ){

            while(temp){
                s.push(temp);
                temp = temp->left;
            }

            TreeNode* top = s.top();
            s.pop();
            count++;

            if(count == k) return top->val;

            temp = top->right;
        }
        return -1;
        
    }
};
