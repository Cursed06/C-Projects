#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient 
{
    char name[26];
    int age;
    char description[100];
    char code[7];
    int priority;
    struct Patient *next;
};

struct Patient *front = NULL;

int getPriority(char *code) 
{
    if (strcmp(code, "Red") == 0)
    {
        return 3;
    } 
    if (strcmp(code, "Yellow") == 0)
    {
        return 2;
    } 
    if (strcmp(code, "Green") == 0)
    {
        return 1;
    } 
    return 0;
}

void insertPatient(char *name, int age, char *description, char *code) 
{
    struct Patient *newPatient = (struct Patient*)malloc(sizeof(struct Patient));
    if (!newPatient) 
    {
        printf("Memory allocation failed!\n");
        return;
    }

    strcpy(newPatient->name, name);
    newPatient->age = age;
    strcpy(newPatient->description, description);
    strcpy(newPatient->code, code);
    newPatient->priority = getPriority(code);
    newPatient->next = NULL;
    
    if (!front || newPatient->priority > front->priority) 
    {
        newPatient->next = front;
        front = newPatient;
    } 
    else 
    {
        struct Patient *temp = front;

        while (temp->next && temp->next->priority >= newPatient->priority) 
        {
            temp = temp->next;
        }

        newPatient->next = temp->next;
        temp->next = newPatient;
    }
    system("cls");
    printf("Patient added successfully!\n");
}

void viewPatients() 
{
    if (!front) 
    {
        printf("There is no queue yet!\n");
        return;
    }

    int counter = 1;
    struct Patient *temp = front;
    printf("\nPatient List:\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("|No  | Name                    | Age | Description                                        | Code    |\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    while (temp) 
    {
        printf("|%-3d | %-23s | %-3d | %-50s | %-7s |\n", counter, temp->name, temp->age, temp->description, temp->code);
        temp = temp->next;
        counter++;
    }
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("\n\n");
}

void nextQueue() 
{
    if (!front) 
    {
        printf("There is no queue yet!\n");
        return;
    }

    struct Patient *temp = front;
    front = front->next;
    printf("Next patient is:\n");
    printf("Name: %s\n",  temp->name);
    printf("Age: %d\n", temp->age);
    printf("Description: %s\n", temp->description);
    printf("Code: %s\n", temp->code);
    free(temp);
}

int main() 
{
    int choice;
    char name[26], description[100], code[7];
    int age, boolean;
    
    do 
    {
        printf("Bluejack Hospital\n");
        printf("=================\n");
        printf("1. Insert\n");
        printf("2. View\n");
        printf("3. Next Queue\n");
        printf("4. Exit\n");
        printf(">> "); scanf("%d", &choice);
        getchar();
        
        switch (choice) 
        {
            case 1:
                do
                {
                    printf("Input patient name [4-25]: ");
                    fgets(name, 26, stdin);
                    name[strcspn(name, "\n")] = '\0';
                } while (strlen(name) < 4 || strlen(name) > 25);
                
                do
                {
                    printf("Input patient age [>= 0]: ");
                    if (scanf("%d", &age) != 1) 
                    {
                        while (getchar() != '\n');
                        continue;
                    }
                    getchar();
                } while (age < 0);
                
                do
                {
                    printf("Input Description [>= 6 characters]: ");
                    fgets(description, 100, stdin);
                    description[strcspn(description, "\n")] = '\0';
                } while (strlen(description) < 6);
                
                do
                {
                    printf("Input code [Red|Yellow|Green]: ");
                    fgets(code, 7, stdin);
                    code[strcspn(code, "\n")] = '\0';

                    if (strcmp(code, "Red") == 0)
                    {
                        boolean = 1;
                    }
                    else if (strcmp(code, "Yellow") == 0)
                    {
                        boolean = 1;
                    }
                    else if (strcmp(code, "Green") == 0)
                    {
                        boolean = 1;
                    }
                    else
                    {
                        boolean = 0;
                        getchar();
                    }
                    
                } while (boolean != 1);
                
                insertPatient(name, age, description, code);
                
                break;
            case 2:
                viewPatients();
                break;
            case 3:
                nextQueue();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);
    
    return 0;
}
