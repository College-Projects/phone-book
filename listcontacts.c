#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void TraverseStack(stack *ptrs,void(*ptrf)(contact)){
contact *ptrn=ptrs->top;
while(ptrn){
    (*ptrf)(*ptrn);
    ptrn=ptrn->next;
}
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
