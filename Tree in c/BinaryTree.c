#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node* left;
    int data;
    struct node* right;
}node;
node* root = NULL; 

node* cerateNode(int data)
{
    node* newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node* insert(node* root, int data)
{

    if(root == NULL) 
    {
        root = cerateNode(data);
        // printf("inserted on root %d\n", root->data);
    }
    else if(root->data > data) 
    {   
        root->left = insert(root->left,data); 
        // printf("inserted on left %d\n", root->data);
    }
    else if(root->data < data)
    { 
        root->right = insert(root->right,data);
        // printf("inserted on right %d\n", root->data);
    }
    return root;
}

void preorder(node* root)       //root left right
{      
    if(root == NULL) return;
    printf("%d  ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root)        //left root right
{       
    if(root == NULL) return;
    inorder(root->left);
    printf("%d  ",root->data);
    inorder(root->right);
}

void postorder(node* root)      //left right root
{
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d  ",root->data);
}

int main()
{
    int option,data;
    printf("\n1. Insert\n2. Preorder Traverse\n3. Inorder Traverse\n4. Postorder Traverse\n0. EXIT\n");

    do
    {
        printf("\nEnter choice = ");
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            printf("Enter data for insertion = ");
            scanf("%d",&data);
            root = insert(root, data);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 0:
            printf("\nExiting...");
            return 0;
        default:
            printf("\nInvalid Option.");
            break;
        }
    }while (option!=0);
}