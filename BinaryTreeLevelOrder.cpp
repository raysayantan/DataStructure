/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],

return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q1, q2;
        vector<vector<int>> res;
        vector<int> data;
        bool flip = false;
        if(root == NULL) return res;
        q1.push(root);
        
        while(!q1.empty()|| !q2.empty()){
            TreeNode* t = NULL;
            while(!q1.empty()){
                t = q1.front();
                q1.pop();
                data.push_back(t->val);
                if(t->left) q2.push(t->left);
                if(t->right) q2.push(t->right);
            }
            if(data.size() > 0){
                res.push_back(data);
                data.clear();
            }
            
            while(!q2.empty()){
                t = q2.front();
                q2.pop();
                data.push_back(t->val);
                if(t->left) q1.push(t->left);
                if(t->right) q1.push(t->right);
            }
            
            if(data.size() > 0){
                res.push_back(data);
                data.clear();
            }
        }
        
        return res;
    }
};
