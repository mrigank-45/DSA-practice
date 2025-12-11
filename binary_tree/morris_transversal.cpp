#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

vector < int > preorderTraversal(node * root) {
  vector < int > preorder;

  node * cur = root;
  while (cur != NULL) {
    if (cur -> left == NULL) {
      preorder.push_back(cur -> data);
      cur = cur -> right;
    } else {
      node * prev = cur -> left;
      while (prev -> right != NULL && prev -> right != cur) {
        prev = prev -> right;
      }

      if (prev -> right == NULL) {
        prev -> right = cur;
        preorder.push_back(cur -> data);
        cur = cur -> left;
      } else {
        prev -> right = NULL;
        // inorder.push_back(cur -> data); // Incase of inorder transversal
        cur = cur -> right;
      }
    }
  }
  return preorder;
}
