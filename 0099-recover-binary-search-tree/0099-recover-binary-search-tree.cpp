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
void solve(TreeNode* root, TreeNode*& prev, TreeNode*& fv, TreeNode*& sv) {
    if (!root)
        return;
    solve(root->left, prev, fv, sv);
    if (prev && prev->val>root->val){
        if(!fv)
            fv=prev;
        sv=root;
    }  
    prev = root;
    solve(root->right, prev, fv,sv);
}
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* prev = nullptr;
        TreeNode* fv = nullptr;
        TreeNode* sv = nullptr;
        solve(root, prev, fv, sv);
        swap(fv->val,sv->val);
    }
};