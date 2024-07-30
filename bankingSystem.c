#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct bank
{
    char name[30];
    int accountno[10];
    int amount[20];
    int date[10];
} details;
void create();
void view();

void main()
{
repeat:
    system("cls");
    int choice;

    printf("***********Welcome to sumit bank****************\n");
    printf("1.create a new account\n");
    printf("2.view accounts\n");
    printf("3.QUIT\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        create();
        break;
    case 2:
        view();
        break;
    case 3:
        exit(0);
    default:
        goto repeat;
    }
}

void create()
{
    FILE *new;
    new = fopen("records.txt", "a");
    details create;
    int i = 0;
    printf("Enter the name: ");
    scanf("%s", create.name);
    while ((getchar()) != '\n')
        ;
    printf("Enter the account no: ");
    scanf("%s", create.accountno);
    printf("Enter your amount: ");
    scanf("%s", create.amount);
    printf("Enter the date: ");
    scanf("%s", create.date);

    fprintf(new, "\n");
    fputs(create.name, new);
    fprintf(new, "\t\t");
    fprintf(new, "%s", create.accountno);
    fprintf(new, "\t\t");
    fprintf(new, "%s", create.amount);
    fprintf(new, "\t\t");
    fprintf(new, "%s", create.date);

    fclose(new);
    printf("\nPress any key to continue...\n");
    getch();
    main();
}
void view()
{
    char c;
    FILE *rptr;
    rptr = fopen("records.txt", "r");
    while (c != EOF)
    {
        c = fgetc(rptr);
        printf("%c", c);
    }
    fclose(rptr);
    printf("\nPress any key to continue...\n");
    getch();
    main();
}
