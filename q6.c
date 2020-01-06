// Train tally
// takes input of 2 integer numbers at a time,
// the numbers representing trains arriving at a 
// station and prints the order at which 
// the trains arrive at station 3

#include <stdio.h>
#include <stdlib.h>

#define EMPTY 0
#define ERR -123456

struct station {
    int num;
    int curr;
    struct station *next;
};

struct node {
    int num;    
    struct node *next;
};

struct metadata {
    struct node *start;
};

struct station *create_stats (struct station *head);
struct station *create_stat (int stat);
struct station *update (struct station *head, struct metadata *meta, int stat, int train);

struct node *add_to_tail (struct node *head, int number);
struct node *create_node (int number);

int main (void) {
    int stat; // station number
    int train; 
    // create linked list with 3 nodes with each representing a station
    struct station *head = NULL;
    head = create_stats(head);
    // create linked list representing print order
    struct node *start = NULL;
    struct metadata *meta = malloc(sizeof(struct metadata));
    meta->start = NULL;
    // scan in number
    while (scanf("%d%d", &stat, &train) != EOF) {
        head = update(head, meta, stat, train);
    }
    // print out trains
    struct node *curr = meta->start;
    while (curr != NULL) {
        if (curr->num != ERR) {
            printf("%d\n", curr->num);
        } else {
            printf("error\n");
        }
        curr = curr->next;
    }

}

struct node *add_to_tail (struct node *head, int number) {
    if (head == NULL) {
        head = create_node(number);
        return head;
    }
    struct node *curr = head;
    struct node *prev = NULL;
    // loop to end of ll
    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = create_node(number);
    return head;
}

struct node *create_node (int number) {
    struct node *new = malloc(sizeof(struct node));
    new->next = NULL;
    new->num = number;
    return new;
}

struct station *create_stats (struct station *head) {
    head = create_stat (1);
    struct station *stat2 = create_stat(2);
    struct station *stat3 = create_stat(3);
    head->next = stat2;
    stat2->next = stat3;
    return head;
}

struct station *create_stat (int stat) {
    struct station *new = malloc(sizeof(struct station));
    new->curr = EMPTY;
    new->next = NULL;
    new->num = stat;
    return new;
}

struct station *update (struct station *head, struct metadata *meta, int stat, int train) {
    struct station *stat1 = head;
    struct station *stat2 = head->next;
    struct station *stat3 = stat2->next;
    switch (stat) {
        case 1:
            if (stat1->curr == EMPTY) {
                stat1->curr = train;
            } else {
                meta->start = add_to_tail(meta->start, ERR);
            }
            break;
        case 2:
            if (stat1->curr == train && stat2->curr == EMPTY) {
                // move train from stat1 to stat2
                stat1->curr = EMPTY;
                stat2->curr = train;
            } else {
                meta->start = add_to_tail(meta->start, ERR);
            }
            break;
        case 3:
            if (stat2->curr == train) {
                // move train from stat2 to stat3
                stat2->curr = EMPTY;
                stat3->curr = train;
                meta->start = add_to_tail(meta->start, train);
            } else {
                meta->start = add_to_tail(meta->start, ERR);
            }
            break;
        default:
            meta->start = add_to_tail(meta->start, ERR);
            break;
    }
    return head;
}