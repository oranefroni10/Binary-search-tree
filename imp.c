#include "header.h"
/*functions implementation*/
/*function that create new node and return it*/
Tree*create(char*val)
{
    Tree*temp;
    temp = (Tree*)malloc(sizeof(Tree));
    if (temp==NULL)
    {
        printf("Error");
        return NULL;
    }
    strcpy(temp->key,val);
    temp->count=0;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
/*void function that create new node using create function and insert it to the tree*/
void insert(Tree** root, char* val)
{
    if (check(*root,val)==1)
    {
        printf("This key is already exist so we'll add 1 to the appropriate node");
        return;
    }
    printf("This is a new key\n");
    Tree* temp = create(val);
    if (temp == NULL)
    {
        printf("error");
        exit(1);
    }

    if (*root == NULL)  // Check if the tree is empty
    {
        *root = temp;  // Set the root to the new node
        return;
    }

    Tree* current = *root;
    while (1)
    {
        if (strcmp(current->key, val) > 0)
        {
            if (current->left == NULL)
            {
                current->left = temp;
                break;
            }
            else
            {
                current = current->left;
            }
        }
        else
        {
            if (current->right == NULL)
            {
                current->right = temp;
                break;
            }
            else
            {
                current = current->right;
            }
        }
    }
}
/*function that check if the key is already in the tree if yes the function will increase its count value and return 1 if nor the function will return 0*/
int check(Tree*root,char*val)
{
    int i=0;
    Tree*temp=root;
    while (temp!=NULL)
    {
        if (strcmp(temp->key,val)==0)
        {
            temp->count++;
            return 1;
        }
        else if (strcmp(temp->key,val)<0)
        {
            temp=temp->left;
        }
        else if (strcmp(temp->key,val)>0)
        {
            temp=temp->right;
        }
    }
    return 0;
    
}
/*recursive function that will print the tree in post order*/
void postorder(Tree* root)
{
    Tree*temp=root;
    if (temp == NULL)
    {
        return;
    }
    postorder(temp->left);
    postorder(temp->right);
    printf("%s ", temp->key);
}
/*recursive function that will calculate and return the tree hight*/
int treeH(Tree*root)
{
    int lh, rh;
    if (root == NULL) 
        return -1;
    lh = treeH(root->left);
    rh = treeH(root->right);
    if(lh>rh)
        return 1 + lh;
    else
        return 1 + rh;
}
/*function that find the minimum value in the tree and return it*/
char*findmin(Tree*root)
{
    char* min;
    min=(char*)malloc(10*sizeof(char));
    if (root==NULL)
    {
        printf("Tree is empty");
        return "False";
    }
    strcpy(min,root->key);
    Tree*temp;
    temp=root;
    while (temp!=NULL)
    {
        if (strcmp(temp->key,min)<=0)
        {
            temp=temp->left;
            if(temp!=NULL)
            {
                strcpy(min,temp->key);
            }
        }
        else if (strcmp(temp->key,min)>0)
        {
            
            temp=temp->right;
        }
    }
    return min;
}
/*function that check if a key is in the tree if yes return 1 if no return 0*/
int find(Tree*root,char*val)
{
    Tree*temp=root;
    while (temp!=NULL)
    {
        if (strcmp(temp->key,val)==0)
        {
            return 1;
        }
        else if (strcmp(temp->key,val)>0)
        {
            temp=temp->left;
        }
        else if (strcmp(temp->key,val)<0)
        {
            temp=temp->right;
        }
    }
    return 0;
    
}
/*recursive function that free all the nodes in the tree*/
void freetree(Tree**root)
{
    if ((*root) == NULL)
        return;
    freetree(&((*root)->left));
    freetree(&((*root)->right));
    free(*root);
    *root = NULL;
}