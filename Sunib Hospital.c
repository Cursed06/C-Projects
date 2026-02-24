#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//disuruh dikasi catatan biar ga dikira copas hehe
struct node {
    char medicine[20];
    struct node* next;
};

struct node* createNode(char newData[])
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    strcpy(newNode->medicine, newData);
    newNode->next = NULL;
    return newNode;
}

void push(struct node** head, char newData[])
{
    struct node* newNode = createNode(newData);
    newNode->next = *head;
    *head = newNode;
}

void pop(struct node** head)
{
    if (*head == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

void view(struct node* head)
{
    if (head == NULL)
    {
        printf("No data in the stack\n");
    }
    else
    {
        struct node* temp = head;
        int i = 1;
        printf("\nMedicine Prescription:\n");
        while (temp != NULL)
        {
            printf("Medicine #%d: %s\n", i, temp->medicine);
            temp = temp->next;
            i++;
        }
    }
}

int main()
{
    struct node* head = NULL;
    char newData[20];
    int counter = 0;
    char choice[5];

    do
    {
        printf("Sunib Hospital\n");
        printf("==============\n\n");

        while (strcmp(newData, "done") != 0)
        {
            printf("Enter medicine name [minimum 5 medicines] ('done' to finish): "); fgets(newData, sizeof(newData), stdin); newData[strcspn(newData, "\n")] = 0;

            if (strcmp(newData, "done") == 0 && counter >= 5)
                break;
            else if (strcmp(newData, "done") == 0)
                printf("You must enter at least 5 medicines!\n");
            else
            {
                printf("Medicine %s added to the prescription\n", newData);
                push(&head, newData);
                counter++;
            }
        }

        view(head);

        printf("\nDo you want to continue? (yes/no): ");
        scanf("%s", choice);
        
        if (strcmp(choice, "yes") == 0 || strcmp(choice, "YES") == 0)
        {
            while (head != NULL)
                pop(&head);
            counter = 0;
        }

    } while (strcmp(choice, "no") != 0 && strcmp(choice, "NO") != 0);

    printf("Thank you for using Sunib Hospital's prescription system!\n");
    return 0;
}
