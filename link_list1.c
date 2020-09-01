//Link list
//Alan Wang
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 100
struct node {
    struct node *next;
    char player[MAX];
};
struct node *create_player (char name[], struct node *next);
void print_player (struct node *head);
struct node *insert_player (char name[], struct node *insertPosition);
struct node *insertAlpha (char name[], struct node *head);

int main(void) {
    struct node *head = create_player("Zion", NULL);
    head = create_player("William", head);
    head = create_player("Fang", head);
    head = create_player("Cindy", head);
    head = create_player("Bran", head);
    //insert_player("Charles", head);
    print_player(head);

    head = insertAlpha("Dean", head);
    printf("Testing insert of Dean in the list:\n");
    print_player(head);
    // free(head);
    head = insertAlpha("Asea", head);
    printf("Testing insert of Asea in the list:\n");
    print_player(head);
    // free(head);
}

struct node *create_player (char name[], struct node *next) {
    struct node *new_player = malloc(sizeof(struct node));
    if (new_player == NULL) {
        printf("Running out of the storage, not exiting\n");
        exit(1);
    }
    strcpy(new_player->player,name);
    new_player->next = next;
    return new_player;
}
void print_player (struct node *head) {
    struct node *current_player = head;
    while (current_player != NULL) {
        printf("%s\n", current_player->player);
        current_player = current_player->next;
    }
}
struct node *insert_player (char name[], struct node *insertPosition) {
    struct node *new_player = create_player(name, NULL);
    if (new_player == NULL) {
        insertPosition->next = new_player;
    }
    else {
        new_player->next = insertPosition->next;
        insertPosition->next = new_player;
    }
    return new_player;
}

struct node *insertAlpha (char name[], struct node *head) {
    struct node *prev = NULL;
    struct node *current = head;
    while (current != NULL && strcmp(name, current->player) > 0) {
        prev = current;
        current = current->next;
    }
    struct node *new_head = head;

    if (prev == NULL) {
        new_head = create_player(name, head);
        return new_head;
    }
    
    insert_player(name, prev);
    return head;
}