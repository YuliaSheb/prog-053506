#include <stddef.h> 
#include <assert.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#include <stdio.h> 

typedef struct treeNode
{
    char* word; 
    int vovelsNumber; 

    struct treeNode* left; /*pointers to next nodes*/
    struct treeNode* right;

} treeNode;

bool InsertNode(treeNode** head, char* newWord, int vovels);

void TreeFree(treeNode** head);

/*Counts the number of vowels in a word*/
int CountVovels(char* word, int wordSize);

bool CheckFileExists(char* filename);

int Input(char* filename, treeNode** head);

int ResultOutput(treeNode* head);

int main()
{
    treeNode *head;
    head = NULL;
    
    Input("data.txt", &head);

    ResultOutput(head);

    TreeFree(&head);

    system("pause");
    return 0;
}

bool InsertNode(treeNode **head, char *newWord, int vovels)
{
    
    if ((*head) == NULL)
    {
        assert(((*head) = (treeNode*)malloc(sizeof(treeNode))) != NULL);

        (*head)->left = NULL;
        (*head)->right = NULL;
        (*head)->word = newWord;
        (*head)->vovelsNumber = vovels;
    }
    else
    {
        
        if(vovels >= 3)
        {
            InsertNode(&((*head)->right),newWord,vovels);
        }
        else
        {
            InsertNode(&((*head)->left),newWord,vovels);
        }
    }
    return true;
}

int CountVovels(char *word, int wordSize)
{
    int i, result = 0;
    for (i = 0; i< wordSize; i++)
    {
        if (word[i] == 'a' || word[i] == 'A' ||
            word[i] == 'e' || word[i] == 'E' ||
            word[i] == 'y' || word[i] == 'Y' || 
            word[i] == 'u' || word[i] == 'U' ||
            word[i] == 'i' || word[i] == 'I' ||
            word[i] == 'o' || word[i] == 'O')
        {
            result++;
        }
    }
    return result;
}

bool CheckFileExists(char *filename)
{
    FILE *file;
    file = fopen(filename, "r");
    if(file == NULL)
    {
        printf("There was an error opening %s\n", filename);
        return false;
    }
    fclose(file);
    return true;
}

int Input(char *filename, treeNode **head)
{
    FILE *file;
    char bufferWord[256]; 

    assert(CheckFileExists(filename) == true);
    assert((file = fopen(filename, "r")) != NULL);

    char c;
    char *wordToInsert;
    int size, i, vovels, wordsNumber = 0;
    while (!feof(file))
    {
        size = 0;
   
        while((c = fgetc(file)) != ' ' && !feof(file) && c != '.' && c != ',')
        {
            bufferWord[size] = c;
            size++;
        }
        
        assert((wordToInsert = (char*)malloc(size*sizeof(char))) != NULL);
        for (i = 0; i<size; i++)
        {
            wordToInsert[i] = bufferWord[i];
        }
        vovels = CountVovels(wordToInsert, size);
        InsertNode(head, wordToInsert, vovels);
       
        wordToInsert = NULL;
        wordsNumber++;
    }

    fclose(file);
    return wordsNumber;
}

void TreeFree(treeNode **head)
{
    if ((*head) == NULL)
    {
        return;
    }
    TreeFree(&((*head)->right));
    TreeFree(&((*head)->left));
    free(*head);
    (*head) = NULL;
}

int ResultOutput(treeNode *head)
{
    static int wordsPrinted = 0;
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        if (head->vovelsNumber>=3)
        {
            printf("Word: %s, vovels here: %d\n",head->word, head->vovelsNumber);
            wordsPrinted++;
        }
        ResultOutput(head->right);
    }
    return wordsPrinted;
}

