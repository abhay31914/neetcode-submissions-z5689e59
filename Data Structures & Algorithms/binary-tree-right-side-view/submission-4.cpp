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
unordered_set<int> level;
vector<int> result;

void view(TreeNode* root, int l){

    if(!root) return;

    if(level.find(l) == level.end()){
        result.push_back(root->val);
        level.insert(l);
    }
    view(root->right, l+1);
    view(root->left, l+1);

}
public:
    vector<int> rightSideView(TreeNode* root) {

        view(root, 0);

        return result;
        
    }
};
