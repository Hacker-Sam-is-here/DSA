#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int size = 8;

int intArray[8];

int top = -1;

//Operation Pop
// pop the top element from the stack
// decrement the top element
// return the top element
int pop(){
    return intArray[top--];
}

//Operation Peek
// return the top element
int peek(){
    return intArray[top];
}

//Operation isEmpty
// return true if the stack is empty
bool isEmpty(){
    return top == -1;
}

//Operation isFull
// return true if the stack is full
bool isFull(){
    return top == size-1;
}

//Operation Push
// push the element to the top of the stack
// increment the top element
void push(int data){
    if(!isFull()){
        intArray[++top] = data;
    }
    else{
        printf("\nCould not insert data, Stack is full.\n");
    }
}

void main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    push(8);
    printf("\nElement at top: %d\n", peek());
    printf("\nElements: ");
    while(!isEmpty()){
        int data = pop();
        printf("%d ", data);
    }
    printf("stack full: %s\n", isFull()?"true":"false");
    printf("stack empty: %s\n", isEmpty()?"true":"false");
}