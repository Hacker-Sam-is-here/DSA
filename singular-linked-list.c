#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node{
    int data;
    int key;
    struct node *next;
};

struct node *head = NULL;
struct node *current = NULL;

void insertFirst(int key, int data){
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->key = key;
    link->data = data;
    link->next = head;
    head = link;
}

void printlist(){
    struct node *ptr = head;
    printf("\n[");
    while(ptr !=NULL){
        printf("(%d,%d)",ptr->key,ptr->data);
        ptr = ptr->next;
    }
    printf("]");
}

struct node* deleteFirst(){
   struct node *tempLink = head;
   head = head->next;
   return tempLink; 
}

bool isEmpty(){
    return head == NULL;
}

int length(){
    int length = 0;
    struct node *current;
    for(current = head; current!=NULL; current = current->next){
        length++;
    }
    return length;
}

struct node* find(int key){
    struct node* current = head;
    if(head == NULL){
        return NULL;
    }
    while(current->key !=key){
        if(current->next == NULL){
            return NULL;
        }
        else{
            current = current->next;
        }    
    }
    return current;
}

struct node* delete(int key){
    struct node *current = head;
    struct node *previous = NULL;
    if(head == NULL){
        return NULL;
    }
    while(current->key != key){
        if(current->next == NULL){
            return NULL;
        }
        else{
            previous = current;
            current = current->next;
        }
    }
    if(current == head){
        head = head->next;
    }
    else{
        previous->next = current->next;
    }
}

struct node* insertAtKey(int key, int data) {
    struct node *link = (struct node*) malloc(sizeof(struct node));
    link->key = key;
    link->data = data;
    
    struct node *current = head;
    struct node *previous = NULL;
    
    if(head == NULL) {
        head = link;
        link->next = NULL;
        return link;
    }
    
    while(current != NULL && current->key < key) {
        previous = current;
        current = current->next;
    }
    
    if(previous == NULL) {
        link->next = head;
        head = link;
    } else {
        link->next = current;
        previous->next = link;
    }
    
    return link;
}

void Sort(){
    int i, j, k, tempKey, tempData;
    struct node *current;
    struct node *next;
    int size = length();
    k = size;
    for(i=0; i<size - 1; i++, k--){
        current = head;
        next = head->next;
        for(j=1; j<k; j++){
            if(current->data > next->data){
                tempData = current->data;
                current->data = next->data;
                next->data = tempData;

                tempKey = current->key;
                current->key = next->key;
                next->key = tempKey;
            }
            current = current->next;
            next = next->next;
        }
    }
}

void reverse(struct node** head_ref){
    struct node* prev = NULL;
    struct node* current = *head_ref;
    struct node* next;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

int main(void){
    insertFirst(1,10);
    insertFirst(2,20);
    insertFirst(3,30);
    insertFirst(4,1);
    insertFirst(5,40);
    insertFirst(6,56);
    printlist();
    printf("\n");
    delete(1);
    printlist();
    printf("\n");
    insertAtKey(1,10);
    printlist();
    printf("\n");
    Sort();
    printlist();
    printf("\n");
    reverse(&head);
    printlist();
    printf("\n");
    struct node *foundlink = find(4);
    if(foundlink != NULL){
        printf("Found: %d %d\n",foundlink->key,foundlink->data);
    }
}