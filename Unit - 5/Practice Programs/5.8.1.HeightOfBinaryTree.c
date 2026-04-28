/*
* How to run this program (linux & Mac & putty(windows)) : 
* $ gcc 5.8.1.HeightOfBinarytree.c ../Utils/*.c -o ouput
* $ ./output
*/

#include<stdio.h>
#include"../Utils/QueueForTree.h"
#include"../Utils/BuildingBlockTree.h"

void constructBinaryTree(TreeNode** root, int numberOfNodes, int nodes[numberOfNodes][2]){
	if(numberOfNodes == 0) return;
    Queue q;
    init(&q);
	*root = createTreeNode(nodes[0][0]);
	enqueue(&q, *root);
	int i = 1;
	while(!isEmpty(&q) && i < numberOfNodes){
		TreeNode* curr = dequeue(&q);

		// left child
		if(i < numberOfNodes && nodes[i][1] == -1){
			curr->left = createTreeNode(nodes[i][0]);
			enqueue(&q, curr->left);
			i++;
		}
		// right child
		if(i < numberOfNodes && nodes[i][1] == 1){
			curr->right = createTreeNode(nodes[i][0]);
			enqueue(&q, curr->right);
			i++;
		}
	}
}

int max(int a, int b){
	return a >= b ? a : b; 
}

int heightOfBinaryTree(TreeNode* root){
	if(root == NULL) return 0;
	int leftHeight = heightOfBinaryTree(root->left);
	int rightHeight = heightOfBinaryTree(root->right);
	return 1 + max(leftHeight, rightHeight);
}

int main(){
	int n;
	scanf("%d", &n);
	// handle empty tree case
	if(n <= 0){
		printf("Invalid number of nodes");
		return -1;
	}
	
	// -1 for left and +1 for right
	int nodes[n][2];
	for(int i = 0; i < n; i++){
		if(i == 0){
			scanf("%d", &nodes[i][0]);
			nodes[i][1] = 0;
			continue;
		}
		scanf("%d", &nodes[i][0]);
		char orientation;
		scanf(" %c", &orientation);
		if(orientation == 'L'){
			nodes[i][1] = -1;
		}
		else 
			nodes[i][1] = 1;
	}

	TreeNode* root = NULL;
	constructBinaryTree(&root, n, nodes);
	printf("%d", heightOfBinaryTree(root));
	return 0;
}
