#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000696969;
long long P = 1000000021;

long long powers[1000005]; // potęgi P

// wypełnia tablice powers
void calcPowers() {
  powers[0]=1;
  for(int i=1;i<1000005;i++) powers[i]=powers[i-1]*P%MOD;
}

struct Node {
  long long key; // hash dzieci
  Node* left; // wskaźnik na lewe dziecko
  Node* right; // wskaźnik na prawe dziecko

  Node() : left(NULL), right(NULL) {} // konstruktor, ustawia left i right na NULL

  void createTree(int* arr, int p, int q) { // tworzy całe drzewo z podanej tablicy arr, p - najmniejszy indeks w tablicy, q - największy
    if(p==q) { // jak jestem w liściu
      key = arr[p]; // to ustawiam jego klucz
      return;
    }
    int s = (p+q)/2; // srodek przedzialu

    if(left==NULL) left = new Node(); // jak nie mam lewego dziecka to go tworzę
    left->createTree(arr,p,s); // wywołuję rekurencyjnie dla lewego poddrzewa

    // analogicznie dla prawego
    if(right==NULL) right = new Node();
    right->createTree(arr,s+1,q);


    key = (left->key * powers[q-p+1] % MOD + right->key) % MOD; // aktualizuje swój hash
  }

  void update(int pos, int x, Node* stareDrzewo, int p, int q) {
    // pozycja (indeksowana od 0), nowa wartość, wskaźnik na poprzednie drzewo, lewy zakres, prawy zakres wierzchołka
    if(p==q) { // jeżeli znalazłem liść
      key = x; // ustaw klucz na nową wartość
      return;
    }
    int s = (p+q)/2; // srodek przedziału
    if(pos<=s) { // pozycja do wstawienia znajduje się w lewej połowie
      right = stareDrzewo->right; // prawa część bez zmian
      left = new Node(); // tworzę nowe lewe dziecko
      left->update(pos,x,stareDrzewo->left,p,s); // wywołuję rekurencyjnie dla lewego
    } else { // ... w prawej połowie
      left = stareDrzewo->left; // lewa część bez zmian
      right = new Node(); // tworzę nowe prawe dziecko
      right->update(pos,x,stareDrzewo->right,s+1,q); // wywołuję rekurencyjnie dla prawego
    }
    key = (left->key * powers[q-p+1] % MOD + right->key) % MOD; // aktualizuję hash
  }
};

vector<Node*> history; // przchowuje na i-tej pozycji wskaźnik na korzeń i-tego drzewa

int n,m; // ilość pomiarów, ilość niewdzięcznych bachorów spisujących pracę domową (ilość zapytań+1)
int lv; // ilość liści (najmniejsza potęga 2 mniejsza lub równa n)
int* tab; // tablica do wczytywania
int a,b; // zmienne pomocnicze do wczytywania
vector<int> t; // tablica numerów dzieci która będzie potem posortowana i wypisana

void update(int pos, int x) { // pozycja, nowa wartość
  history.push_back(new Node()); // tworzę nowy korzeń
  history[history.size()-1]->update(pos,x,history[history.size()-2],0,lv-1);
  // dla ostatniego (przed chwilą utworzonego) korzenia wywołuję update z argumentami
  // pozycja, nowa wartość, poprzedni korzeń (2 od końca), lewy zakres, prawy zakres korzenia
}

int difference(Node*& a, Node*& b) { // 0 gdy równe, 1 gdy `a` większe, -1 gdy `b` większe
  // zakładam że oba drzewa są tej samej wielkości więc niektóre rzeczy sprawdzam tylko dla `a`
  if(a->key==b->key) return 0; // jeżeli hashe są równe zwracam 0
  if(a->left==NULL) return a->key>b->key ? 1 : -1; // jeżeli liść to zwracam który większy

  if(a->left->key != b->left->key) return difference(a->left,b->left); // jeżeli w lewym się coś różni to zwróć który jest większy w lewym
  return difference(a->right,b->right); // jeżeli nie to w prawym
}

bool cmp(const int& a, const int& b) {
  int ans = difference(history[a],history[b]);
  if(ans==0) return a<b; // jeżeli hashe są takie same to zwracam tą o mniejszym numerze
  return ans==-1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

  calcPowers();

  cin>>n>>m;
  for(lv=1;lv<n;lv*=2); // ustawiam lv
  history.push_back(NULL); //wsadzam nulla na pozycje 0 żeby numerować od 1

  tab = new int[lv];
  for(int i=0;i<n;i++) cin>>tab[i]; // wczytuje początkowe pomiary
  for(int i=n;i<lv;i++) tab[i]=0; // wypełniam reszte zerami

  history.push_back(new Node()); // tworzę korzeń dla nowego drzewa
  history[1]->createTree(tab,0,lv-1); // wypełniam drzewo wartościami z `tab`

  for(int i=1;i<m;i++) {
    cin>>a>>b;
    update(a-1,b); // a-1 bo indeksowane od 0 (patrz linia 41)
  }

  for(int i=1;i<=m;i++) t.push_back(i); // wypełniam t liczbami od 1 do m
  sort(t.begin(),t.end(),cmp); // sortuje używając tablicy history
  for(int i : t) cout<<i<<" "; // wypisywanie
}
