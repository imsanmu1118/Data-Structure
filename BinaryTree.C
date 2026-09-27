#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct TreeNode {
    ElementType data;
    TreeNode* lchild;
    TreeNode* rchild;
} TreeNode;

typedef TreeNode* BinaryTree;

 