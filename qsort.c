
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

// --------------------------------------------------------
// STRUCT author
// --------------------------------------------------------
typedef struct author
{
    int id;
    char name[64];
} author;

//--------------------------------------------------------
// FUNCTION PROTOTYPES
//--------------------------------------------------------
int compare_ints(const void* a, const void* b);
int compare_author_id(const void* a, const void* b);
int compare_author_name(const void* a, const void* b);

void output_ints(int* data, int size);
void output_authors(author* authors, int size);

void sort_integers();
void sort_authors();

//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
void main(void)
{
    puts("-----------------");
    puts("| codedrome.com |");
    puts("| qsort         |");
    puts("-----------------\n");

    sort_integers();

    // sort_authors();
}

//--------------------------------------------------------
//
// INTEGERS
//
//--------------------------------------------------------

//--------------------------------------------------------
// FUNCTION sort_integers
//--------------------------------------------------------
void sort_integers()
{
    int data[16];
    srand(time(NULL));

    for(int i = 0; i < 16; i++)
    {
        data[i] = (rand() % 128);
    }

    puts("Unsorted");
    output_ints(data, 16);

    qsort(data, 16, sizeof(int), compare_ints);

    puts("Sorted");
    output_ints(data, 16);
}

//--------------------------------------------------------
// FUNCTION output_ints
//--------------------------------------------------------
void output_ints(int* data, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d\n", data[i]);
    }
}

//--------------------------------------------------------
// FUNCTION compare_ints
//--------------------------------------------------------
int compare_ints(const void* a, const void* b)
{
    if(*(int*)a < *(int*)b)
        return -1;
    else if(*(int*)a > *(int*)b)
        return 1;
    else
        return 0;
}

//--------------------------------------------------------
//
// AUTHORS
//
//--------------------------------------------------------

//--------------------------------------------------------
// FUNCTION sort_authors
//--------------------------------------------------------
void sort_authors()
{
    author authors[6];

    authors[0] = (author){.id = 7, .name = "Dickens, Charles"};
    authors[1] = (author){.id = 3, .name = "Stevenson, Robert Louis"};
    authors[2] = (author){.id = 9, .name = "Bronte, Emily"};
    authors[3] = (author){.id = 4, .name = "Gaskell, Elizabeth"};
    authors[4] = (author){.id = 1, .name = "Collins, Wilkie"};
    authors[5] = (author){.id = 8, .name = "Shelley, Mary"};

    puts("Unsorted");
    output_authors(authors, 6);

    qsort(authors, 6, sizeof(author), compare_author_id);
    puts("Sorted by id");
    output_authors(authors, 6);

    qsort(authors, 6, sizeof(author), compare_author_name);
    puts("Sorted by name");
    output_authors(authors, 6);
}

//--------------------------------------------------------
// FUNCTION output_authors
//--------------------------------------------------------
void output_authors(author* authors, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("id: %d name: %s\n", authors[i].id, authors[i].name);
    }
}

//--------------------------------------------------------
// FUNCTION compare_author_id
//--------------------------------------------------------
int compare_author_id(const void* a, const void* b)
{
    if(((author*)a)->id < ((author*)b)->id)
        return -1;
    else if(((author*)a)->id > ((author*)b)->id)
        return 1;
    else
        return 0;
}

//--------------------------------------------------------
// FUNCTION compare_author_name
//--------------------------------------------------------
int compare_author_name(const void* a, const void* b)
{
    return strcmp(((author*)a)->name, ((author*)b)->name);
}
