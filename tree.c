#include<stdio.h>
#include<stdlib.h>
#include"binary_tree.h"
int main() {
    node* root = NULL; 

    root = Insert(root, 50);
    root = Insert(root, 30);
    root = Insert(root, 20);
    root = Insert(root, 40);
    root = Insert(root, 70);
    root = Insert(root, 60);
    root = Insert(root, 80);

    int searchData = 30;
    node* result = Search(root, searchData);
    if (result != NULL) {
        printf("이진 트리에서 %d를 찾았습니다.\n", searchData);
    }
    else {
        printf("이진 트리에서 %d를 찾지 못했습니다.\n", searchData);
    }

    return 0;
}


