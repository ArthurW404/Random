#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *left;
    struct node *right;
};

typedef struct node *TreeNode;

TreeNode addTree (TreeNode node, int val) {
    if (node == NULL) {
        TreeNode new_node = malloc(sizeof(struct node));
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->val = val;
        return new_node;
    }

    if (node->val > val) {
        node->left = addTree(node->left, val);
    } else {
        node->right = addTree(node->right, val);
    }
    return node;
}

void infix_print(TreeNode node) {
    if (node == NULL) {
        return;
    }
    
    infix_print(node->left);

    infix_print(node->right);

    printf("%d ", node->val);
}

main () {
    TreeNode t = addTree(NULL, 5);
    t = addTree(t, 3);
    t = addTree(t, 8);
    t = addTree(t, 1);
    t = addTree(t, 4);
    t = addTree(t, 7);
    t = addTree(t, 9);
    infix_print(t);
}