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
    long long maxi;
    int total_sum;
    const int MOD = 1e9+7;

    int sum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return root->val + sum(root->left) + sum(root->right);
    }

    long long solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        long long left=solve(root->left);
        long long right=solve(root->right);

        int curr_sum1 = root->val + left + right;
        int curr_sum2 = total_sum - curr_sum1;
        long long prod = 1LL * curr_sum1 * curr_sum2;
        maxi = max(maxi, prod);

        return curr_sum1; 
    }

    int maxProduct(TreeNode* root) {
        total_sum = sum(root); 

        maxi = 0;
        solve(root);

        return maxi % MOD;

    }
};

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     long long maxi;
//     int total_sum;
//     const int MOD = 1e9+7;

//     int sum(TreeNode* root){
//         if(root==NULL){
//             return 0;
//         }
//         return root->val + sum(root->left) + sum(root->right);
//     }

//     void solve(TreeNode* root){
//         if(root==NULL){
//             return;
//         }
//         solve(root->left);
//         solve(root->right);

//         int curr_sum1 = sum(root);
//         int curr_sum2 = total_sum - curr_sum1;
//         long long prod = 1LL * curr_sum1 * curr_sum2;
//         maxi = max(maxi, prod);
//         return;
//     }

//     int maxProduct(TreeNode* root) {
//         total_sum = sum(root); 

//         maxi = INT_MIN;
//         solve(root);

//         return maxi % MOD;

//     }
// };