class Solution {
    int maxLength=0;
    void solve(TreeNode *root, int dir, int currLength){
        if (!root) return;
        maxLength=max(maxLength,currLength);
        solve(root->left,0,dir?currLength+1:1); //left is 0 direction, so if u come from  1 dir, then add 1 to currLength else start a new path
        solve(root->right, 1, dir? 1: currLength+1);
    }
public:
    int longestZigZag(TreeNode* root) {
        solve(root, 0, 0);
        solve(root, 1, 0);
        return maxLength;
    }
};

//T(n) = O(n)
//S(n) = O(1)
