#include <stdio.h>
#include <stdlib.h>

// 简单二叉树结点定义
typedef struct Node {
  int val;
  struct Node *left;
  struct Node *right;
} Node;

// 创建新结点
Node *new_node(int v) {
  Node *n = (Node *)malloc(sizeof(Node));
  if (!n) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  n->val = v;
  n->left = NULL;
  n->right = NULL;
  return n;
}

// 先序遍历：根 -> 左 -> 右
void preorder(Node *root) {
  if (root == NULL)
    return;
  printf("%d ", root->val);
  preorder(root->left);
  preorder(root->right);
}
// 中序遍历：左 -> 根 -> 右
void inorder(Node *root) {
  if (root == NULL)
    return;
  inorder(root->left);
  printf("%d ", root->val);
  inorder(root->right);
}

// 后序遍历：左 -> 右 -> 根
void postorder(Node *root) {
  if (root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  printf("%d ", root->val);
}

// 释放整棵树
void free_tree(Node *root) {
  if (root == NULL)
    return;
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}

int main(void) {
  system("chcp 65001");
  // 构造一棵示例二叉树：
  //        1
  //      /   \
    //     2     3
  //    / \   /
  //   4   5 6
  Node *root = new_node(1);
  root->left = new_node(2);
  root->right = new_node(3);
  root->left->left = new_node(4);
  root->left->right = new_node(5);
  root->right->left = new_node(6);

  printf("先序遍历: ");
  preorder(root);
  printf("\n");
  printf("中序遍历: ");
  inorder(root);
  printf("\n");
  printf("后序遍历: ");
  postorder(root);
  printf("\n");

  free_tree(root);
  return 0;
}