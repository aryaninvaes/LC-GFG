// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     bool getPath(TreeNode* root, vector<TreeNode*>& path, TreeNode* target){
//         if(root==NULL){
//             return false;
//         }
        
//         path.push_back(root);
//         if(root == target){
//             return true;
//         }
//         if(getPath(root->left, path, target) || getPath(root->right, path, target)){
//             return true;
//         }
//         path.pop_back();
//         return false;
//     }

//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<TreeNode*> leftPath, rightPath;
//         getPath(root, leftPath, p);
//         getPath(root, rightPath, q);

//         TreeNode* ans = NULL;
//         int i=0;
         
//         while(i<leftPath.size() && i<rightPath.size() && leftPath[i]==rightPath[i]){
//            ans=leftPath[i];
//            i++;
//         }
//         return ans;

//     }
// };
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL) return NULL;
        if(root==p || root==q){
            return root;
        }

        TreeNode* leftAns= lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns= lowestCommonAncestor(root->right,p,q);

        // if(leftAns==NULL && rightAns== NULL) return NULL;
        if(leftAns!=NULL && rightAns!=NULL){
            return root;
        }
        if(leftAns!=NULL){
            return leftAns;
        }else{
            return rightAns;
        }



    }
};