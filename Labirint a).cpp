#include <iostream> 
#include <stdio.h>    
#include <stdlib.h> 
#include <conio.h> 
using namespace std; 
#define n 5 
char m[n + 1][n + 1], copie[n + 1][n + 1];
int i, j, nr_min = 100;
div_t a, b;

void tipar() { 
	for (i = 0; i <= n; i++) {
		cout<< "       ";
		for (j = 0; j <= n; j++)  
			cout<<m[i][j];
		cout<<"\n";
	} cout<<"\n"; 
} 

void show_solution() {
	for (i = 0; i <= n; i++) {
		cout << "       ";
		for (j = 0; j <= n; j++)
			cout << copie[i][j];
		cout << "\n";
	} cout << "\n";
}

void make_copie() {
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= n; j++)
			copie[i][j] = m[i][j];
	}
}

void p(int x, int y, int nr_linii) {
	if (m[x][y] == ' ') {
		m[x][y] = '+'; 
		a = div(x, n); 
		b = div(y, n); 
		if ((a.rem == 0) || (b.rem == 0)) {
			if (nr_linii < nr_min) {
				nr_min = nr_linii;
				nr_linii = 1;
				make_copie();
			}
		}
			
		else { 
			p(x + 1, y, nr_linii + 1); 
			p(x, y + 1, nr_linii + 1);
			p(x - 1, y, nr_linii + 1);
			p(x, y - 1, nr_linii + 1);
		} 
		m[x][y] = ' ';
	}
} int main() { 
	for (i = 0; i <= n; i++)
		for (j = 0; j <= n; j++)
			m[i][j] = '*'; 
	for (j = 2; j <= 5; j++)  
		m[1][j] = ' '; 
		m[2][1] = ' ';
		m[2][2] = ' '; 
		m[2][4] = ' ';
		m[3][2] = ' '; 
		m[3][3] = ' '; 
		m[3][4] = ' '; 
		m[4][2] = ' '; 
		m[5][2] = ' '; 
		tipar();
		a = div(n, 2);
		p(a.quot, a.quot,0);
		cout << "Solutia are " << nr_min << "pasi si este: " << endl;
		show_solution();
}
