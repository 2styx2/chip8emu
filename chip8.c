#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// #define MAX_STACK_SIZE 48 // In bytes

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
        return -1;
   int data = st->top->data;
   node *temp = st->top;
   st->top = temp->next;
   free(temp);
   return data;
}

const uint8_t font[80] = {
    0xF0, 0x90, 0x90, 0x90, 0xF0,  // 0
    0x20, 0x60, 0x20, 0x20, 0x70,  // 1
    0xF0, 0x10, 0xF0, 0x80, 0xF0,  // 2
    0xF0, 0x10, 0xF0, 0x10, 0xF0,  // 3
    0x90, 0x90, 0xF0, 0x10, 0x10,  // 4
    0xF0, 0x80, 0xF0, 0x10, 0xF0,  // 5
    0xF0, 0x80, 0xF0, 0x90, 0xF0,  // 6
    0xF0, 0x10, 0x20, 0x40, 0x40,  // 7
    0xF0, 0x90, 0xF0, 0x90, 0xF0,  // 8
    0xF0, 0x90, 0xF0, 0x10, 0xF0,  // 9
    0xF0, 0x90, 0xF0, 0x90, 0x90,  // A
    0xE0, 0x90, 0xE0, 0x90, 0xE0,  // B
    0xF0, 0x80, 0x80, 0x80, 0xF0,  // C
    0xE0, 0x90, 0x90, 0x90, 0xE0,  // D
    0xF0, 0x80, 0xF0, 0x80, 0xF0,  // E
    0xF0, 0x80, 0xF0, 0x80, 0x80   // F
};


typedef struct chip_8 {
    uint8_t mem[4096];
    uint8_t vReg[16];
    uint16_t iReg;
    uint16_t pcReg;
    uint8_t delayT;
    uint8_t soundT;
    bool display[64*32];
    bool keypad[16];
    char *rom;
    stack_t stack;
}chip_8_t;

void init_chip_8(chip_8_t *chip_8, const char *rom){
    const uint32_t start_add = 0x200;

    chip_8->pcReg = start_add;
}

int main() {
    printf("Hello\n");
    stack_t st = {0};
    push(&st,8);
    int num = pop(&st);
    printf("num:%d\n", num);
    return 0;

}
