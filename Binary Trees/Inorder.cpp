#include <vector>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
  void help(TreeNode *root, vector<int> &ans)
  {
    if (root == nullptr)
    {
      return;
    }
    help(root->left, ans);
    ans.push_back(root->val);
    help(root->right, ans);
  }

  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> ans;
    help(root, ans);
    return ans;
  }
};