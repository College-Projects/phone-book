#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void searchContacts(){
char word[10];
printf("Please, Enter the first name of the contact to search with: ");
fflush(stdin);
gets(word);
Search(&contacts, word);
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

