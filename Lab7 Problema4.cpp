#include <iostream>
#include <cstring>

using namespace std;

#define n 10


struct student {
	int id;
	char nume[20];
}a[n], clasa[n / 5][5], pr[n];

void perm(int i, int nr_clasa) {
	int j, f; 
	if (i == n ) { 
		cout << "\n"; 
		for (f = 0; f < n; f++) {
			cout << pr[f].id;
			cout << pr[f].nume << endl;
		}
	} else 
		for (j = 0; j < n; j++) 
			if (pr[j].id == -1) { 
				pr[j] = clasa[nr_clasa][i];
				perm(i + 1,nr_clasa); 
				pr[j].id = -1; 
			}
}

int main()
{
	int nr_elevi = n, nr_clasa = 0, id, nr_elev_clasa = 0;
	for (int i = 0; i < n; i++) {
		cout << "Introduceti elevul " << i;
		a[i].id = i;
		cin.get(a[i].nume,20);
		cin.get();
		pr[i].id = -1;
	}
	while (nr_elevi > 0) {
		cout << "Introduceti elevii in clasa " << nr_clasa << endl;
		cout << "Introduceti Id-ul elevului pe care doriti sa il introduceti in aceasta clasa: ";
		cin >> id;
		clasa[nr_clasa][nr_elev_clasa] = a[id];
		nr_elev_clasa++; 
		if (nr_elev_clasa == 5)
			nr_clasa++;
		nr_elevi--;
	}
	while (nr_clasa >= 0) {
		cout << "Permutarile pt clasa " << nr_clasa << "sunt";
		perm(0, nr_clasa);
		nr_clasa--;
	}

}
