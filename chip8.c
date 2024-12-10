#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

typedef struct stack {
    node *top;
}stack_t;

void push(stack_t *st, int val) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = st->top;
    st->top = newNode;
}

int isEmpty(stack_t *st) {
    return st->top == NULL;
}

int pop(stack_t *st) {
    if (isEmpty(st))
        return;
   int data = st->top->data;
   node *temp = st->top;
   st->top = temp->next;
   free(temp);
   return data;
}


typedef struct chip_8 {
    uint8_t mem[4096];
    stack_t stack;
}chip_8_t;

int main() {
    printf("Hello\n");
    stack_t st = {0};
    push(&st,8);
    return 0;

}
