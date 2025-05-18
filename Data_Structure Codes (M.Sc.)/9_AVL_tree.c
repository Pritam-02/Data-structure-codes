#include<stdio.h>
#include<stdlib.h>

struct Node{
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

// func. to calculate height
int height( struct Node *N) {
    if (N == NULL)
    return 0;
    return N->height;
}

// func. to calculate max
int max(int a, int b) {
    return (a > b) ? a : b;
}

//func. to create a new node
struct Node* newNode(int key) {
    
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return(node);
}

// get the balance factor
int getBF(struct Node *N){
    if (N == NULL)
    return 0;
    return height(N->left) - height(N->right);
}

//min. value node
struct Node* minValNode(struct Node* node){
    struct Node* current = node;
    while(current->left != NULL)
    current = current->left;
    return current;
}

// left rotation
struct Node* leftRotate(struct Node *x) {
struct Node* y= x->right;
struct Node* z = y->left;
y->left = x;
x->right = z;
x->height = max(height(x->left), height(x->right))+1;
y->height = max(height(y->left), height(y->right))+1;
return y;
}

//right rotation
struct Node* rightRotate(struct Node *y) {
struct Node* x= y->left;
struct Node* z= x->right;
x->right = y;
y->left = z;
y->height = max(height(y->left), height(y->right))+1;
x->height = max(height(x->left), height(x->right))+1;
return x;
}

//insert node
struct Node* InsertNode(struct Node* node, int key){
    if (node == NULL){
        return newNode(key);
    }
    if (key < node->key){
        node->left = InsertNode(node->left, key);
    }
    else if (key > node->key )
    {
        node->right = InsertNode(node->right, key);
    }
    else {
        return node;
    }

    //update the balance factor of each node
    node->height = 1 + max(height(node->left),height(node->right));
    int balance = getBF(node);

    //rotations
    if (balance > 1 && key < node->left->key) //RR rotation
    {
        return rightRotate(node);
    }
    if (balance < -1 && key > node->right->key) //LL rotation
    {
        return leftRotate(node);
    }
    if (balance > 1 && key > node->left->key) //LR rotation
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) //RL rotation
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
return node;
}

//delete node
struct Node* deleteNode(struct Node* node, int key){
//find the node and delete it
if (node == NULL){
    return node;
}
if(key < node->key){
    node->left = deleteNode(node->left, key);
}
else if(key > node->key){
    node->right = deleteNode(node->right, key);
}
else{
    if((node->left == NULL) || (node->right == NULL))
    {
        struct Node* temp = node->left ? node->left : node->right;
        if(temp == NULL) //node to be deleted is leaf node
        {
            temp = node;
            node = NULL;
        }
        else //node to be deleted has one child
        {
            *node = *temp;
        }
        free (temp);
    }
    else //node to beleted has two children
    {
        struct Node* temp = minValNode(node->right);
        node->key = temp->key;
        node->right = deleteNode(node->right, temp->key);
    }   
}
if (node == NULL) //value not found
{
    return node;
}

//update the balance factor of each node and balance the tree
node->height = 1 + max(height(node->left),height(node->right));
int balance = getBF(node);

//rotation after delete
if (balance > 1 && getBF(node->left) >= 0) //R0,R1 rotation
{
    return rightRotate(node);
}
if (balance > 1 && getBF(node->left) < 0) //R1 rotation
{
    node->left = leftRotate(node->left);
    return rightRotate(node);
}
if (balance < -1 && getBF(node->right) <= 0) //L-1,L0 rotation
{
    return leftRotate(node);
}
if (balance < -1 && getBF(node->right) > 0) //L1 rotation
{
    node->right = rightRotate(node->right);
    return leftRotate(node);
}
return node;
}

//print the tree
//preorder
void preorder(struct Node* node)
{
    if(node != NULL)
    {
        printf("%d ", node->key);
        preorder(node->left);
        preorder(node->right);
    }
}

//inorder
void inorder(struct Node* node)
{
    if(node != NULL)
    {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

//postordet
void postorder(struct Node* node)
{
    if(node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->key);
    }
}

//main function
int main()
{
    struct Node* node = NULL;
    int val,ch;
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter value to be inserted: ");
            scanf("%d",&val);
            Output:
            node = InsertNode(node, val);
            break;
            case 2:
            printf("Enter value to be deleted: ");
            scanf("%d",&val);
            node = deleteNode(node, val);
            break;
            case 3:
            printf("\nPreorder:\n");
            preorder(node);
            printf("\nInorder:\n");
            inorder(node);
            printf("\nPostorder:\n");
            postorder(node);
            //printf("\n");
            break;
            case 4:
            exit(0);
            break;     
        
        }
    }
    return 0;
}
