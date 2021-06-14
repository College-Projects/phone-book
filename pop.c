#include<stdio.h>
#include<stdlib.h>
#include<string.h>



//precondition: The stack exists and it is not empty
//postcondition: The item at the top of the stack is removed and returned in *ptrs

  void pop(stack *ptrs);

//pop(&variable,&s);


void pop(stack *ptrs){
if(!ptrs->top){
printf("Your phone book is empty, you have nothing to delete\n");
}
else{
contact *temp;
temp=ptrs->top;
ptrs->top=temp->next;
pe=temp;
free(temp);
ptrs->size--;
menu();
}
}
