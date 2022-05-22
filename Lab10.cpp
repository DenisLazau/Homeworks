//Se consideră o listă dublu înlănţuită în care fiecare nod va conţine un cuvant.
//Să se sorteze aceste cuvinte în ordine alfabetică folosind algoritmul de sortare Bubblesort.

#include <iostream>
#include <conio.h> 
#include <stdio.h>
#include <cstring>
#define n 5

using namespace std;

struct list {
    char word[20];
    list* next, * prev;
};
list* start = NULL, * element;

void print_list(list* start) {
    while (start != NULL) {
        cout << start->word << '\n';
        start = start->next;
    }
}

void add_word(list* &start) {
    char word[20];
    cout << "Type the word: ";
    cin >> word;
    element = new list;
    strcpy_s(element->word, word);
    element->prev = NULL;
    element->next = start;
    
    if (start != NULL){
        start->prev = element;
    }
    start = element;
}

void sort(list* start) {
    list* rptr = new list;
    list* lptr = new list;
    int swapped;
    lptr = NULL;
    do
    {
        swapped = 0;
        rptr = start;
        while (rptr->next != lptr) {
            if (strcmp(rptr->word, rptr->next->word) > 0) {
                swap(rptr->word, rptr->next->word);
                swapped = 1;
            }
            rptr = rptr->next;
        }
        lptr = rptr;
    } while (swapped);
}

int main()
{
    for (int i = 0; i < n; i++) {
        add_word(start);
        cin.get();
    }
    sort(start);
    cout << "The list is: ";
    print_list(start);
}
