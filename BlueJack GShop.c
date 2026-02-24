#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

typedef struct Node {
    char title[26];
    char genre[20];
    int stock;
    int height;
    struct Node* left;
    struct Node* right;
} Node;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* n) {
    return n ? n->height : 0;
}

Node* createNode(char* title, char* genre, int stock) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->title, title);
    strcpy(newNode->genre, genre);
    newNode->stock = stock;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

Node* rightRotate(Node* top) {
    Node* mid = top->left;
    Node* midRight = mid->right;
    mid->right = top;
    top->left = midRight;

    top->height = max(height(top->left), height(top->right)) + 1;
    mid->height = max(height(mid->left), height(mid->right)) + 1;
    return mid;
}

Node* leftRotate(Node* top) {
    Node* mid = top->right;
    Node* midLeft = mid->left;
    mid->left = top;
    top->right = midLeft;

    top->height = max(height(top->left), height(top->right)) + 1;
    mid->height = max(height(mid->left), height(mid->right)) + 1;
    return mid;
}

int getBalance(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
}

Node* search(Node* root, char* title) {
    if (!root) return NULL;
    int cmp = strcmp(title, root->title);
    if (cmp == 0) return root;
    return (cmp < 0) ? search(root->left, title) : search(root->right, title);
}

Node* insert(Node* node, char* title, char* genre, int stock) {
    if (!node) return createNode(title, genre, stock);

    int cmp = strcmp(title, node->title);
    if (cmp < 0)
        node->left = insert(node->left, title, genre, stock);
    else if (cmp > 0)
        node->right = insert(node->right, title, genre, stock);
    else
        return node; // Duplicate not allowed

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && strcmp(title, node->left->title) < 0)
        return rightRotate(node);
    if (balance < -1 && strcmp(title, node->right->title) > 0)
        return leftRotate(node);
    if (balance > 1 && strcmp(title, node->left->title) > 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && strcmp(title, node->right->title) < 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, char* title) {
    if (!root) return root;

    int cmp = strcmp(title, root->title);
    if (cmp < 0)
        root->left = deleteNode(root->left, title);
    else if (cmp > 0)
        root->right = deleteNode(root->right, title);
    else {
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        } else {
            Node* temp = minValueNode(root->right);
            strcpy(root->title, temp->title);
            strcpy(root->genre, temp->genre);
            root->stock = temp->stock;
            root->right = deleteNode(root->right, temp->title);
        }
    }

    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrder(Node* root) {
    if (root) {
        inOrder(root->left);
        printf("| %-30s | %-13s | %-10d |\n", root->title, root->genre, root->stock);
        printf("---------------------------------------------------------------\n");
        inOrder(root->right);
    }
}

int validGenre(char* genre) {
    return strcmp(genre, "Action") == 0 || strcmp(genre, "RPG") == 0 ||
           strcmp(genre, "Adventure") == 0 || strcmp(genre, "Card Game") == 0;
}

void toLower(char* str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

int main() {
    Node* root = NULL;
    int choice;

    while (1) {
        system("cls");
        printf("Bluejack GShop\n");
        printf("==============\n");
        printf("1. Insert Game\n");
        printf("2. View Game\n");
        printf("3. Update Stock\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &choice); getchar();

        if (choice == 1) {
            char title[26], genre[20];
            int stock;

            do
            {
                printf("Input game title[5-25][unique]: ");
                fgets(title, 26, stdin); title[strcspn(title, "\n")] = 0;
            } while (strlen(title) < 5 || strlen(title) > 25 || search(root, title));

            do
            {
                printf("Input game type[Action|RPG|Adventure|Card Game]: ");
                fgets(genre, 20, stdin); genre[strcspn(genre, "\n")] = 0;
            } while (!validGenre(genre));
            
            do
            {
                printf("Input game stock[>= 1]: ");
                scanf("%d", &stock); getchar();
            } while (stock < 1);

            root = insert(root, title, genre, stock);
            printf("Insert success !\n\n");

            printf("Press enter to continue...");
            getch(); continue;


        } else if (choice == 2) {
            if (!root) {
                printf("Warehouse is empty !\n\n");

                printf("Press enter to continue...");
                getch(); continue;
            } else {
                printf("Game List:\n");
                printf("---------------------------------------------------------------\n");
                printf("| Game Title                     | Game Genre    | Game Stock |\n");
                printf("---------------------------------------------------------------\n");
                inOrder(root);
            }

        } else if (choice == 3) {
            if (!root) {
                printf("Warehouse is empty!\n\n");

                printf("Press enter to continue...");
                getch(); continue;
            }

            char title[26];
            printf("Input game title: ");
            fgets(title, 26, stdin); title[strcspn(title, "\n")] = 0;
            Node* game = search(root, title);
            if (!game) {
                printf("Data not found !\n\n");

                printf("Press enter to continue...");
                getch(); continue;
            }

            printf("Current stock: %d\n\n", game->stock);

            char type[10];
            do
            {
                printf("Input update type[add|remove][case insensitive]: ");
                fgets(type, 10, stdin); type[strcspn(type, "\n")] = 0; toLower(type);
            } while (strcmp(type, "add") != 0 && strcmp(type, "remove") != 0);
            
            int qty;
            if (strcmp(type, "remove") == 0) {
                do
                {
                    printf("Input stock to remove[1-%d]: ", game->stock);
                    scanf("%d", &qty); getchar();
                } while (qty < 1 || qty > game->stock);
            
                game->stock -= qty;
                if (game->stock == 0) {
                    printf("%s is removed from the warehouse !\n", game->title);
                    root = deleteNode(root, game->title);
                } else {
                    printf("Stock updated!\n");
                }
            } else if (strcmp(type, "add") == 0) {
                

                do
                {
                    printf("Input stock to add: ");
                    scanf("%d", &qty); getchar();
                } while (qty < 1);

                game->stock += qty;
                printf("Stock updated!\n");
                
            }

        } else if (choice == 4) {
            printf("Exiting... Thank you!\n");
            break;

        } else {
            printf("Invalid choice!\n");
        }

        printf("Press any key to continue...\n");
        getch();
    }

    return 0;
}
