/* Przykładowe (błędne) rozwiązanie zadania Dług */
#include "dlulib.h"

int main() {
	int n = daj_n();
	int a = sprawdz(1);
	int b = sprawdz(n);
	odpowiedz(a < b ? b : a);
	
	return 0;
}
