#include <bits/stdc++.h>
#include <iostream>
#include<fstream>
#include <algorithm>
#include <vector>
using namespace std;

// pentru fiecare element din target pana la
// elementul maxim din target calculez numarul
// de operatii minime pentru a forma un numar
// functia intoarce un vector, valoarea fiecarui
// element din vector reprezinta nr minim de operatii
// necesare transformarii unui numar
vector<int> nr_op(vector<int> target) {
    int i, j, l;
    int ele_max = *max_element(target.begin(), target.end());
    vector<int> w(ele_max + 1);
    // cazuri de baza
    // pentru 1 nu este nevoie de nicio operatie
    w[1] = 0;
    // pentru a ajunge la 2 este necesara o singura operatie
    w[2] = 1;
    // parcurg elementele pana la cel mai mare element din target
    for (i = 3; i <= ele_max; i++) {
        w[i] = w[i - 1];
        // calculez pentru fiecare numar divizorii
        for (j = 2; j * j <= i; j++)
        // daca am gasit un divizor pt care j * j <= i
        // am nevoie si de celalalt divizor al lui i (i / j)
        // pentru a calcula nr de operatii care minimizeaza
        // obtinerea numarului
            if (i % j == 0) {
                l = i / j;
                w[i] = min(w[i], min(w[i - j], w[i - l]));
            }
        // cresc nr de operatii necesare
        w[i] += 1;
    }
    return w;
}

int main() {
    int k, n;
    ifstream fin("prinel.in");
    ofstream fout("prinel.out");
    // citire din fisier
    fin >> n >> k;
    // alocare vectori si matrice
    vector<int> target(n + 1);
    vector<int> puncte(n + 1);
    vector< vector<int> > dp(n + 1, vector<int>(k + 1, 0));

    int s1 = 0;
    int s2 = 0;
    // citire din fisier a vectorului target
    for (int i = 1; i <= n; i++) {
        fin >> target[i];
    }
    // formez vectorul de operatii
    int elem_max = *max_element(target.begin(), target.end());
    vector<int> op(elem_max + 1);
    op = nr_op(target);

    // formez vectorul de weights corespunzator valorilor din target
    vector<int> weights(n + 1);
    for (int i = 1; i<= n; i++) {
        weights[i] = op[target[i]];
    }
    // citire din fisier a vectorului de puncte
    // calcularea sumei de puncte totale
    for (int i = 1; i <= n; i++) {
        fin >> puncte[i];
        s2 = s2 + puncte[i];
    }

    // calculare suma de operatii
    for (int i = 1; i <= n; i++) {
        s1 = s1 + weights[i];
    }
    // daca nr de operatii este <= k
    // se afiseaza direct punctele totale
    if (s1 <= k) {
        fout << s2;
    } else {
        // problema rucsacului din laborator
        for (int i = 0; i <= k; i++)
            dp[0][i] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = dp[i-1][j];
                if (j - weights[i] >= 0) {
                    int sol_aux = dp[i-1][j - weights[i]] + puncte[i];
                    dp[i][j] = max(dp[i][j], sol_aux);
                }
            }
        }
        fout << dp[n][k];
    }
    fin.close();
    fout.close();
    return 0;
}
