#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int val;
    struct node *left, *right;
} node;

node *Newnode(int val){
    node *node = (struct node*)malloc(sizeof(node));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

node* insert(int data, node* root){
    if(root==NULL){
        return Newnode(data);
    }
    else{
        if(data > root->val){
            root->right = insert(data, root->right);        
        } 
        else{
            root->left = insert(data, root->left);        
        } 
        return root;
    }
}

node* search(int data, node* root){
    if(root==NULL){
        return NULL;
    }
    else if(root->val == data){
        return root;
    }
    else{

        if(data > root->val){
            root->right = search(data, root->right);   
        } 
        else{
            root->left = search(data, root->left);        
        } 
    }
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    else{
        inorder(root->left);
        printf(" %d", root->val);
        inorder(root->right);
    }
}

node* InorderSucc(node* root){
    node* cur=root;
    while(cur && cur->left!=NULL){
        cur = cur->left;
    }
    return cur;
}

node* delete(int data, node* root){
    if(data > root->val){
        root->right = delete(data, root->right);        
    } 
    else if(data < root->val){
        root->left = delete(data, root->left);        
    } 
    else{
        if(root->left==NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }
        node* temp = InorderSucc(root->right);
        root->val = temp->val;
        root->right = delete(temp->val, root->right);
    }
    return root;
}

int main() {
    node* root = Newnode(12);
    root = insert(47, root);
    insert(52, root);
    insert(45, root);
    insert(46, root);
    insert(10, root);

    inorder(root);
    root = delete(47, root);
    printf("\n");
    inorder(root);
    search(45, root);
    
    if(search(45, root)!=NULL){
        printf("\nValue exists");
    }
    else{
        printf("\nValue does not exists");
    }
    return 0;
}
