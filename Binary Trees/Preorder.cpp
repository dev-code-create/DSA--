#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int val)
  {
    data = val;
    left = right = NULL;
  }
};

static int index = -1;
Node *buildTree(vector<int> preorder)
{
  index++;
  if (preorder[index] == -1)
  {
    return NULL;
  }

  Node *root = new Node(preorder[index]);
  root->left = buildTree(preorder);
  root->right = buildTree(preorder);
  return root;
}

void preOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

int main()
{
  // Example tree: 1
  //              / \
  //             2   3
  //            /   / \
  //           4   5   6
  // Preorder with -1 as NULL: 1 2 4 -1 -1 -1 3 5 -1 -1 6 -1 -1
  vector<int> preorder = {1, 2, 4, -1, -1, -1, 3, 5, -1, -1, 6, -1, -1};
  Node *root = buildTree(preorder);
  preOrder(root);
  cout << endl;
  return 0;
}