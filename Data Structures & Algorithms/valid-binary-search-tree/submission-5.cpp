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

    bool isValidBST(TreeNode* root) {

        stack<TreeNode*> st;
        int min = INT_MIN;
        TreeNode* temp = root;

        while(temp || !st.empty()){

            while(temp){
                st.push(temp);
                temp = temp->left;
            }

            TreeNode* top = st.top();
            st.pop();

            if(top->val <= min) return false;
            min = top->val;

            temp = top->right;
        }

        return true;
        
    }
};
