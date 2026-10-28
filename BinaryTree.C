#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct TreeNode {
  ElementType data;
  TreeNode* lchild;
  TreeNode* rchild;
} TreeNode;

typedef TreeNode* BinaryTree;

char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;
// create a binary tree
void createTree(BinaryTree* root) {
  ElementType ch = str[idx++];
  if (ch == '#') {
    *root = NULL;
  } else {
    *root = (BinaryTree)malloc(sizeof(TreeNode));
    (*root)->data = ch;
    createTree(&((*root)->lchild));
    createTree(&((*root)->rchild));
  }
}

// Preorder traversal
void preoderTraversal(BinaryTree root) {
  if (root == NULL) {
    return;
  }
  printf("%c ", root->data);
  preoderTraversal(root->lchild);
  preoderTraversal(root->rchild);
}

// Inorder traversal
void inorderTraversal(BinaryTree root) {
  if (root == NULL) {
    return;
  }
  inorderTraversal(root->lchild);
  printf("%c ", root->data);
  inorderTraversal(root->rchild);
}

// Postorder traversal
void postorderTraversal(BinaryTree root) {
  if (root == NULL) {
    return;
  }
  postorderTraversal(root->lchild);
  postorderTraversal(root->rchild);
  printf("%c ", root->data);
}

int main(int argc, char* const argv[]) {
  BinaryTree root;
  createTree(&root);

  printf("Preorder Traversal: ");
  preoderTraversal(root);
  printf("\n");

  printf("Inorder Traversal: ");
  inorderTraversal(root);
  printf("\n");

  printf("Postorder Traversal: ");
  postorderTraversal(root);
  printf("\n");

  return 0;
}
