#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *next;
    int val;
};

typedef struct node *Node;

Node push_node (Node node, int new_val) {
    if (node == NULL) {
        Node new_node = malloc(sizeof(struct node));
        new_node->val = new_val;
        new_node->next = NULL;
        return new_node;
    }
    node->next = push_node(node->next, new_val);
    return node;
}

void print_list (Node node) {
    if (node == NULL) {
        printf("\n");
        return;
    }
    printf("%d ", node->val);
    print_list(node->next);
}

Node reverse (Node head) {
    if (head == NULL) {
        return NULL;
    }
    Node prev = head;
    Node curr = head->next;
    prev->next = NULL;
    while (curr != NULL) {
        Node next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

int main (void) {
    int i = 0;
    Node ll = NULL;
    for (int i = 0; i < 5; i++) {
        ll = push_node(ll, i);
    }
    print_list (ll);
    ll = reverse (ll);
    print_list (ll);
    return 0;
}