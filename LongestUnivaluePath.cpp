class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans=0;
        if (root)
            go(root,ans);
        return ans;
    }
private:
    int go(TreeNode* node, int& ans){
        int L=node->left ? go(node->left,ans) : 0;
        int R=node->right ? go(node->right,ans) : 0;
        L=(node->left && node->left->val == node->val) ? L+1 : 0;
        R=(node->right && node->right->val == node->val) ? R+1 : 0;
        ans=max(ans,L+R);
        return max(L,R);
    }
};
