/*2. Se consideră un vector de n numere. Să se  sorteze în ordine crescătoare elementele de pe pozițiile  pare,
folosind algoritmul  shellsort, şi elementele de  pe poziţiile impare  în  ordine descrescătoare folosind algorimul heapsort. 
Să se  afişeze vectorul în noua formă. 
*/

#include <iostream>
#include <random>

using namespace std;

#define n 20

int a[n], b[n / 2], c[n / 2], j = 0, k = 0;

int shellsort() {
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = b[i];
            int j;
            for (j = i; j >= gap && b[j - gap] > temp; j -= gap)
                b[j] = b[j - gap];
            b[j] = temp;
        }
    }
    return 0;
}

void heapify(int m, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < m && c[l] > c[largest])
        largest = l;
    if (r < m && c[r] > c[largest])
        largest = r;
    if (largest != i) {
        swap(c[i], c[largest]);
        heapify(m, largest);
    }
}

void heapSort()
{
    for (int i = k / 2 - 1; i >= 0; i--)
        heapify(k, i);
    for (int i = k - 1; i > 0; i--) {
        swap(c[0], c[i]);
        heapify(i, 0);
    }
}

int main()
{
    for (int i = 0; i < n; i++) {
        a[i]= rand() % 100;
        if (i % 2 == 0) {
            b[j] = a[i];
            j++;
        }
        else {
            c[k] = a[i];
            k++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "]=" << a[i] << endl;
    }

    heapSort();
    shellsort();
    j = 0;
    k--;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            a[i] = b[j];
            j++;
        }
        else {
            a[i] = c[k];
            k--;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "]=" << a[i] << endl;
    }
    return 0;
}

