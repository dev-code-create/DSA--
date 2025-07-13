#include <algorithm> // for std::max
#include <cstddef>   // for NULL

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int leftH = maxDepth(root->left);
        int rightH = maxDepth(root->right);
        return std::max(leftH, rightH) + 1;
    }
};