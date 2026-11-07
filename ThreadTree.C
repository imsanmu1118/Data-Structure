#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct ThreadNode {
  ElementType data;
  struct ThreadNode* lchild;
  struct ThreadNode* rchild;
  int ltag; // 0 for child, 1 for thread
  int rtag; // 0 for child, 1 for thread
} ThreadNode;

typedef ThreadNode* ThreadTree;

char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;

ThreadTree pre = NULL; // Pointer to the previous node in the traversal

// Create a binary tree
void createTree(ThreadTree* root) {
  ElementType ch = str[idx++];
  if (ch == '#') {
    *root = NULL;
  } else {
    *root = (ThreadTree)malloc(sizeof(ThreadNode));
    (*root)->data = ch;
    (*root)->ltag = 0; // Initialize ltag to 0 (child)
    (*root)->rtag = 0; // Initialize rtag to 0 (child)
    createTree(&((*root)->lchild));
    createTree(&((*root)->rchild));
  }
}

// Thread the binary tree in inorder
void threading(ThreadTree root) {
    if(root != NULL) {
        threading(root->lchild); // Thread the left subtree

        // If the left child is NULL, set ltag to 1 and point to pre
        if(root->lchild == NULL) {
            root->ltag = 1; // Set ltag to thread
            root->lchild = pre; // Point to the previous node
        }

        // If pre's right child is NULL, set rtag to 1 and point to root
        if(pre != NULL && pre->rchild == NULL) {
            pre->rtag = 1; // Set rtag to thread
            pre->rchild = root; // Point to the current node
        }

        pre = root; // Move pre to the current node

        threading(root->rchild); // Thread the right subtree
    }
}

// Create an inorder threaded binary tree
void inorderThreading(ThreadTree *head, ThreadTree root) {
    *head = (ThreadTree)malloc(sizeof(ThreadNode));
    (*head)->ltag = 0; // Left child
    (*head)->rtag = 1; // Right thread
    (*head)->rchild = *head; // Right child points to head

    if (root == NULL) {
        (*head)->lchild = *head; // Left child points to head if tree is empty
    } else {
        (*head)->lchild = root; // Left child points to the root of the tree
        pre = *head; // Initialize pre to head
        threading(root); // Start threading the tree
        pre->rchild = *head; // Last node's right child points to head
        pre->rtag = 1; // Last node's right tag is set to thread
        (*head)->rchild = pre; // Head's right child points to the last node
    }
}

// Inorder traversal of the threaded binary tree
void inorderTraversal(ThreadTree head) {
    ThreadTree current = head->lchild; // Start from the root of the tree
    while (current != head) {
        // Move to the leftmost node
        while (current->ltag == 0) {
            current = current->lchild;
        }
        printf("%c ", current->data); // Visit the node

        // Use threads to traverse the tree
        while (current->rtag == 1 && current->rchild != head) {
            current = current->rchild;
            printf("%c ", current->data); // Visit the node
        }
        current = current->rchild; // Move to the right child
    }
}

int main(int argc, char* const argv[]) {
    ThreadTree root;
    createTree(&root);

    ThreadTree head;
    inorderThreading(&head, root);

    printf("Inorder Traversal of Threaded Binary Tree: ");
    inorderTraversal(head);
    printf("\n");

    return 0;
}
