#include <stdio.h>
#include <string.h>

//disuruh dikasi catatan biar ga dikira copas hehe
struct Cake
{
    char Name[25];
    char Code[6];
    int stock;
    int price;
};


int main()
{
    struct Cake Kue[4];
    int choice_main;
    char Code_search[6]; int code, qty;

    strcpy(Kue[0].Code, "CK001"); strcpy(Kue[0].Name, "Blueberry Cake"); Kue[0].stock = 13; Kue[0].price = 25000;
    strcpy(Kue[1].Code, "CK009"); strcpy(Kue[1].Name, "Chocochip Cake"); Kue[1].stock = 5; Kue[1].price = 20000;
    strcpy(Kue[2].Code, "CK017"); strcpy(Kue[2].Name, "Mayonaise Cake"); Kue[2].stock = 24; Kue[2].price = 30000;
    strcpy(Kue[3].Code, "CK023"); strcpy(Kue[3].Name, "Strawberry Shortcake"); Kue[3].stock = 7; Kue[3].price = 17500;

    while (choice_main != 3)
    {
        printf("BLUE CAKE SHOP CASHIER\n");
        printf("======================\n");
        printf("\n");
        printf("No. | Cake Code | Cake Name            | Available | Price\n");
        printf("---------------------------------------------------------------\n");
        for (int i = 0; i < 4; i++)
        {
            printf("%02d. | %-9s | %-20s | %9d | Rp. %d,-\n", i + 1, Kue[i].Code, Kue[i].Name, Kue[i].stock, Kue[i].price);
        }
        printf("---------------------------------------------------------------\n");
        printf("Menu :\n");
        printf("1. Sell\n");
        printf("2. Add Stock\n");
        printf("3. Exit\n");
        printf("Input choice : "); scanf("%d", &choice_main);

        switch (choice_main)
        {
        case 1:
            do
            {
                code = -1; qty = 0;
                printf("Input Cake Code [5 chars]: "); scanf("%s", Code_search);

                for (int i = 0; i < 4; i++)
                {
                    if(strcmp(Code_search, Kue[i].Code) == 0)
                    {
                        code = i;
                        break;
                    }
                }

                if (code == -1)
                {
                    printf("\n");
                    printf("--- The Cake Code doesn't exist ---\n");
                    printf("\n");
                }
            } while (code == -1);
            
            do
            {
                printf("Input Quantity [0..%d]: ", Kue[code].stock); scanf("%d", &qty);
                if (qty > Kue[code].stock)
                {
                    printf("\n...The quantity of cake is not enough...\n");
                }
            } while (qty < 0 || qty > Kue[code].stock);
            
            printf("\n");
            printf("\n");
            printf("\n");
            printf("Total Price is : Rp %d,- x %d = Rp %d,-\n", Kue[code].price, qty, Kue[code].price * qty);

            Kue[code].stock = Kue[code].stock - qty;

            printf("--- Thank You ---\n\n");
            
            break;
        
        case 2:
            do
            {
                code = -1; qty = 0;
                printf("Input Cake Code [5 chars]: "); scanf("%s", Code_search);

                for (int i = 0; i < 4; i++)
                {
                    if(strcmp(Code_search, Kue[i].Code) == 0)
                    {
                        code = i;
                        break;
                    }
                }

                if (code == -1)
                {
                    printf("\n");
                    printf("--- The Cake Code doesn't exist ---\n");
                    printf("\n");
                }
            } while (code == -1);

            do
            {
                printf("Input Quantity [1..10]: "); scanf("%d", &qty);
            } while (qty < 1 || qty > 10);

            printf("\n");
            printf("\n");
            printf("\n");
            printf("--- Adding Stock Success ---\n\n");

            Kue[code].stock = Kue[code].stock + qty;
            break;
        default:
            break;
        }
    }
    
    
    
    return 0;   
}