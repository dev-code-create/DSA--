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
int main()
{

  vector<int> preorder = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  Node *root = buildTree(preorder);
  cout << root->data << endl;
  cout << root->left->data << endl;
  cout << root->left->left->data << endl;
  return 0;
}