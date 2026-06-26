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
    bool isCompleteTree(TreeNode* root) {
        
        if(root==NULL) return true;


        queue<TreeNode*> q;
        q.push(root);
        bool past=false;

        while(!q.empty()){
            TreeNode* node= q.front();
            q.pop();
            
            if(node==NULL){
                past=true;
            }else{
                if(past==true){
                    return false;
                }
                q.push(node->left);
                q.push(node->right);
            }

        }
        return true;









    }
};










/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// class Solution {
// public:
//     bool isCompleteTree(TreeNode* root) {
//         if (root == NULL) {
//             return true;
//         }
//         vector<vector<int>> checkAns;

//         queue<TreeNode*> q;
//         q.push(root);

//         int i = 0;
//         while (!q.empty()) {
//             int N = q.size();
//             vector<int> temp;
//             while (N--) {
//                 TreeNode* node = q.front();
//                 q.pop();

//                 temp.push_back(node->val);

//                 if (node->left) {
//                     q.push(node->left);
//                 }
//                 if (node->right) {
//                     q.push(node->right);
//                 }
//             }
//             checkAns.push_back(temp);
//             if (temp.size() != (2 ^ i)) {
//                 return false;
//             }
//             i++;
//         }
//         return true;
//     }
// };