#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000696969;
long long P = 1000000021;

long long powers[1000005];

void calcPowers() {
  powers[0]=1;
  for(int i=1;i<1000005;i++) powers[i]=powers[i-1]*P%MOD;
}

struct Node {
  long long key;
  Node* left;
  Node* right;
  int exponent; // przez P do której potęgi przemnożyć lewą część aby otrzymać hash (po ile liści zawiera każde poddrzewo)

  Node() : left(NULL), right(NULL) {}

  void createTree(int* arr, int p, int q) {
    if(p>q) return;
    if(p==q) { // jak jestem w liściu
      key = arr[p]; // to ustawiam jego klucz
      exponent=0;
      return;
    }
    int s = (p+q)/2; // srodek przedzialu

    if(left==NULL) left = new Node(); // jak nie mam lewego dziecka to go tworzę
    left->createTree(arr,p,s); // wywołuję rekurencyjnie dla lewego poddrzewa

    // analogicznie dla prawego
    if(right==NULL) right = new Node();
    right->createTree(arr,s+1,q);

    exponent = right->exponent == 0 ? 1 : right->exponent * 2;

    key = (left->key * powers[exponent] % MOD + right->key) % MOD;
  }

  void update(int pos, int x, Node* stareDrzewo, int p, int q) {
    // pozycja, nowa wartość, wskaźnik na poprzednie drzewo, lewy zakres, prawy zakres wierzchołka
    if(p==q) { // jeżeli znalazłem liść
      key = x; // ustaw klucz na nową wartość
      return;
    }
    int s = (p+q)/2; // srodek przedziału
    exponent=stareDrzewo->exponent;
    if(pos<=s) { // pozycja do wstawienia w lewej połowie
      right = stareDrzewo->right; // prawa część bez zmian
      left = new Node(); // tworzę nowe lewe dziecko
      left->update(pos,x,stareDrzewo->left,p,s); // wysołuję rekurencyjnie dla lewego
    } else { // w prawej połowie
      left = stareDrzewo->left; // lewa część bez zmian
      right = new Node(); // tworzę nowe prawe dziecko
      right->update(pos,x,stareDrzewo->right,s+1,q); // wysołuję rekurencyjnie dla prawego
    }
    key = (left->key * powers[exponent] % MOD + right->key) % MOD; // aktualizuję hash
  }
};

vector<Node*> history; // przchowuje na i-tej pozycji wskaźnik na korzeń i-tego drzewa

int n,m; // ilość pomiarów, ilość niewdzięcznych bachorów spisujących pracę domową (ilość zapytań)
int lv; // ilość liści (najmniejsza potęga 2 mniejsza lub równa n)
int* tab; // tablica do wczytywania
int a,b;
vector<int> t;

void update(int pos, int x) { // pozycja, nowa wartość
  history.push_back(new Node()); // tworzę nowy korzeń
  history[history.size()-1]->update(pos,x,history[history.size()-2],0,lv-1);
}

int difference(Node*& a, Node*& b) { // 0 gdy równe, 1 gdy `a` większe, -1 gdy `b` większe
  // zakładam że oba drzewa są tej samej wielkości więc niektóre rzeczy sprawdzam tylko dla `a`
  if(a->key==b->key) return 0; // jeżeli równe
  if(a->left==NULL) { // jeżeli liść
    if(a->key>b->key) return 1;
    return -1;
  }
  if(a->left->key != b->left->key) return difference(a->left,b->left); // jeżeli w lewym się coś różni to zwróć który jest większy w lewym
  return difference(a->right,b->right); // jeżeli nie to dla prawego
}

bool cmp(const int& a, const int& b) {
  int ans = difference(history[a],history[b]);
  if(ans==0) return a<b; // jeżeli prace są takie same to zwracam tą o mniejszym numerze
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
  for(int i=0;i<n;i++) cin>>tab[i];
  for(int i=n;i<lv;i++) tab[i]=0; // wypełniam reszte zerami

  history.push_back(new Node());
  history[1]->createTree(tab,0,lv-1);

  for(int i=1;i<m;i++) {
    cin>>a>>b;
    update(a-1,b);
  }

  for(int i=1;i<=m;i++) t.push_back(i);
  sort(t.begin(),t.end(),cmp);
  for(int i : t) cout<<i<<" ";
}
