#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define ct 1000000007
using namespace std;

int main() {
    ifstream f("crypto.in");
    ofstream g("crypto.out");
    string k;
    string s;
    int n, l, i, j, v[26] = {0};
    f >> n >> l;
    f >> k;
    f >> s;
    // numar cate caractere distincte am in subsir
    for (i = 0; i <= l - 1; i++)
        v[s[i] - 97] = 1;
    int nr = 0;
    for (i = 0; i <= 25; i++)
          nr += v[i];
    // matrice pt programare dinamica
    vector< vector<int> > d(n + 1, vector<int>(l + 1, 0));
    d[0][0] = 1;
    // calculez coloana 0 din matrice
    for (i = 1; i <= n; i++) {
        if (k[i - 1] == '?') {
            d[i][0] = (1LL * d[i - 1][0] * nr) % ct;
        } else {
            d[i][0] = d[i - 1][0] % ct;
        }
    }
    // parcurg cheia si subsirul
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= l; j++) {
            // verific daca in cheie am ?
            if (k[i - 1] == '?') {
               d[i][j] = (d[i - 1][j - 1] + 1LL * nr * d[i - 1][j]) % ct;
            } else {
                // am alt caracter inafara de ? (caracter fixat)
                if (k[i - 1] != s[j - 1]) {
                    // daca cele 2 caractere din cheie si subsir
                    // sunt diferite,pastrez rezultatul de pe linia de sus
                    d[i][j] = d[i - 1][j] % ct;
                } else {
                    // rezultatul este suma dintre elem de pe diag principala
                    // si cel de pe linia de sus
                    d[i][j] = (d[i - 1][j - 1] + d[i - 1][j]) % ct;
                }
            }
        }
    }
    g << d[n][l] << endl;
    f.close();
    g.close();
    return 0;
}
