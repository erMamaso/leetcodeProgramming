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
    int max(int a, int b){
        if(a >= b) return a;
        return b;
    }

    int heightTree(TreeNode* node){
        if(node == NULL) return 0;
        int hLeftNode  = heightTree(node->left);
        int hRightNode = heightTree(node->right);
        return 1+max(hLeftNode, hRightNode);
    }

    void solver(TreeNode* node, int level, vector<vector<int> >& map){
        if(node == NULL) return;
        map[level].push_back(node->val);
        solver(node->left,  level+1, map);
        solver(node->right, level+1, map);
    }

    bool isEvenOddTree(TreeNode* root) {
        int height = heightTree(root);
        vector<vector<int> > map(height);
        
        solver(root, 0, map);

        int last_val;
        for(int level = 0; level<map.size(); ++level){
            if(level%2 == 0){
                if(map[level][0]%2 == 0) return false;
                last_val = map[level][0];
                for(int j = 1; j<map[level].size(); ++j){
                    if(map[level][j]%2 == 0) return false;
                    if(map[level][j] <= last_val) return false;
                    last_val = map[level][j];
                }
            }
            else{
                if(map[level][0]%2 != 0) return false;
                last_val = map[level][0];
                for(int j = 1; j<map[level].size(); ++j){
                    if(map[level][j]%2 != 0) return false;
                    if(map[level][j] >= last_val) return false;
                    last_val = map[level][j];
                }
            }
        }
        return true;
    }
};