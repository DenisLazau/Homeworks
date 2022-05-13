// Problema1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*1. Să se realizeze un program interactiv care implementează metodele de sortare avansate prezentate în această lucrare. 
Programul va prezenta următorul meniu: 
- C - iniţializează tabloul de sortat cu valori generate aleator 
- V - vizualizează tablou 
- R - reiniţializează tabloul: 
- S - sortare shellsort 
- H - sortare heapsort 
- Q- sortare quicksort 
- X - părăsirea programului. 
*/Pentru acelaşi tablou iniţial se vor evalua şi compara timpii de execuţie a diferitelor metode de sortare. 

#include <iostream>
#include <random>
#include <time.h>

using namespace std;

int a[1000], copy[1000], n;
clock_t start, stop;

void menu() {
    cout << "C - initializeaza tabloul de sortat cu valori generate aleator"<< endl;
    cout << "V - vizualizeaza tablou" << endl;
    cout << "R - reinitializeaza tablou" << endl;
    cout << "S - sortare shellsort" << endl;
    cout << "H - sortare heapsort" << endl;
    cout << "Q- sortare quicksort" << endl;
    cout << "X - parasirea programului." << endl;
}

void display() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
}

void generate() {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }

}

void gen_copy() {
    for (int i = 0; i < n; i++) {
        copie[i] = a[i];
    }
}

void reset() {
    for (int i = 0; i < n; i++)
        a[i] = copy[i];
}

int shellsort(){
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
            a[j] = temp;
        }
    }
    return 0;
}

void heapify(int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && a[l] > a[largest])
        largest = l;
    if (r < n && a[r] > a[largest])
        largest = r;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(n, largest);
    }
}

void heapSort()
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(i, 0);
    }
}

void QuickSort(int a[], int st, int dr)
{
    if (st < dr)
    {
        int m = (st + dr) / 2;
        int aux = a[st];
        a[st] = a[m];
        a[m] = aux;
        int i = st, j = dr, d = 0;
        while (i < j)
        {
            if (a[i] > a[j])
            {
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
                d = 1 - d;
            }
            i += d;
            j -= 1 - d;
        }
        QuickSort(a, st, i - 1);
        QuickSort(a, i + 1, dr);
    }
}

int main()
{
    int x = 1;
    char choice;
    cout << "Introduceti cate numere aleatoare doriti sa sortati: ";
    cin >> n;
    while (x) {
        menu();
        cout << "Alegerea voastra este: ";
        cin >> choice;
        switch (choice) {
        case 'C':
            generate();
            display();
            gen_copy();
            break;
        case 'V':
            display();
            break;
        case 'R':
            reset();
            display();
            break;
        case 'S':
            start = clock();
            shellsort();
            display();
            stop = clock();
            cout << "\n\nPentru  shellsort dureaza:  " << ((float)(stop - start)) / CLOCKS_PER_SEC;
            break;
        case 'H':
            start = clock();
            heapSort();
            display();
            stop = clock();
            cout << "\n\nPentru heapsort dureaza:  " << ((float)(stop - start)) / CLOCKS_PER_SEC;
            break;
        case 'Q':
            start = clock();
            QuickSort(a, 0, n);
            display();
            stop = clock();
            cout << "\n\nPentru quicksort dureaza:  " << ((float)(stop - start)) / CLOCKS_PER_SEC;
            break;
        case 'X':
            x = 0;
            break;
        }

    }
}
