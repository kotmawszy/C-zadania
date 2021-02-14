#include <bits/stdc++.h>
using namespace std;

int n;
string s;
string c;
int* suf;
int* lcp; // długość najdłuższego wspólnego prefiksu słowa i oraz i+1
int* index; // na której pozycji znajduje się index i w tablicy suf

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n>>s>>c;

  suf = new int[n+1];
}
