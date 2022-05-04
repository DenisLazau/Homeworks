#include <iostream>
#include <cstring>

constexpr auto n = 5;

using namespace std;



struct Abonat {
    char nume[30];
    char adresa[50];
    char tel[10];
    int factura;
}a[n], aux;


void QuickSort(int st, int dr)
{
    if (st < dr)
    {
        int m = (st + dr) / 2;
        aux = a[st];
        a[st] = a[m];
        a[m] = aux;
        int i = st, j = dr, d = 0;
        while (i < j)
        {
            if (a[i].factura < a[j].factura)
            {
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
                d = 1 - d;
            }
            i += d;
            j -= 1 - d;
        }
        QuickSort(st, i - 1);
        QuickSort(i + 1, dr);
    }
}


int main()
{
    for (int i = 0; i < n; i++) {
        cout << "Introduceti numele persoanei " << i << " :"; 
        cin.get(a[i].nume,20);
        cin.get();
        cout << "Introduceti adresa persoanei " << i << " :";
        cin.get(a[i].adresa, 30);
        cin.get();
        cout << "Introduceti numarul de telefon persoanei " << i << " :";
        cin.get(a[i].tel, 10);
        cin.get();
        cout << "Introduceti factura persoanei " << i << " :";
        cin >> a[i].factura;
        cin.get();
    }
    QuickSort(0, n);

    for (int i = 0; i < 3; i++) {
        cout << a[i].nume << " adresa: " << a[i].adresa << "numar de telefon:" << a[i].tel << " cu factura: " << a[i].factura << endl;
    }
}
