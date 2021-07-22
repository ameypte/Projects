#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void actions(int);
void See_list();
void Add_contact();
int Search_contact();
void Edit_contact();
void Delete_contact();
void Exit_Program();

struct Contact_Management_System
{ 
    // strlwr
    char name[34];
    char Id_code[20];
    char contact[11];
    char email[50];
    char address[50];
} CMS[50];

int contact_count = 0;

int main()
{
    int num;
    printf("\n********Welocome To Student Contact Management System********\n");
    while (1)
    {
        printf("\n===========================================================");
        printf("\nPress:\n[0]. Exit Program\n[1]. See list of all contact\n[2]. Add new contact\n[3]. Edit contact\n[4]. Search contact\n[5]. Delete Contact\nInput: ");
        scanf("%d", &num);

        actions(num);
    }

    return 0;
}

void actions(int n)
{
    switch (n)
    {
    case 0:
        Exit_Program();
        break;
    case 1:
        See_list();
        break;
    case 2:
        Add_contact();
        break;
    case 3:
        Edit_contact();
        break;
    case 4:
        Search_contact();
        break;
    case 5:
        Delete_contact();
        break;

    default:
        break;
    }
}

void See_list()
{
    if (contact_count == 0)
    {
        printf("Please add Student Contact Details...\n");
    }

    for (int i = 0; i < contact_count; i++)
    {
        printf("\n%d. Printing the Details of %s....\n", i + 1, CMS[i].name);
        printf("\tStudent name: %s\n", CMS[i].name);
        printf("\tStudent Id Code: %s\n", CMS[i].Id_code);
        printf("\tStudent Contact No: %s\n", CMS[i].contact);
        printf("\tStudent Email: %s\n", CMS[i].email);
        printf("\tStudent Address: %s\n", CMS[i].address);
    }
}
void Add_contact()
{
    printf("Enter student name: ");
    scanf("%s", CMS[contact_count].name);

    printf("Enter student Id_code: ");
    scanf("%s", CMS[contact_count].Id_code);

    printf("Enter student Contact number: +91 ");
    scanf("%s", CMS[contact_count].contact);

    printf("Enter student Email: ");
    scanf("%s", CMS[contact_count].email);

    printf("Enter student Address: ");
    scanf("%s", CMS[contact_count].address);

    contact_count++;
}
int Search_contact()
{
    int n;
    char str[34];
search:
    printf("Press:\n[0]. Cancle Search\n[1]. Search by name\n[2]. Search by Id code\nInput: ");
    scanf("%d", &n);

    switch (n)
    {
    case 0:
        printf("Search Cancled!");
        break;
    case 1:
        printf("Enter name you want to search: ");
        scanf("%s", str);
        // lower casing the string for search
        for (int i = 0; i < contact_count; i++)
        {
            if (strcmp(str, CMS[i].name) == 0)
            {
                char choice;
                printf("%s has found in the list\nDo you want yo see the details (y/n)? ", str);
                scanf(" %c", &choice);
                if (choice == 'y' || choice == 'Y')
                {
                    printf("Printing the Details of %s....\n", CMS[i].name);
                    printf("\tStudent name: %s\n", CMS[i].name);
                    printf("\tStudent Id Code: %s\n", CMS[i].Id_code);
                    printf("\tStudent Contact No: %s\n", CMS[i].contact);
                    printf("\tStudent Email: %s\n", CMS[i].email);
                    printf("\tStudent Address: %s\n", CMS[i].address);
                    return 0;
                }
                else
                {
                    printf("\nSearch Cancled!\n");
                    return 0;
                }
            }
        }
        printf("No contact found named %s in the list!\n", str);
        return 0;
    case 2:
        printf("Enter the Idcode you want to search: ");
        scanf("%s", str);
        // lower casing the string for search
        
        for (int i = 0; i < contact_count; i++)
        {
            if (strcmp(str, CMS[i].Id_code) == 0)
            {
                char choice;
                printf("%s has found in the list\nDo you want yo see the details (y/n)? ", str);
                scanf(" %c", &choice);
                if (choice == 'y' || choice == 'Y')
                {
                    printf("Printing the Details of %s....\n", CMS[i].name);
                    printf("\tStudent name: %s\n", CMS[i].name);
                    printf("\tStudent Id Code: %s\n", CMS[i].Id_code);
                    printf("\tStudent Contact No: %s\n", CMS[i].contact);
                    printf("\tStudent Email: %s\n", CMS[i].email);
                    printf("\tStudent Address: %s\n", CMS[i].address);
                    return 0;
                }
                else
                {
                    printf("\nSearch Cancled!\n");
                    return 0;
                }
            }
        }
        printf("No contact found having Id code %s in the list!\n", str);
        return 0;

    default:
        printf("Please enter valid input!\n");
        goto search;
    }
}
void Edit_contact()
{
    int num;
    for (int i = 0; i < contact_count; i++)
    {
        printf("[%d]. %s\n",i+1,CMS[i].name);
    }
    printf("Enter the number to Edit the contact: ");
    scanf("%d",&num);
    num--;

    printf("Enter New name of %s: ",CMS[num].name);
    scanf("%s", CMS[num].name);

    printf("Enter New contact no of %s: ",CMS[num].name);
    scanf("%s", CMS[num].contact);

    printf("Enter New id code of %s: ",CMS[num].name);
    scanf("%s", CMS[num].Id_code);

    printf("Enter address of %s: ",CMS[num].name);
    scanf("%s", CMS[num].address);

    printf("Enter Email of %s: ",CMS[num].name);
    scanf("%s", CMS[num].email);

    printf("Contact edited Successfuly..");
}
void Delete_contact()
{
    int num;
    for (int i = 0; i < contact_count; i++)
    {
        printf("[%d]. %s\n",i+1,CMS[i].name);
    }
    printf("Enter the number to delete the contact: ");
    scanf("%d",&num);
    
    for (int i = num-1; i < contact_count; i++)
    {
        strcpy(CMS[i].name,CMS[i+1].name);
        strcpy(CMS[i].Id_code,CMS[i+1].Id_code);
        strcpy(CMS[i].email,CMS[i+1].email);
        strcpy(CMS[i].contact,CMS[i+1].contact);
        strcpy(CMS[i].address,CMS[i+1].address);
    }
    contact_count--;
    printf("Your contact has been deleted!");

}
void Exit_Program()
{
    exit(0);
    printf("Exiting the program...\n=======THANKU FOR USING OUR SYSTEM=======\n");
}  