#include <stdio.h>

typedef struct bank
{
    char name[30];
    int accountno[10];
    int amount[20];
    int date[10];
} details;
void create();
void view();
int main()
{
    int choice;

    printf("***********Welcome to sumit bank****************\n");
    printf("1.create a new account\n");
    printf("2.view accounts\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        create();
        break;
    case 2:
        view();

        break;
    default:
        printf("Sorry this option doesnt exists");
        break;
    }
    return 0;
}

void create()
{
    FILE *new;
    new = fopen("text.txt", "a");
    details create;
    int i=0;
    printf("Enter the name: ");
    scanf("%s", create.name);
    fflush(stdin);
    printf("Enter the account no: ");
    scanf("%s", create.accountno);
    printf("Enter your amount: ");
    scanf("%s",create.amount);
    printf("Enter the date: ");
    scanf("%s", create.date);
      
    fprintf(new,"\n");
    fputs(create.name,new);
    fprintf(new,"\t\t");
    fprintf(new,"%s",create.accountno);
    fprintf(new,"\t\t");
    fprintf(new,"%s",create.amount);
    fprintf(new,"\t\t");
    fprintf(new,"%s",create.date);

}
void view()
{
    char c;
    FILE* rptr;
    rptr=fopen("text.txt","r");
     while (c!=EOF)
     {
        c=fgetc(rptr);
        printf("%c",c);
     }
     
}
