#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define STR_SIZE 50

typedef struct {
    char isbn[STR_SIZE];
    char title[STR_SIZE];
    char author[STR_SIZE];
    int is_borrowed;
} Book;

typedef struct {
    Book books[MAX_BOOKS];
    int count;
} Library;

int find_book(Library *lib, char *isbn) {
    for (int i = 0; i < lib->count; i++) {
        if (strcmp(lib->books[i].isbn, isbn) == 0) {
            return i; // Return index if found
        }
    }
    return -1;
}

void add_book(Library *lib) {
    if (lib->count >= MAX_BOOKS) {
        printf("\n[Error] Library capacity full!\n");
        return;
    }

    char isbn[STR_SIZE];
    printf("Enter ISBN: ");
    scanf("%s", isbn);

    if (find_book(lib, isbn) != -1) {
        printf("\n[Error] Book with this ISBN already exists.\n");
        return;
    }

    strcpy(lib->books[lib->count].isbn, isbn);
    
    printf("Enter Title: ");
    scanf(" %[^\n]s", lib->books[lib->count].title); // Reads string with spaces
    
    printf("Enter Author: ");
    scanf(" %[^\n]s", lib->books[lib->count].author);

    lib->books[lib->count].is_borrowed = 0;
    lib->count++;
    
    printf("\n[Success] Book added.\n");
}

void display_books(Library *lib) {
    if (lib->count == 0) {
        printf("\nLibrary is empty.\n");
        return;
    }

    printf("\n--- Catalog ---\n");
    for (int i = 0; i < lib->count; i++) {
        printf("ISBN: %s | %s by %s [%s]\n", 
               lib->books[i].isbn, 
               lib->books[i].title, 
               lib->books[i].author, 
               lib->books[i].is_borrowed ? "Borrowed" : "Available");
    }
}

void borrow_book(Library *lib) {
    char isbn[STR_SIZE];
    printf("Enter ISBN to borrow: ");
    scanf("%s", isbn);

    int idx = find_book(lib, isbn);
    if (idx == -1) {
        printf("\n[Error] Book not found.\n");
    } else if (lib->books[idx].is_borrowed) {
        printf("\n[Error] Book is already borrowed.\n");
    } else {
        lib->books[idx].is_borrowed = 1;
        printf("\n[Success] You successfully borrowed '%s'.\n", lib->books[idx].title);
    }
}

void return_book(Library *lib) {
    char isbn[STR_SIZE];
    printf("Enter ISBN to return: ");
    scanf("%s", isbn);

    int idx = find_book(lib, isbn);
    if (idx == -1) {
        printf("\n[Error] Book not found.\n");
    } else if (!lib->books[idx].is_borrowed) {
        printf("\n[Error] Book was not borrowed.\n");
    } else {
        lib->books[idx].is_borrowed = 0;
        printf("\n[Success] You successfully returned '%s'.\n", lib->books[idx].title);
    }
}

int main() {
    Library lib = { .count = 0 };
    int choice;

    strcpy(lib.books[0].isbn, "101");
    strcpy(lib.books[0].title, "The Hobbit");
    strcpy(lib.books[0].author, "J.R.R. Tolkien");
    lib.books[0].is_borrowed = 0;
    lib.count = 1;

    while (1) {
        printf("\n1. Add Book\n2. View Catalog\n3. Borrow Book\n4. Return Book\n5. Exit\n");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid Input.\n");
            break;
        }

        switch (choice) {
            case 1: add_book(&lib); break;
            case 2: display_books(&lib); break;
            case 3: borrow_book(&lib); break;
            case 4: return_book(&lib); break;
            case 5: printf("\nGoodbye!\n"); return 0;
            default: printf("\nInvalid Choice.\n");
        }
    }
    return 0;
}
