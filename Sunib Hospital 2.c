#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 1007

struct Medicine {
    char medicineID[30];
    char medicineName[51];
    char manufacturerName[26];
    char registrationNumber[11];
    char batchNumber[17];
    struct Medicine *next;
};

struct Medicine *hashTable[SIZE];
int lastID = 0;

void initializeTable() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

int getHash(char *medicineID) {
    int sum = 0;
    for (int i = 0; i < strlen(medicineID); i++) {
        sum += medicineID[i];
    }
    return sum % SIZE;
}

int validateMedicineName(char *name) {
    return (strlen(name) >= 5 && strlen(name) <= 50);
}

int validateManufacturerName(char *name) {
    int len = strlen(name);
    return (len >= 3 && len <= 25 && strstr(name, "Ltd.") == name + len - 4);
}

int validateRegistrationNumber(char *reg) {
    if (strlen(reg) != 10) return 0;
    for (int i = 0; i < 10; i++) {
        if (!isdigit(reg[i])) return 0;
    }
    return 1;
}

void generateMedicineID(char *medicineID, char *registrationNumber, char *manufacturer, char *medicineName) {
    lastID++;
    sprintf(medicineID, "M%05d-%s-%c%c", lastID, registrationNumber, toupper(manufacturer[0]), toupper(medicineName[0]));
}

void insertMedicine() {
    char name[51], manufacturer[26], reg[11], id[30];
    int batch;

    do {
        printf("Input medicine name[5-50][unique]: ");
        scanf(" %[^\n]", name);
    } while (!validateMedicineName(name));

    do {
        printf("Input manufacturer name[3-25][end with Ltd.]: ");
        scanf(" %[^\n]", manufacturer);
    } while (!validateManufacturerName(manufacturer));

    do {
        printf("Input registration No.[10 digits][numeric]: ");
        scanf("%s", reg);
    } while (!validateRegistrationNumber(reg));

    do {
        printf("Input batch/lot[>=16]: ");
        scanf("%d", &batch);
    } while (batch < 16);

    generateMedicineID(id, reg, manufacturer, name);
    int index = getHash(id);

    struct Medicine *newMed = (struct Medicine *)malloc(sizeof(struct Medicine));
    strcpy(newMed->medicineID, id);
    strcpy(newMed->medicineName, name);
    strcpy(newMed->manufacturerName, manufacturer);
    strcpy(newMed->registrationNumber, reg);
    sprintf(newMed->batchNumber, "%d", batch);
    newMed->next = hashTable[index];
    hashTable[index] = newMed;

    printf("Medicine added successfully with ID: %s\n", id);
}

void viewMedicines() {
    int found = 0;
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != NULL) {
            struct Medicine *curr = hashTable[i];
            printf("---------------------------------------------------------------------------------------------------------------------------\n");
            printf("| Medicine Id          | Medicine Name                 | Manufacturer Name      | Reg No.           | Batch/Lot Number    |\n");
            printf("---------------------------------------------------------------------------------------------------------------------------\n");
            while (curr) {
                printf("| %-20s | %-29s | %-22s | %-17s | %-19s |\n",
                       curr->medicineID, curr->medicineName, curr->manufacturerName,
                       curr->registrationNumber, curr->batchNumber);
                curr = curr->next;
                printf("---------------------------------------------------------------------------------------------------------------------------\n");
            }
            found = 1;
        }
    }
    if (!found) printf("There is no medicine(s)!\n");
}

void deleteMedicine() {
    char id[30]; 
    printf("Input Medicine ID to delete: ");
    scanf("%s", id);

    int index = getHash(id);
    struct Medicine *curr = hashTable[index], *prev = NULL;

    
    while (curr) {
        if (strcmp(curr->medicineID, id) == 0) {
            printf("Medicine Id : %s\n", curr->medicineID);
            printf("Medicine Name : %s\n", curr->medicineName);
            printf("Manufacturer Name : %s\n", curr->manufacturerName);
            printf("Registration No. : %s\n", curr->registrationNumber);
            printf("Batch/Lot : %s\n", curr->batchNumber);
            printf("Are you sure? [y|n]: ");
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'y' || confirm == 'Y') {
                if (prev) prev->next = curr->next;
                else hashTable[index] = curr->next;
                free(curr);
                printf("Medicine deleted successfully.\n");
            } else {
                printf("Deletion cancelled.\n");
            }
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    printf("Medicine not found.\n");
}

void printMenu() {
    printf("Sunib Hospital\n");
    printf("==================\n");
    printf("1. View Medicine\n");
    printf("2. Insert Medicine\n");
    printf("3. Remove Medicine\n");
    printf("4. Exit\n");
    printf("Input >> ");
}

int main() {
    int choice;
    initializeTable();
    do {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: viewMedicines(); break;
            case 2: insertMedicine(); break;
            case 3: deleteMedicine(); break;
            case 4: printf("Thank you for using this program.\n"); break;
            default: printf("Invalid choice! Enter a number between 1 and 4.\n");
        }
    } while (choice != 4);
    return 0;
}
