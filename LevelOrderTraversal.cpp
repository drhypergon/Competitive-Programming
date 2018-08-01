/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {    
        int level = 0;
        queue<pair<TreeNode*, int>> q;
        pair<TreeNode*, int> p (root, level);
        q.push(p);
        
        vector<vector<int>> v;
        vector<int> currlevel;
        
        if (root == NULL)
        {
            return v;
        }
        while (!q.empty())
        {
            pair<TreeNode*, int> temp = q.front();
            cout << temp.first->val;
            cout << "\n";
            cout << temp.second;
            cout << "\n";
            cout << "\n";
            q.pop();
            if (temp.first->left != NULL)
            {
                pair<TreeNode*, int> left (temp.first->left, temp.second+1);
                q.push(left);
            }
            if (temp.first->right != NULL)
            {
                pair<TreeNode*, int> right (temp.first->right, temp.second+1);
                q.push(right);
            }
            
            if (temp.second == level)
            {
                currlevel.push_back(temp.first->val);
            }
            else
            {
                v.push_back(currlevel);
                currlevel.clear();
                currlevel.push_back(temp.first->val);
                level++;
            }  
        }
        v.push_back(currlevel);
        return v;
    }
};
