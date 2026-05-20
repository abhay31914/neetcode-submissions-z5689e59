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
private:
vector<int> result;

void view(TreeNode* root, int level, int& count){

    if(!root) return;

    if(level >= count){
        result.push_back(root->val);
        count += 1;
    }
    view(root->right, level+1, count);
    view(root->left, level+1, count);

}
public:
    vector<int> rightSideView(TreeNode* root) {

        int count = 0;
        view(root, 0, count);

        return result;
        
    }
};
