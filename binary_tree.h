#ifndef binary_tree_H
#include "node.h"
node* Insert(node* root, int data);
node* Search(node* node, int data);
node* FindMaxNode(node* standard, node** max_node);
node* FindParent(node* root, node* child);
node* DeleteNode(node* root, int data);
#endif