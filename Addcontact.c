#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void push(stack *ptrs,char fn[],char ln[],char pn[],char add[],char ml[] ){

contact *ptrn=(contact*)malloc(sizeof(contact));
strcpy(ptrn->first_name,fn);
strcpy(ptrn->last_name,ln);
strcpy(ptrn->phone_number,pn);
strcpy(ptrn->address,add);
strcpy(ptrn->mail,ml);
ptrn->next=ptrs->top;
ptrs->top=ptrn;
ptrs->size++;
}
void addContact(){
 char fn[10];
 char ln[10];
 char pn[15];
 char add[40];
 char ml[30];
printf("Enter first name: ");
fflush(stdin);
gets(fn);
fflush(stdin);
printf("Enter last name: ");
fflush(stdin);
gets(ln);
fflush(stdin);
printf("Enter phone number: ");
fflush(stdin);
gets(pn);
fflush(stdin);
printf("Enter address: ");
fflush(stdin);
gets(add);
fflush(stdin);
printf("Enter Email: ");
fflush(stdin);
gets(ml);
fflush(stdin);
push(&contacts,fn,ln,pn,add,ml);
printf("***************\n");
puts("A contact has been added");
printf("***************\n\n");

menu();
}
