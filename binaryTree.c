#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Define a structure for the queue
struct Queue
{
    struct Node* data;
    struct Queue* next;
};

struct Node* createNode(int data)
{
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Queue* createQueueNode(struct Node* node)
{
    struct Queue* qNode = malloc(sizeof(struct Queue));
    qNode->data = node;
    qNode->next = NULL;
    return qNode;
}

struct Queue* enqueue(struct Queue* front, struct Node* node)
{
    struct Queue* qNode = createQueueNode(node);
    if (front == NULL)
    {
        return qNode;
    }
    struct Queue* rear = front;
    while (rear->next != NULL)
    {
        rear = rear->next;
    }
    rear->next = qNode;
    return front;
}

struct Queue* dequeue(struct Queue* front)
{
    if (front == NULL)
    {
        return front;
    }
    struct Queue* temp = front;
    front = front->next;
    free(temp);
    return front;
}

int isQueueEmpty(struct Queue* front)
{
    return front == NULL;
}

// Perform level-order traversal
void levelOrderTraversal(struct Node* root)
{
    if (root == NULL)
    {
        return;
    }

    struct Queue* queue = NULL;
    queue = enqueue(queue, root);

    while (!isQueueEmpty(queue))
    {
        struct Node* current = queue->data;
        printf("%d ", current->data);

        if (current->left != NULL)
        {
            queue = enqueue(queue, current->left);
        }
        if (current->right != NULL)
        {
            queue = enqueue(queue, current->right);
        }

        queue = dequeue(queue);
    }
}

// Find the level of a specific node in the binary tree
int findLevel(struct Node* root, int key, int level)
{
    if (root == NULL)
    {
        return -1; // Node not found
    }
    if (root->data == key)
    {
        return level; // Node found at the current level
    }

    int leftLevel = findLevel(root->left, key, level + 1);
    if (leftLevel != -1)
    {
        return leftLevel; // Node found in the left subtree
    }

    return findLevel(root->right, key, level + 1); // Node found in the right subtree
}

int findSize(struct Node* root)
{
    if(root == NULL)
    {
        return 0;
    }    
    return 1+findSize(root->left)+findSize(root->right);
}

int findLeafNodes(struct Node* root)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int leftLeafNodes = findLeafNodes(root->left);
    int rightLeafNodes = findLeafNodes(root->right);
    return leftLeafNodes + rightLeafNodes;
}

int main()
{
    int searchValue, deleteValue;
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);

    printf("\nLevel-order traversal of the binary tree: ");
    levelOrderTraversal(root);

    printf("\nEnter the element to find its level: ");
    scanf("%d", &searchValue);

    int level = findLevel(root, searchValue, 0);
    if (level != -1)
    {
        printf("The Level of the given element is: %d\n", level);
    }
    else
    {
        printf("The element you gave is not found in the tree!\n");
    }
    int size = findSize(root);
    printf("\nThe size of the tree is %d",size);
    int leafNodes = findLeafNodes(root);
    printf("\nThe Number of leaf nodes : %d",leafNodes);
    return 0;
}
