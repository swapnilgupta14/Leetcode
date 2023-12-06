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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue <pair<TreeNode*, pair<int,int>>> q;
        map <int, map<int, multiset<int>>> nodeMap;
        q.push({root, {0,0}});
        while(!q.empty()){
            // int s = q.size();
            auto p = q.front();
            q.pop();
            int x = p.second.first;
            int y = p.second.second;
            TreeNode *ptr = p.first;
            nodeMap[x][y].insert(ptr->val);
            if(ptr->left != nullptr){
                q.push({ptr->left, {x-1, y+1}});
            }
            if(p.first->right != nullptr){
                q.push({ptr->right, {x+1, y+1}});
            }
        }
        vector<vector<int>> ans;
        for (auto i : nodeMap){
            vector<int>col;
            for (auto m : i.second){
                col.insert(col.end(), m.second.begin() , m.second.end());
            }
            ans.push_back(col);
        }
        return ans;
        
    }
};