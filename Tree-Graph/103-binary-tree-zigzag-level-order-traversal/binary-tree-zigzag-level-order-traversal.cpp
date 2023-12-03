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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr){
            return result;
        }
        queue <TreeNode*> q;
        q.push(root);
        bool flag = true;
        while (!q.empty()){
            int s = q.size();
            vector<int> level(s);
            for (int i=0 ; i<s ; i++){
                TreeNode* ptr = q.front();
                q.pop();

                int index = flag ? i : s-1-i;
                level[index] = ptr->val;
                if(ptr->left != nullptr){
                    q.push(ptr->left);
                }
                if(ptr->right != nullptr){
                    q.push(ptr->right);
                }
            }
            flag = !flag;
            result.push_back(level);
        }
        return result;
    }
};