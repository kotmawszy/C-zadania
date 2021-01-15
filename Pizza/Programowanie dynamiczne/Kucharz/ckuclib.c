#include <stdio.h>

int ckuclib_ready;
int ckuclib_n, ckuclib_e;
int ckuclib_t[3][1000007];

void init() {
	if(ckuclib_ready)
		return ;
	ckuclib_ready = 1;
	
	scanf("%d %d\n", &ckuclib_n, &ckuclib_e);
	for(int i = 0 ; i < 3 ; i++)
		for(int j = 1 ; j <= ckuclib_n ; j++)
			scanf("%d", &ckuclib_t[i][j]);
}

int dajn() {
	init();
	return ckuclib_n;
}

int daje() {
	init();
	return ckuclib_n;
}

int jedno(int k) {
	init();
	return ckuclib_t[0][k];
}

int dwa(int k) {
	init();
	return ckuclib_t[1][k];
}

int polowa(int k) {
	init();
	return ckuclib_t[2][k];
}

void odpowiedz(int wynik) {
	init();
	printf("%d\n", wynik);
}

