/* Przykładowa biblioteka do zadania Dług
 * Format pliku wejściowego: n, wartości kolejnych przywieszek. */

#include <cstdio>
#include <cstdlib>

using namespace std;

const int __MAX_N = 1000007;

int __n, __cnt;
bool __inited;
int __val[__MAX_N];

void __init() {
	if(__inited)
		return ;
	__inited = true;
	__cnt = 0;
		
	scanf("%d", &__n);
	for(int i = 1 ; i <= __n ; i++)
		scanf("%d", &__val[i]);
}

int daj_n() {
	__init();
	return __n;
}

int sprawdz(int p) {
	__init();
	__cnt++;
	return __val[p];
}

void odpowiedz(int wartosc) {
	__init();
	printf("Odpowiedz: %d, liczba zapytan: %d\n", wartosc, __cnt);
	exit(0);
}

