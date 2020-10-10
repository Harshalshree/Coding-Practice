class Solution {
public:
    void fun(TreeNode* root, int curr, int &ans)
    {
        if(!root->left && !root->right)
            ans += curr*2 + root->val;
        curr = curr*2 + root->val;
        if(root->left){
            fun(root->left,curr, ans);
        }
        if(root->right){
            fun(root->right, curr, ans);
        }
    }
    
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans = 0;
        int curr = 0;
        fun(root,curr, ans);
        return ans;
    }
};
