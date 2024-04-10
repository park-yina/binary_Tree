#include"binary_tree.h"
#include<stdio.h>
#include<stdlib.h>
node* Insert(node* root, int data) {
    if (root == NULL) {
        node* Node = (node*)malloc(sizeof(node));
        if (Node == NULL) {
            printf("왜 이게 널일까");
        }
        else {
            Node->data = data;
            Node->Left = NULL;
            Node->Right = NULL;
        }
        return Node;
    }
    else {
        //root에는 이미 값이 있다는 것이니 루트와 크기를 비교하여서 왼 오를 나누어서 삽입해주어야 한다.
        if (data <= root->data && root->Left == NULL) {
            root->Left = Insert(root->Left, data);
        }
        else {
            root->Right = Insert(root->Right, data);
        }
    }
    return root;
}
node* Search(node* node, int data) {
    if (node == NULL)return NULL;
    if (node->data == data) {
        return node;
    }
    else {
        if (data <= node->data) {
            //만약 데이터가 노드의 데이터보다 작거나 같다면
            return Search(node->Left, data);
        }
        else {
            return Search(node->Right, data);
        }
    }
}
node* FindMaxNode(node* standard, node** max_node) {
    if (standard->Right == NULL) {
        *max_node = standard;
        return standard->Left; //오른쪽이 비어있으니 당연 왼쪽을 반환해야하는데 실수함...능지
    }
    else {
        standard->Right = FindMaxNode(standard->Right, max_node);
        return standard;
    }
}
node* FindParent(node* root, node* child) {
    if (root == NULL || root == child) {
        return NULL;
    }
    // 현재 노드의 자식이 삭제할 노드인 경우
    if (root->Left == child || root->Right == child) {
        return root;
    }
    node* parent = FindParent(root->Left, child); // 먼저 왼쪽 서브트리를 탐색
    if (parent != NULL) {
        return parent;
    }
    return FindParent(root->Right, child); // 그 다음 오른쪽 서브트리를 탐색
}

node* DeleteNode(node* root, int data) {
    if (root == NULL) {
        printf("노드에서 데이터를 찾지 못했습니다");
        return NULL;
    }

    node* parent = FindParent(root, root);

    if (root->data == data) {
        node* to_delete = root;
        if (to_delete->Left == NULL && to_delete->Right == NULL) {
            if (parent != NULL) {
                if (parent->Left == to_delete)
                    parent->Left = NULL;
                else
                    parent->Right = NULL;
            }
            free(to_delete);
            return NULL;
        }
        else if (to_delete->Left == NULL && to_delete->Right != NULL) {
            if (parent != NULL) {
                if (parent->Left == to_delete)
                    parent->Left = to_delete->Right;
                else
                    parent->Right = to_delete->Right;
            }
            node* temp = to_delete->Right;
            free(to_delete);
            return temp;
        }
        else if (to_delete->Right == NULL && to_delete->Left != NULL) {
            if (parent != NULL) {
                if (parent->Left == to_delete)
                    parent->Left = to_delete->Left;
                else
                    parent->Right = to_delete->Left;
            }
            node* temp = to_delete->Left;
            free(to_delete);
            return temp;
        }
        else {
            node* max_node = NULL;
            to_delete->Left = FindMaxNode(to_delete->Left, &max_node);
            max_node->Right = to_delete->Right;
            max_node->Left = to_delete->Left;
            if (parent != NULL) {
                if (parent->Left == to_delete)
                    parent->Left = max_node;
                else
                    parent->Right = max_node;
            }
            free(to_delete);
            return root;
        }
    }

    if (data < root->data)
        root->Left = DeleteNode(root->Left, data);
    else
        root->Right = DeleteNode(root->Right, data);

    return root;
}
