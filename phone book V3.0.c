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

void InitializeStack(stack *ptrs);//InitializeStack(&s);

void menu();

//precondition: The stack exists and is initialized
//postcondition: The argument item has been stored at the top of the stack
void push(stack *ptrs,char fn[],char ln[],char pn[],char add[],char ml[] );
//push(element,&s);

//precondition: The stack exists and it is not empty
//postcondition: The item at the top of the stack is removed and returned in *ptre
void pop(stack *ptrs);
//pop(&variable,&s);

//returns 1 if the stack is empty and 0 if not empty
int StackEmpty(stack *ptrs);//StackEmpty(&s);

//precondition: The stack exists
//postcondition: All elements are freed
void ClearStack(stack *ptrs);

/*like map in python,takes the address of a stack and address of a function
and applies the function to all the elements of the stack*/
//precondition: The Stack exists
//postcondition: The function is passed to process every stack element
void TraverseStack(stack *ptrs,void(*ptrf)(contact));

int StackSize(stack *ptrs);

void addContact();

stack contacts;
FILE *fp;

void main(){
puts("\t\t\t\t\tWelcome to your phone book\n");
InitializeStack(&contacts);
//LoadToStack(&contacts);
menu();
}

void menu(){
int choice;
printf("***************\n\n");
puts("To add a new contact, press 1 \nTo list your contacts, press 2\nTo delete The last contact you added, press 3 \nTo search for a contact press, 4 \nTo clear your phone book, press 5\nTo know how many contacts you have in your phone book, press 6\nTo Exit the program, press 7");
printf("***************\n");
scanf("%d", &choice);
switch(choice){
case 1:
    addContact();
    break;
case 2:
    listContacts();
    break;
case 3:
    pop(&contacts);
    break;
case 4:
    searchContacts();
    break;
case 5:
    ClearStack(&contacts);
    break;
case 6:
    StackSize(&contacts);
    break;
case 7:
    exit(0);
    break;
default:
    puts("Enter 1 to 7 only");
    menu();
}
}

void InitializeStack(stack *ptrs){
ptrs->top=NULL;
ptrs->size=0;
}
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
fp = fopen("contacts.txt","a");
fprintf(fp,"%s %s %s %s %s", fn, ln, pn, add, ml);
fclose(fp);
}
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
void TraverseStack(stack *ptrs,void(*ptrf)(contact)){
contact *ptrn=ptrs->top;
while(ptrn){
    (*ptrf)(*ptrn);
    ptrn=ptrn->next;
}
}

int StackEmpty(stack *ptrs){
return ptrs->top==NULL;
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

void DisplayContact(contact x){
printf("***************\n");
printf("First Name: ");
puts(x.first_name);
printf("Last Name: ");
puts(x.last_name);
printf("Phone Number: ");
puts(x.phone_number);
printf("Address: ");
puts(x.address);
printf("Email: ");
puts(x.mail);
printf("***************\n");
}

void listContacts(){
TraverseStack(&contacts,&DisplayContact);
menu();
}

void Search(stack *ps,char fn[]){
    contact *temp;
    int x=0;
    if(!ps->top)
    {
        printf("Your phone book is empty!\n");
        return 0;
    }
    for(temp=ps->top;temp;temp=temp->next)
    {
        if(!strcmp(temp->first_name,fn))
            {
            printf("Contact Found\n\n");
            DisplayContact(*temp);
            x=1;
            }
    }
    if(!x)
        printf("Contact not Found\n");

}

void searchContacts(){
char word[10];
printf("Please, Enter the first name of the contact to search with: ");
fflush(stdin);
gets(word);
Search(&contacts, word);
menu();
}

/*void LoadToStack(stack *ptrs){
fp = fopen("contacts.txt","r");
contact *ptrn;
ptrn=(contact*)malloc(sizeof(contact));
ptrs->top=ptrn;
while(fscanf(fp,"%s,%s,%s,%s,%s",ptrn->first_name,ptrn->last_name,ptrn->phone_number,ptrn->address,ptrn->mail) != EOF){
ptrn=ptrn->next;
ptrn=(contact*)malloc(sizeof(contact));
ptrs->top=ptrn;
}
fclose(fp);
}*/
