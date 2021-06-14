#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 typedef struct Contact{
 char first_name[10];
 char last_name[10];
 char phone_number[15];
 char address[40];
 char mail[30];
 struct contact *next;
 }contact;
 contact *pe;

typedef struct Stack{
contact *top;
int size;
}stack;

void InitializeStack(stack *ptrs){
ptrs->top=NULL;
ptrs->size=0;
}

void ClearStack(stack *ptrs){
contact *ptrn=ptrs->top;
while(ptrn){
    ptrn=ptrn->next;
    free(ptrs->top);
    ptrs->top=ptrn;
}
ptrs->size=0;
puts("Your phone book has been cleared");
menu();
}

int StackSize(stack *ptrs){
printf("your phone book have %d contacts\n", ptrs->size);
menu();
}

