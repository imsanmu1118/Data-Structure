//层序遍历求解树的深度
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef char TreeType;

typedef struct TreeNode
{
    TreeType data;
    struct TreeNode *lchild;
    struct TreeNode *rchild;
}TreeNode;

typedef TreeNode* ElemType;

typedef struct
{
    ElemType *data;
    int front;
    int rear;
}Queue;

typedef TreeNode* BinaryTree;

char str[] = "ABDH#K###E##CFI###G#J##";
int idx = 0;

void createTree(BinaryTree* root)
{
    TreeType ch = str[idx++];
    if (ch == '#')
    {
        *root = NULL;
    }
    else
    {
        *root = (BinaryTree)malloc(sizeof(TreeNode));
        (*root)->data = ch;
        createTree(&((*root)->lchild));
        createTree(&((*root)->rchild));
    }
}

// Initialize the queue
Queue* initQueue()
{
    Queue* Q = (Queue*)malloc(sizeof(Queue));
    Q->data = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
    Q->front = 0;
    Q->rear = 0;
    return Q;
}

// Check if the queue is empty
int isEmpty(Queue* Q)
{
    return Q->front == Q->rear;
}

// Enqueue an element
int enqueue(Queue* Q, ElemType e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
    {
        printf("Queue is full\n");
        return 0; // Queue is full
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return 1; // Enqueue successful
}

// Dequeue an element
int dequeue(Queue* Q, ElemType* e)
{
    if (isEmpty(Q))
    {
        printf("Queue is empty\n");
        return 0; // Queue is empty
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return 1; // Dequeue successful
}

// Get the front element of the queue
int getFront(Queue* Q, ElemType* e)
{
    if (isEmpty(Q))
    {
        printf("Queue is empty\n");
        return 0; // Queue is empty
    }
    *e = Q->data[Q->front];
    return 1; // Get front successful
}

//Get the amount of elements in the queue
int queueSize(Queue* Q)
{
    return (Q->rear - Q->front + MAXSIZE) % MAXSIZE;
}

// Level order traversal to calculate the depth of the tree
int levelOrderTraversal(BinaryTree root)
{
    if (root == NULL)
    {
        return 0; // Empty tree has depth 0
    }

    Queue* Q = initQueue();
    enqueue(Q, root);
    int depth = 0;

    while (!isEmpty(Q))
    {
        int levelSize = queueSize(Q);
        depth++;

        for (int i = 0; i < levelSize; i++)
        {
            ElemType currentNode;
            dequeue(Q, &currentNode);

            if (currentNode->lchild != NULL)
            {
                enqueue(Q, currentNode->lchild);
            }
            if (currentNode->rchild != NULL)
            {
                enqueue(Q, currentNode->rchild);
            }
        }
    }

    free(Q->data);
    free(Q);
    return depth;
}

int main()
{
    BinaryTree root;
    createTree(&root);

    int depth = levelOrderTraversal(root);
    printf("Depth of the tree: %d\n", depth);

    return 0;
}
