#include <vector>
#include <stack>

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
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> preorder; // ✅ Result vector to store values
    stack<TreeNode *> st; // ✅ Stack to simulate recursion

    if (root == nullptr)
      return preorder; // ✅ Base case: empty tree

    st.push(root); // ✅ Push the root to start traversal

    while (!st.empty())
    {                           // ✅ Process until stack is empty
      TreeNode *top = st.top(); // ✅ Get top element (current node)
      st.pop();                 // ✅ Remove it from stack

      preorder.push_back(top->val); // ✅ Visit node: add its value

      if (top->right != nullptr)
      {                      // ✅ Push right child first
        st.push(top->right); // So left is processed first
      }

      if (top->left != nullptr)
      { // ✅ Push left child next
        st.push(top->left);
      }
    }

    return preorder; // ✅ Return the result
  }
};
