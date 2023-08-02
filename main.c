#include "header.h"
#include "imp.c"

int main()
{
    Tree*root=NULL;
    int h=0,i=0,x=0;
    char v[10];
    char min[10];
    printf("Welcome!\nTo add a node to the tree press 1\nTo print (postorder) the tree press 2\n");
    printf("To calculate the tree hight press 3\nTo find the tree minimum press 4\nTo search for a node by key press 5\n:");
    scanf("%d",&x);
    /*while loop that run through the proccess until the user enter -1*/
    while (x!=-1)
    {
        if (x==1)
        {
            /*use the function insert*/
            printf("You pressed 1\nPlease enter a key to the node:");
            scanf("%s",v);
            insert(&root,v);
            printf("The node added successfully\n");
        }
        else if (x==2)
        {
            /*use the function postorder*/
             printf("You pressed 2\nHere is the tree printed in post order:");
             postorder(root);
        }
        else if (x==3)
        {
            /*use the function treeH*/
            printf("You pressed 3\nThe tree hight is:");
            h=treeH(root);
            printf("%d",h);
        }
        else if (x==4)
        {
            /*use the function findmin*/
            printf("You pressed 4\nThe tree minimum key is:");
            strcpy(min,findmin(root));
            printf("%s",min);

        }
        else if (x==5)
        {
            /*use the function find*/
            printf("You pressed 5\nEnter a string to search in the tree:");
            scanf("%s",v);
            i=find(root,v);
            if (i==1)
            {
                printf("\n%s Is in the tree\n",v);
            }
            else
            {
                printf("\nNot in the tree\n");
            }
        }
        else
        {
            printf("\nError please enter x between 1 to 5:");
            scanf("%d",&x);
        }
        printf("\npick another action or press -1 to exit:");
        scanf("%d",&x);
    }
    /*use the function freetree*/
    freetree(&root);
    printf("Thank you for your use, the tree is now free!");
    return 0;
}