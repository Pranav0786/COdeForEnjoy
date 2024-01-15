// LeetCode 110

#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    int height( TreeNode* root )
    {
        // base case 
        if( root == NULL )
            return 0 ;

        int leftH = height( root->left ) ;
        int rightH = height( root->right ) ;

        return 1+ max( leftH , rightH ) ;
        
    }
    bool isBalanced(TreeNode* root) {
        
        if( root == NULL )
            return true ;

        // step 1 
        int leftheight = height( root->left ) ;
        int rightheight = height( root->right ) ;
        int diff = abs( leftheight - rightheight ) ;

        bool ans1 = ( diff <= 1 ) ;

        // recursion
        bool leftans = isBalanced( root->left ) ;
        bool rightans = isBalanced( root->right ) ;

        if( ans1 && leftans && rightans )
            return true ;

        return false ;
    }
};


int main()
{
    return 0;
}