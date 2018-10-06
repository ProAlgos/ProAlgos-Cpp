#include <stdio.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newnode(int data){
    struct node* node=malloc(sizeof(struct node));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return (node);
};
struct node* insert(struct node* node,int data){
    if (node==NULL){
        return(newnode(data));
    }
    else{
        if(data <= node->data){
            node->left=insert(node->left,data);
        }
        else{
            node->right=insert(node->right,data);
        }
        return node;
    }
};
int FindMin(struct node* root){
    if(root==NULL){
        printf("Error : Tree is empty\n");
        return -1;
    }
    while(root->left!=NULL){
    root=root->left; }
    return root->data;
}
int FindMax(struct node* root){
    if(root==NULL){
        printf("Error : Tree is empty\n");
        return -1;
    }
    while(root->right!=NULL){
    root=root->right; }
    return root->data;
}
int main(){
    int k,i;
    printf("The number of nodes in a tree : ");
    scanf("%d",&k);
    int a[k];
    printf("\n");
    for(i=0;i<k;i++){
        scanf("%d",&a[i]);
    }
    struct node* root = NULL;
    root = insert(root, a[0]);
    for(i=1;i<k;i++){
        insert(root,a[i]);
    }
    printf("Minimum value : %d",FindMin(root));
    printf("\n");
    printf("Maximum value : %d", FindMax(root));
    printf("\n");
    return 0;
}
