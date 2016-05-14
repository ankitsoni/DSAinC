//
// Created by asoni on 10/5/16.
//
#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node *start, *newnode, *ptr;

void getNode();

void input();

void createList();

void showList();

void insertFirst();

void insertAfter();

void insertLast();

void deleteFirst();

void deleteLast();

void deleteParticular();

void deleteAfter();

void showReverse();

void main() {
    int choice;
    start = NULL;
    do {
        printf(" 1 Create List \n 2 Show List \n 3 Insert First \n 4 Insert Last \n 5 Insert After \n 6 Delete First\n "
                       "7 Delete Last \n 8 Delete Particular \n 9 Delete After \n 10 Show Reverse \n 11 Exit \n");
        printf("Enter Choice\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                showList();
                break;
            case 3:
                insertFirst();
                break;
            case 4:
                insertLast();
                break;
            case 5:
                insertAfter();
                break;
            case 6:
                deleteFirst();
                break;
            case 7:
                deleteLast();
                break;
            case 8:
                deleteParticular();
                break;
            case 9:
                deleteAfter();
                break;
            case 10:
                showReverse();
                break;
            case 11:
                exit(0);
            default:
                exit(0);
        }
    } while (1);
}

void getNode() {
    newnode = (struct node *) malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("OverFlow");
        exit(0);
    }
    newnode->link = NULL;
}

void input() {
    printf("Enter Info of the newNode\n");
    scanf("%d", &newnode->info);
}

void showList() {
    if (start == NULL) {
        printf("List is Empty\n");
    } else {
        ptr = start;
        while (ptr != NULL) {
            printf("%d ", ptr->info);
            ptr = ptr->link;
        }
        printf("\n");
    }
}

void createList() {
    int choice;
    do {

        getNode();
        input();
        if (start == NULL) {
            start = newnode;
            ptr = newnode;
        } else {
            ptr->link = newnode;
            ptr = newnode;
        }
        printf("Press 1 to add more Info\n");
        scanf("%d", &choice);
    } while (choice == 1);
}

void insertFirst() {
    getNode();
    input();
    if (start == NULL) {
        start = newnode;
        ptr = newnode;
    } else {
        newnode->link = start;
        start = newnode;
    }
}

void insertLast() {
    getNode();
    input();
    ptr = start;
    while (ptr->link != NULL) {
        ptr = ptr->link;
    }
    ptr->link = newnode;
}

void insertAfter() {
    int tempInfo;
    printf("Enter Info After which to enter");
    scanf("%d", &tempInfo);
    ptr = start;
    while (ptr->info != tempInfo) {
        ptr = ptr->link;
    }
    if (ptr == NULL) {
        printf("Info not found \n");
        return;
    }
    getNode();
    input();
    newnode->link = ptr->link;
    ptr->link = newnode;
}

void deleteFirst() {
    if (start == NULL) {
        printf("No node to be deleted\n");
        return;
    }
    ptr = start->link;
    free(start);
    start = ptr;
}

void deleteLast() {
    struct node *prev;
    ptr = start;
    while (ptr->link != NULL) {
        prev = ptr;
        ptr = ptr->link;
    }
    prev->link = NULL;
    free(ptr);
}

void deleteParticular() {
    int tempInfo;
    struct node *prev;
    printf("Enter Info of node to be deleted \n");
    scanf("%d", &tempInfo);
    ptr = start;
    prev = start;
    while (ptr != NULL) {
        if (ptr->info == tempInfo) {
            break;
        }
        prev = ptr;
        ptr = ptr->link;
    }
    if (ptr == NULL) {
        printf("Info not found\n");
        return;
    }
    prev->link = ptr->link;
    free(ptr);
}

void deleteAfter(){
    int tempInfo;
    struct node* temp;
    printf("Enter info after which node to be deleted\n");
    scanf("%d",&tempInfo);
    ptr = start;
    while (ptr != NULL) {
        if (ptr->info == tempInfo) {
            break;
        }
        ptr = ptr->link;
    }
    if (ptr == NULL) {
        printf("Info not found\n");
        return;
    }
    temp = ptr->link;
    ptr->link = temp->link;
    free(temp);
}


void showReverse(){
    struct node * temp;
    temp = NULL;
    while (temp!=start){
        ptr=start;
        while (ptr->link!=temp)
            ptr = ptr->link;
        printf("%d ",ptr->info);
        temp =ptr;
    }
    printf("\n");
}






















