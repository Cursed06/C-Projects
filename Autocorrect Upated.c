#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <conio.h>

#define MAX_WORD_LEN 100
#define MAX_ALL_SUGGESTIONS 10000
#define SUGGESTION_BATCH_SIZE 3
#define MAX_EDIT_DISTANCE 2

typedef struct 
{
    char word[MAX_WORD_LEN];
    int distance;
} Suggestion;

typedef struct TrieNode 
{
    struct TrieNode* children[26];
    bool isEndOfWord;
} TrieNode;

Suggestion allSuggestions[MAX_ALL_SUGGESTIONS];
int allSuggestionCount = 0;
TrieNode* trieRoot = NULL;

TrieNode* createNode() 
{
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));

    if (node == NULL) 
    {
        perror("Failed to allocate TrieNode");
        exit(EXIT_FAILURE);
    }

    node->isEndOfWord = false;

    for (int i = 0; i < 26; i++) 
    {
        node->children[i] = NULL;
    }

    return node;
}

void insertWord(TrieNode* root, const char* word) 
{
    TrieNode* current = root;

    for (int i = 0; word[i]; i++) 
    {
        int idx = word[i] - 'a';

        if (!current->children[idx])
        {
            current->children[idx] = createNode();
        }

        current = current->children[idx];
    }

    current->isEndOfWord = true;
}

bool searchWord(TrieNode* root, const char* word) 
{
    TrieNode* current = root;

    for (int i = 0; word[i]; i++) 
    {
        int idx = word[i] - 'a';

        if (!current->children[idx])
        {
            return false;
        }

        current = current->children[idx];
    }

    return current->isEndOfWord;
}

TrieNode* findPrefixNode(TrieNode* root, const char* prefix) 
{
    TrieNode* current = root;

    for (int i = 0; prefix[i]; i++) 
    {
        int idx = prefix[i] - 'a';

        if (!current->children[idx]) 
        {
            return NULL;
        }

        current = current->children[idx];
    }

    return current;
}

void freeTrie(TrieNode* node) 
{
    if (node == NULL) return;

    for (int i = 0; i < 26; i++) 
    {
        freeTrie(node->children[i]);
    }

    free(node);
}

int compareSuggestions(const void* a, const void* b) 
{
    Suggestion* sa = (Suggestion*)a;
    Suggestion* sb = (Suggestion*)b;
    return sa->distance - sb->distance;
}

void toLowercase(char* str) 
{
    for (int i = 0; str[i]; i++) 
    {
        str[i] = tolower(str[i]);
    }
}

void printAllWordsFromPrefix(TrieNode* node, char* buffer, int depth) 
{
    if (node->isEndOfWord) 
    {
        buffer[depth] = '\0';
        printf("%s\n", buffer);
    }

    for (int i = 0; i < 26; i++) 
    {
        if (node->children[i]) 
        {
            buffer[depth] = 'a' + i;
            printAllWordsFromPrefix(node->children[i], buffer, depth + 1);
        }
    }
}

void searchTrieApproximateRecursive(TrieNode* node, const char* input, char* buffer, int depth,
                                    int* prevRow, int inputLen) 
{
    int curRow[inputLen + 1];
    curRow[0] = prevRow[0] + 1;

    for (int i = 1; i <= inputLen; i++) 
    {
        int insertCost = curRow[i - 1] + 1;
        int deleteCost = prevRow[i] + 1;
        int replaceCost = prevRow[i - 1] + (input[i - 1] != buffer[depth]);

        curRow[i] = (insertCost < deleteCost) ? insertCost : deleteCost;
        if (replaceCost < curRow[i]) 
        {
            curRow[i] = replaceCost;
        }
    }

    if (node->isEndOfWord && curRow[inputLen] <= MAX_EDIT_DISTANCE) 
    {
        buffer[depth + 1] = '\0';

        if (allSuggestionCount < MAX_ALL_SUGGESTIONS) 
        {
            strcpy(allSuggestions[allSuggestionCount].word, buffer);
            allSuggestions[allSuggestionCount].distance = curRow[inputLen];
            allSuggestionCount++;
        }
    }

    int minDist = INT_MAX;

    for (int i = 0; i <= inputLen; i++) 
    {
        if (curRow[i] < minDist) 
        {
            minDist = curRow[i];
        }
    }

    if (minDist <= MAX_EDIT_DISTANCE) 
    {
        for (int i = 0; i < 26; i++) 
        {
            if (node->children[i]) 
            {
                buffer[depth + 1] = 'a' + i;
                searchTrieApproximateRecursive(node->children[i], input, buffer, depth + 1, curRow, inputLen);
            }
        }
    }
}

void loadDictionary(const char* filename) 
{
    FILE* fp = fopen(filename, "r");
    if (!fp) 
    {
        printf("Dictionary '%s' not found.\n", filename);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LEN];

    while (fgets(word, sizeof(word), fp)) 
    {
        word[strcspn(word, "\n")] = 0;
        toLowercase(word);
        insertWord(trieRoot, word);
    }

    fclose(fp);
}

void handleAutocorrect() 
{
    char input[MAX_WORD_LEN];
    printf("Insert word: "); 
    scanf("%s", input); 
    getchar();

    toLowercase(input);

    allSuggestionCount = 0;
    char buffer[MAX_WORD_LEN];
    int inputLen = strlen(input);
    int initialRow[inputLen + 1];

    for (int i = 0; i <= inputLen; i++) 
    {
        initialRow[i] = i;
    }

    searchTrieApproximateRecursive(trieRoot, input, buffer, -1, initialRow, inputLen);

    if (allSuggestionCount == 0) 
    {
        printf("No suggestions found.\n");
        return;
    }

    qsort(allSuggestions, allSuggestionCount, sizeof(Suggestion), compareSuggestions);

    int printed = 0;
    char moreChoice;

    do 
    {
        int toPrint = (allSuggestionCount - printed) < SUGGESTION_BATCH_SIZE ? 
                      (allSuggestionCount - printed) : SUGGESTION_BATCH_SIZE;

        printf("Suggestions:\n");

        for (int i = 0; i < toPrint; i++) 
        {
            printf("%d. %s (distance: %d)\n", printed + i + 1, 
                   allSuggestions[printed + i].word, allSuggestions[printed + i].distance);
        }

        printed += toPrint;

        if (printed >= allSuggestionCount) 
        {
            printf("No more suggestions.\n");
            break;
        }
      
        while (1) 
        {
            printf("Do you want more suggestions? (y/n): ");

            char line[10];

            if (!fgets(line, sizeof(line), stdin)) 
            {
                moreChoice = 'n';
                break;
            }

            if (line[0] == 'y' || line[0] == 'Y') 
            {
                moreChoice = 'y';
                break;
            } 
            else if (line[0] == 'n' || line[0] == 'N') 
            {
                moreChoice = 'n';
                break;
            } 
            else 
            {
                printf("Please enter 'y' or 'n'.\n");
            }
        }
    } while (moreChoice == 'y' || moreChoice == 'Y');
}

void handleSearchWord() 
{
    char input[MAX_WORD_LEN];
    printf("Search word: "); 
    scanf("%s", input);
    getchar();

    toLowercase(input);

    system("cls");

    if (searchWord(trieRoot, input)) 
    {
        printf("'%s' found in dictionary.\n", input);
    } 
    else 
    {
        printf("'%s' NOT found in dictionary.\n", input);
    }
}

void handleViewWordsWithPrefix() 
{
    char prefix[MAX_WORD_LEN];
    printf("Enter prefix: "); 
    scanf("%s", prefix);
    getchar();

    toLowercase(prefix);

    TrieNode* node = findPrefixNode(trieRoot, prefix);
    if (!node) 
    {
        printf("\nNo words found with prefix '%s'.\n", prefix);
    } 
    else 
    {
        printf("\nWords with prefix '%s':\n", prefix);

        char buffer[MAX_WORD_LEN];
        
        strcpy(buffer, prefix);
        printAllWordsFromPrefix(node, buffer, strlen(prefix));
    }
}

int main() 
{
    trieRoot = createNode();
    loadDictionary("dictionary.txt");

    int choice;
    do 
    {
        system("cls");

        printf("\nBR's Autocorrect System\n");
        printf("=========================\n");
        printf("1. Autocorrect\n");
        printf("2. Search a word\n");
        printf("3. View all words with a prefix\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) 
        {
            case 1: 
            {
                handleAutocorrect();
                printf("\n\nPress Enter to continue..."); 
                getch();
                break;
            }
            case 2: 
            {
                handleSearchWord();
                printf("\n\nPress Enter to continue..."); 
                getch();
                break;
            }
            case 3: 
            {
                handleViewWordsWithPrefix();
                printf("\n\nPress Enter to continue..."); 
                getch();
                break;
            }
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                printf("\n\nPress Enter to continue..."); 
                getch();
        }
    } while (choice != 4);

    freeTrie(trieRoot);
    return 0;
}