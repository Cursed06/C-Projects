#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ORDERS 10

struct Customer 
{
    char phone[14];
    char name[30];
    char email[30];
    int points;
    struct Customer *left, *right;
};

struct Order 
{
    char drink[30];
    int quantity;
    int price;
};

int validatePhone(char *phone) 
{
    int len = strlen(phone);
    if (len < 10 || len > 13) return 0;
    for (int i = 0; i < len; i++) 
    {
        if (!isdigit(phone[i])) return 0;
    }
    return 1;
}

int validateName(char *name) 
{
    if (strlen(name) < 5 || strlen(name) > 25) return 0;
    if (strncmp(name, "Mr. ", 4) != 0 && strncmp(name, "Mrs. ", 5) != 0) return 0;
    return 1;
}

int validateEmail(char *email) 
{
    if (strlen(email) < 10 || strlen(email) > 20) return 0;
    if (strchr(email, '@') == NULL) return 0;
    if (strstr(email, ".com") == NULL && strstr(email, ".co.id") == NULL) return 0;
    return 1;
}

int validateDrink(char *drink) 
{
    if (strcmp(drink, "Cafe Latte") == 0) return 1;
    if (strcmp(drink, "Cappuccino") == 0) return 1;
    if (strcmp(drink, "Caramel Macchiato") == 0) return 1;
    if (strcmp(drink, "Cafe Mocha") == 0) return 1;
    return 0;
}

struct Customer *search(struct Customer *root, char *phone) 
{
    if (root == NULL || strcmp(phone, root->phone) == 0) return root;
    if (strcmp(phone, root->phone) < 0)
        return search(root->left, phone);
    return search(root->right, phone);
}

void registerAndProcessOrder(struct Customer **root) 
{
    char phone[14], name[30], email[30];
    int redeem, totalPrice = 0, totalPointsEarned = 0;
    struct Customer *customer;
    struct Order orders[MAX_ORDERS];
    int orderCount = 0;
    
    do {
        printf("Input phone number[10-13][numeric]: "); scanf("%s", phone);
    } while (!validatePhone(phone));

    customer = search(*root, phone);
    if (customer == NULL) 
    {
        customer = (struct Customer*) malloc(sizeof(struct Customer));
        strcpy(customer->phone, phone);
        customer->points = 10;
        customer->left = customer->right = NULL;

        getchar();

        do 
        {
            printf("Input name[5-25][Mr. | Mrs. ]: "); fgets(name, sizeof(name), stdin); name[strcspn(name, "\n")] = 0;
        } while (!validateName(name));

        do 
        {
            printf("Input email[10-20][email format]: "); scanf("%s", email);
        } while (!validateEmail(email));
        
        strcpy(customer->name, name);
        strcpy(customer->email, email);
        *root = customer;
        printf("Insert success !\n");
    }

    if (customer->points >= 25) 
    {
        char choice;
        printf("Do you want to use your points[You have %d][y/n]: ", customer->points); scanf(" %c", &choice);
    
        if (choice == 'y') 
        {
            do 
            {
                printf("How much[%d left]: ", customer->points); scanf("%d", &redeem);
            } while (redeem <= 0 || redeem % 25 != 0 || redeem > customer->points);
    
            printf("You redeemed %d points!\n", redeem);
            customer->points -= redeem;

            printf("You have %d free drink(s) left.\n", redeem / 25);
        } else 
        {
            printf("You have %d free drink(s) left.\n", 0);
        }
    }
    

    do 
    {
        do {
            printf("Input drink (Cafe Latte, Caramel Macchiato, Cappuccino, Cafe Mocha): ");
            getchar();
            fgets(orders[orderCount].drink, sizeof(orders[orderCount].drink), stdin);
            orders[orderCount].drink[strcspn(orders[orderCount].drink, "\n")] = 0;
        
        } while (!validateDrink(orders[orderCount].drink));
        

        do 
        {
            printf("Enter quantity [>= 1]: "); scanf("%d", &orders[orderCount].quantity);
        } while (orders[orderCount].quantity < 1);
        

        orders[orderCount].price = orders[orderCount].quantity * 30000;
        totalPrice += orders[orderCount].price;
        orderCount++;

        if (orderCount >= MAX_ORDERS) break;

        char more;
        do 
        {
            printf("Order more? (y/n): "); scanf(" %c", &more);
        } while (more != 'y' && more != 'n');

        if (more == 'n') break;
    } while (1);

    totalPointsEarned = (totalPrice / 50000) * 3;
    customer->points += totalPointsEarned;

    printf("\nOrder Summary:\n");
    for (int i = 0; i < orderCount; i++) 
    {
        printf("%-20s %3dx = %d\n", orders[i].drink, orders[i].quantity, orders[i].price);
    }
    printf("Total: %d\n", totalPrice);
    printf("Points Obtained: %d\n", totalPointsEarned);
}

void displayCustomers(struct Customer *root) 
{
    if (root == NULL) 
    {
        printf("There is no data!\n");
        return;
    }

    printf("| Name               | Phone Number  | Email               | Points |\n");
    printf("---------------------------------------------------------------------\n");
    
    inOrderTraversal(root);
}

void inOrderTraversal(struct Customer *root) 
{
    if (root == NULL) return;

    inOrderTraversal(root->left);

    printf("| %-18s | %-13s | %-20s | %-6d |\n", root->name, root->phone, root->email, root->points);
    printf("---------------------------------------------------------------------\n");

    inOrderTraversal(root->right);
}

void removeCustomer(struct Customer **root) 
{  
    printf("Enter phone number to remove: ");
    char phone[14];
    fgets(phone, sizeof(phone), stdin); phone[strcspn(phone, "\n")] = 0;

    if (*root == NULL) 
    {  
        printf("There is no data!\n\n");  
        return;  
    }  

    struct Customer *current = *root, *parent = NULL;  

    while (current != NULL && strcmp(current->phone, phone) != 0) 
    {  
        parent = current;  
        if (strcmp(phone, current->phone) < 0)  
            current = current->left;  
        else  
            current = current->right;  
    }  

    if (current == NULL) 
    {  
        printf("Data invalid!\n");  
        return;  
    }  

    if (current->left == NULL || current->right == NULL) 
    {  
        struct Customer *newChild = (current->left != NULL) ? current->left : current->right;  

        if (parent == NULL)  
            *root = newChild;  
        else if (parent->left == current)  
            parent->left = newChild;  
        else  
            parent->right = newChild;  

        free(current);  
    } 
    else 
    {  
        struct Customer *successor = current->right, *successorParent = current;  

        while (successor->left != NULL) 
        {  
            successorParent = successor;  
            successor = successor->left;  
        }  

        strcpy(current->phone, successor->phone);  
        strcpy(current->name, successor->name);  
        strcpy(current->email, successor->email);  
        current->points = successor->points;  

        if (successorParent->left == successor)  
            successorParent->left = successor->right;  
        else  
            successorParent->right = successor->right;  

        free(successor);  
    }  

    printf("Customer removed successfully!\n");  
}

void displayMenu() 
{
    printf("BlueBucks\n");
    printf("=================\n");
    printf("1. Process Order\n");
    printf("2. View All Customers\n");
    printf("3. Remove Customer\n");
    printf("4. Exit\n");
}

int main() 
{
    struct Customer *root = NULL;
    int choice;
    do 
    {
        displayMenu();
        printf(">> "); scanf("%d", &choice);
        getchar();

        switch (choice) 
        {
            case 1:
                registerAndProcessOrder(&root);
                break;
            case 2:
                displayCustomers(root);
                break;
            case 3:
                removeCustomer(&root);
                break;
            case 4:
                printf("Exiting system.\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}