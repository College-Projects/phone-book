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

typedef struct Contac{
 char first_name[10];
 char last_name[10];
 char phone_number[15];
 char address[40];
 char mail[30];
}contac; //without t

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
/*void pop(stack *ptrs);*/
void delet(stack *ps,stack *ps2);
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

void StackSize(stack *ptrs);

void addContact();

void SaveData(stack *ps);
void LoadData(stack *ps);
void Delete();
void DeleteContact(stack *ps,char dfn[],char dln[]);

contac c1;
contact *pe;
stack contacts;
FILE *fp;

void main(){
puts("\t\t\t\t\tWelcome to your phone book\n");
InitializeStack(&contacts);
if(fp=fopen("8.dat","rb"))
            LoadData(&contacts);
//LoadToStack(&contacts);
menu();
}

void menu(){
int choice;
printf("***************\n\n");
puts("[1] To add a new contact \n[2] To list your contacts \n[3] To delete The last contact you added  \n[4] To search for a contact  \n[5] To clear your phone book  \n[6] To know how many contacts you have in your phone book \n[7] To Delete a specific Contact \n[8] To Exit The program\n");
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
    Delete();
case 8:
    SaveData(&contacts);
    exit(0);
    break;
default:
    puts("Enter 1 to 8 only");
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
/*Saving the contact information to the file(without the pointer next of course)*/
/*fp=fopen("8.dat","ab");
strcpy(c1.first_name,fn);
strcpy(c1.last_name,ln);
strcpy(c1.phone_number,pn);
strcpy(c1.address,add);
strcpy(c1.mail,ml);
fwrite(&c1,sizeof(c1),1,fp);
fclose(fp);*/
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

void StackSize(stack *ptrs){
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


/*void delet(stack *ps, stack *ps2)
{
 contact*temp;
char dfname[31],dlname[31];
int find=0;
char ch;
	system("cls"); //clrscr();
    printf("\nPhone Book<::>Delete Contacts");
    printf("\n--------------------------------------------------------------------------------");
	printf ("\n::Enter data of the contact that you want delete it,please:");
	printf("\n\n  ::Enter first name: ");
	fflush(stdin);
	gets(dfname);
	printf("\n  ::Enter last name: ");
	fflush(stdin);
	gets(dlname);

	if(!ps->top){printf("Your Phone Book Is Empty! \n"); return 0;}
for (temp=ps->top;temp;temp=temp->next){
 if (strcmp (dfname, temp->first_name)==0 && strcmp (dlname, temp->last_name)==0 )
{
    printf("\nContact found! Detail: \n");
	DisplayContact(*temp);
	printf("\n\nAre you sure you want to delete this contact?(y/n) ");
	ch=getche();
	if(ch=='y'){
contact *temp2=ps->top;
while(temp2!=temp){
        push(ps2,temp2->first_name,temp2->last_name,temp2->phone_number,temp2->address,temp2->mail);
        pop(ps);
        printf("How you doin\n");
        temp2=temp2->next;
}
pop(ps);
contact *temp3=ps2->top;
while(temp3){
    push(ps,temp3->first_name,temp3->last_name,temp3->phone_number,temp3->address,temp3->mail);
    pop(ps2);
    temp3=temp3->next;
}

   find=1;
   break;
}}
}
if (find==0)
printf("\t\t\n<<This contact dose not exist in this list or program can not delete it or you chose.>>");
else
printf("\t\t\n<<Target contact was successfully deleted from list!>>");
menu();
}*/

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
void DeleteContact(stack *ps,char dfn[],char dln[])
{
    char choice;
    contact *a,*b;
    a=ps->top;
    if(!a)
    {   printf("Your phone book is empty !\n");
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
