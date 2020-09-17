# Gra w lewo i prawo
Dostępna pamięć: 64MB

Bajtomirek gra w grę planszową, w której pionek porusza się po jednowymiarowej planszy. Każde pole jest numerowane kolejnymi liczbami naturalnymi, pierwsze po lewo ma numer 1, ostatnie po prawo n. Bajtomirek może w dowolnej kolejności wykonywać na przemian jeden z dwóch ruchów: pionek może przesunąć się w prawo o dowolną parzystą liczbę pól lub może przesunąć się w lewo o dowolną nieparzystą liczbę pól. Bajtomirek zastanawia się teraz, ile minimalnie takich ruchów musi wykonać, aby przesunąćsię z pola o numerze a na pole o numerze b. Czy potrafisz mu pomóc? Możesz założyć, że zawsze da się wykonać ruch pionkiem.
### Wejście
W  pierwszym i jedynym wierszu wejścia znajduje się trzy liczby naturalne n, a i b – odpowiednio rozmiar planszy oraz numery pola startowego i końcowego (1 ≤ n ≤ 106, 1 ≤ a, b ≤ n, a ≠ b).
### Wyjście
Jedyny wiersz wyjścia zawiera jedną liczbą całkowitą: minimalną liczbę ruchów do wykonania.
### Przykład
Wejście
```
20 2 5
```
Wyjście
```
2
```
### Wyjaśnienie
Bajtomirek w jednym ruchu może iść w prawo o 10 i w lewo o 7.
