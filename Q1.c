#include<stdlib.h>
#include<stdio.h>

struct bin_tree {
int data;
struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

void p_pre(node * tree)
{
    if (tree)
    {
        printf("%d\n",tree->data);
        p_pre(tree->left);
        p_pre(tree->right);
    }

}

void p_in(node * tree)
{
    if (tree)
    {
        p_in(tree->left);
        printf("%d\n",tree->data);
        p_in(tree->right);
    }
}

void p_post(node * tree)
{
    if (tree)
    {
        p_post(tree->left);
        p_post(tree->right);
        printf("%d\n",tree->data);
    }
}

void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}

void main()
{
    node *root;
    node *tmp;

    root = NULL;
    int n,x;
    printf("How many nodes do you want to add? : ");
    scanf("%d",&n);
    printf("Enter their values\n");
    while (n>0) {
      scanf("%d",&x);
      insert(&root, x);
      n--;
    }

    printf("Pre Order Display\n");
    p_pre(root);

    printf("In Order Display\n");
    p_in(root);

    printf("Post Order Display\n");
    p_post(root);

}
