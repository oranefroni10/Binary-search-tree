/*define the header and libraries*/
#ifndef header
#define header
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*define struct Tree that will be used to build the tree*/
typedef struct Tree
{
    char key[10];
    int count;
    struct Tree*left;
    struct Tree*right;   
}Tree;
/*declare functions*/

/*function that create new tree node and return it*/
Tree*create(char*val);
/*function that insert a new node to the tree*/
void insert(Tree**root,char*val);
/*function that check if the value is already in the tree if it is the func return 1 if not the func return 0*/
int check(Tree*root,char*val);
/*function that print the tree post order*/
void postorder(Tree*root);
/*function that calculate the tree hight and return this value*/
int treeH(Tree*root);
/*function that find the minimum key in the tree and return it*/
char*findmin(Tree*root);
/*function that check if the value is in the tree if yes return 1 if no return 0*/
int find(Tree*root,char*val);
/*function that free the tree*/
void freetree(Tree**root);

#endif