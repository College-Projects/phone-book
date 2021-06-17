#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void DeleteContact(stack *ps,char dfn[],char dln[]);
void Delete();


void DeleteContact(stack *ps,char dfn[],char dln[])
{
    char choice;
    contact *a,*b;
    a=ps->top;
    if(!a)
    {   printf("List empty !\n");
    }
    else
        {
        if(strcmp(a->first_name,dfn)==0 && strcmp(a->last_name,dln)==0)
        {
            puts("Contact Found!\n");
            DisplayContact(*a);
            puts("\n\nAre you sure you want to delete this contact");
            fflush(stdin);
            scanf("%c",&choice);

            if(choice=='y'){

            ps->top=a->next;
            free(a);
            ps->size--;
            printf("Contact deleted successfully !\n");

            }
            else{puts("You chose not to delete this contact\n");}
        }
        else
        {
        a=a->next;
        b=ps->top;
        while(a)
        {
            if(!(strcmp(a->first_name,dfn)==0 && strcmp(a->last_name,dln)==0))
            {
                a=a->next;
                b=b->next;
            }
            else if(strcmp(a->first_name,dfn)==0 && strcmp(a->last_name,dln)==0)
                break;
        }
        if(!a)
        {
            printf("Contact not found!\n");
        }
        else if(strcmp(a->first_name,dfn)==0 && strcmp(a->last_name,dln)==0)
        {
            puts("Contact Found!\n");
            DisplayContact(*a);
            puts("\n\nAre you sure you want to delete this contact");
            fflush(stdin);
            scanf("%c",&choice);
            if(choice=='y'){
            b->next=a->next;
            free(a);
            ps->size--;
            printf("Contact deleted successfully\n");
                }
            else{puts("You chose not to delete the contact");}
        }
        }
    }
    SaveData(ps);
    LoadData(ps);
    menu();
}
void Delete(){
    char dfn[10], dln[10];
    puts("Enter the first name of the contact you want to delete: ");
    fflush(stdin);
    gets(dfn);
    puts("Enter the last name of the contact you want to delete: ");
    fflush(stdin);
    gets(dln);
    DeleteContact(&contacts,dfn,dln);
}
