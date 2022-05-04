#include <iostream>

using namespace std;

#define n 5
#define m 2
int a[n];

int main()
{
    for (int i = 0; i < n; i++) {
        cout << "a[" << i << "]=";
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if(a[i]!= a[j])
            cout << a[i] << " " << a[j];
            cout << endl;
        }
    }
}

