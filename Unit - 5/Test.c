#include<stdio.h>
#include"./Utils/BuildTree.h"
#include"./Utils/TreeTraversal.h"

int main(){
    int numberOfNodes = 11;
    int nodes[] = {5, 3, 6, 2, 4, -1, -1, -1, -1, -1, -1};
    TreeNode* root = buildTreeFromArray(numberOfNodes, nodes);
    bfs(root);
    return 0;
}