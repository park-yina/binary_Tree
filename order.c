#include<stdio.h>
#include"order.h"

void Pre_order(node* root) {
	if (root != NULL) {
		printf("[%2d]", root->data);
		Pre_order(root->Left);
		Pre_order(root->Right);
	}
}

void In_order(node* root) {
	if (root != NULL) {
		In_order(root->Left);
		printf("[%2d]", root->data);
		In_order(root->Right);
	}
}

void Post_order(node* root) {
	if (root != NULL) {
		Post_order(root->Left);
		Post_order(root->Right);
		printf("[%2d]", root->data);
	}
}
