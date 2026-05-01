#include<stdio.h>
#include"TreeTraversal.h"

void dfs(TreeNode* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);
    dfs(root->left);
    dfs(root->right);
    return;
}

void bfs(TreeNode* root){
    if(root == NULL) return;
    Queue q;
    init(&q);
    int sizeOfLevel = 0, level = 0;
    // push the root into the queue
    enqueue(&q, root);

    while(!isEmpty(&q)){
        sizeOfLevel = sizeOfQueue(&q);
        printf("Level - %d : ", level);
        for(int i = 0; i < sizeOfLevel; i++){
            TreeNode* frontElement = dequeue(&q);
            printf("%d ", frontElement->data);
            if(frontElement->left != NULL)
                enqueue(&q, frontElement->left);
            if(frontElement->right != NULL)
                enqueue(&q, frontElement->right);
        }
        level++;
        printf("\n");
    }
}