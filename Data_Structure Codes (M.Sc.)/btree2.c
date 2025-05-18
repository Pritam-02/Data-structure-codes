/*#include <stdio.h>
#include <stdlib.h>

// Define the order of the B-tree
#define MAX 5 // Order (m)
#define MIN (MAX / 2)

// B-tree node structure
typedef struct BTreeNode {
    int keys[MAX - 1];
    struct BTreeNode *children[MAX];
    int count;
    int leaf;
} BTreeNode;

// Function to create a new B-tree node
BTreeNode *createNode(int leaf) {
    BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));
    node->leaf = leaf;
    node->count = 0;
    for (int i = 0; i < MAX; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to split a child node
void splitChild(BTreeNode *parent, int index) {
    BTreeNode *child = parent->children[index];
    BTreeNode *newChild = createNode(child->leaf);
    newChild->count = MIN;

    for (int i = 0; i < MIN; i++) {
        newChild->keys[i] = child->keys[i + MIN];
    }
    if (!child->leaf) {
        for (int i = 0; i <= MIN; i++) {
            newChild->children[i] = child->children[i + MIN];
        }
    }

    child->count = MIN;
    for (int i = parent->count; i >= index + 1; i--) {
        parent->children[i + 1] = parent->children[i];
    }
    parent->children[index + 1] = newChild;

    for (int i = parent->count - 1; i >= index; i--) {
        parent->keys[i + 1] = parent->keys[i];
    }
    parent->keys[index] = child->keys[MIN - 1];
    parent->count++;
}

// Function to insert a key into a non-full node
void insertNonFull(BTreeNode *node, int key) {
    int i = node->count - 1;

    if (node->leaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->count++;
    } else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;
        if (node->children[i]->count == MAX - 1) {
            splitChild(node, i);
            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->children[i], key);
    }
}

// Function to insert a key into the B-tree
BTreeNode *insert(BTreeNode *root, int key) {
    if (!root) {
        root = createNode(1);
        root->keys[0] = key;
        root->count = 1;
        return root;
    }

    if (root->count == MAX - 1) {
        BTreeNode *newRoot = createNode(0);
        newRoot->children[0] = root;
        splitChild(newRoot, 0);

        int i = (key > newRoot->keys[0]) ? 1 : 0;
        insertNonFull(newRoot->children[i], key);
        return newRoot;
    } else {
        insertNonFull(root, key);
        return root;
    }
}

// Function to perform in-order traversal of the B-tree
void traverse(BTreeNode *node) {
    if (node) {
        for (int i = 0; i < node->count; i++) {
            traverse(node->children[i]);
            printf("%d ", node->keys[i]);
        }
        traverse(node->children[node->count]);
    }
}

int main() {
    BTreeNode *root = NULL;
    int n, key;

    printf("Enter the number of keys to insert: ");
    scanf("%d", &n);

    printf("Enter the keys: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        root = insert(root, key);
    }

    printf("B-tree in-order traversal: \n");
    traverse(root);
    printf("\n");

    return 0;
}




#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum number of children a node can have (order m = 5)
#define MIN 2 // Minimum number of children a node can have ((m+1)/2)

typedef struct BTreeNode {
    int keys[MAX + 1]; // An extra space to handle overflow
    struct BTreeNode *child[MAX + 1];
    int n; // Current number of keys
    int leaf; // True if the node is a leaf
} BTreeNode;

BTreeNode *root = NULL;

BTreeNode* createNode(int leaf) {
    BTreeNode *newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
    newNode->leaf = leaf;
    newNode->n = 0;
    for (int i = 0; i < MAX + 1; i++)
        newNode->child[i] = NULL;
    return newNode;
}

void traverse(BTreeNode *node) {
    for (int i = 0; i < node->n; i++) {
        if (!node->leaf)
            traverse(node->child[i]);
        printf("%d ", node->keys[i]);
    }
    if (!node->leaf)
        traverse(node->child[node->n]);
}

BTreeNode* insertNonFull(BTreeNode *node, int k) {
    int i = node->n - 1;
    if (node->leaf) {
        while (i >= 0 && k < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = k;
        node->n++;
    } else {
        while (i >= 0 && k < node->keys[i])
            i--;
        i++;
        if (node->child[i]->n == MAX) {
            splitChild(node, i, node->child[i]);
            if (k > node->keys[i])
                i++;
        }
        node->child[i] = insertNonFull(node->child[i], k);
    }
    return node;
}

void splitChild(BTreeNode *parent, int i, BTreeNode *y) {
    BTreeNode *z = createNode(y->leaf);
    z->n = MIN;

    for (int j = 0; j < MIN; j++)
        z->keys[j] = y->keys[j + MIN + 1];
    
    if (!y->leaf) {
        for (int j = 0; j <= MIN; j++)
            z->child[j] = y->child[j + MIN + 1];
    }

    y->n = MIN;

    for (int j = parent->n; j >= i + 1; j--)
        parent->child[j + 1] = parent->child[j];

    parent->child[i + 1] = z;

    for (int j = parent->n - 1; j >= i; j--)
        parent->keys[j + 1] = parent->keys[j];

    parent->keys[i] = y->keys[MIN];
    parent->n++;
}

void insert(int k) {
    if (root == NULL) {
        root = createNode(1);
        root->keys[0] = k;
        root->n = 1;
    } else {
        if (root->n == MAX) {
            BTreeNode *s = createNode(0);
            s->child[0] = root;
            splitChild(s, 0, root);
            int i = 0;
            if (s->keys[0] < k)
                i++;
            s->child[i] = insertNonFull(s->child[i], k);
            root = s;
        } else {
            root = insertNonFull(root, k);
        }
    }
}

int main() {
    int n, key;
    printf("Enter the number of keys to be inserted: ");
    scanf("%d", &n);

    printf("Enter the keys to be inserted: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    printf("Traversal of B-tree:\n");
    traverse(root);

    return 0;
}
*/