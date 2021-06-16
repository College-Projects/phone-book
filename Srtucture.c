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

typedef struct Contac{
 char first_name[10];
 char last_name[10];
 char phone_number[15];
 char address[40];
 char mail[30];
}contac; //without t
contac c1;

typedef struct Stack{
contact *top;
int size;
}stack;
stack contacts;

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

int StackEmpty(stack *ptrs){
return ptrs->top==NULL;
}
FILE *fp;

void LoadData(stack *ps)
{
    fseek(fp,0,SEEK_SET);
    while(fread(&c1,sizeof(c1),1,fp))
    {
    push(ps,c1.first_name,c1.last_name,c1.phone_number,c1.address,c1.mail);
    }
    fclose(fp);
}

void SaveData(stack *ps)
{
    contact *pn;
    if(!(fp=fopen("8.dat","wb")))
    {
        printf("Can't open The file\n");
        return 0;
    }
    else
    {
        for(pn=ps->top;pn;pn=pn->next)
        {
            strcpy(c1.first_name,pn->first_name);
            strcpy(c1.last_name,pn->last_name);
            strcpy(c1.phone_number,pn->phone_number);
            strcpy(c1.address,pn->address);
            strcpy(c1.mail,pn->mail);

            fwrite(&c1,sizeof(c1),1,fp);
        }
    }
    fclose(fp);
}
