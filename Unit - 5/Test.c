#include<stdio.h>
#include"./Utils/BuildTree.h"
#include"./Utils/TreeTraversal.h"

int main(){
    int numberOfNodes = 7;
    int nodes[] = {1, 2, 3, 4, 5, -1, -1};
    TreeNode* root = buildTreeFromArray(numberOfNodes, nodes);
    dfs(root);
    return 0;
}