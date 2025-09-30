#include<stdio.h>
#include<stdlib.h>

struct node{
    int rollNo;
    struct node* next;
};

// Create new node
struct node* createNode(int rollNo){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->rollNo = rollNo;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertLast(struct node** head, int rollNo){
    struct node* newNode = createNode(rollNo);
    if (*head == NULL){
        *head = newNode;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

// Display List
void display(struct node* head){
    printf("Roll Numbers in Linked List: ");
    struct node *temp=head;
    while (temp != NULL){
        printf("%d", temp->rollNo);
        if (temp->next != NULL) printf(" --> ");
        temp = temp->next;
    }
    printf("\n");
}

void main(){
    struct node* head = NULL;

    insertLast(&head, 13);
    insertLast(&head, 14);
    insertLast(&head, 7);
    insertLast(&head, 42);

    display(head);
}
