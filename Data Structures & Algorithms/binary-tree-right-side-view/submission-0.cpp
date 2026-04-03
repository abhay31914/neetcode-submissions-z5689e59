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

    unordered_set<int> level;
    vector<int> result;
public:

    void view(TreeNode* root, int l){

        if(root == nullptr) return;
        cout<<root->val<<" "<<l<<endl;
        if(level.find(l) == level.end()){
            result.push_back(root->val);
            level.insert(l);
        }

        l = l+1;        
        view(root->right, l);
        view(root->left, l);

    }

    vector<int> rightSideView(TreeNode* root) {

        view(root, 0);

        return result;

        
    }
};
