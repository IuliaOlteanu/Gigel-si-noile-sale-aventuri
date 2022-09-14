#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// calculez nr de aparitii ale unei litere
// intr-un sir de caractere
int nr_aparitii(char litera, string s) {
    int nr = 0;
    for (auto i : s) {
        if (i == litera)
            nr++;
    }
    return nr;
}

// calculez ponderea unei litere intr-un sir
// de exemplu: daca litera este 'a' si sirul
// este abab ponderea este : 1 + (-1) + 1 + (-1) = 0
int calcul_pondere(char litera, string s) {
    int nr_ap = nr_aparitii(litera, s);
    return 2 * nr_ap - s.length();
}

// comparator pt sortare descrescatoare
bool comparator(int x, int y) {
    return (x > y) ? true : false;
}

// calculez cate elemente din vectorul de suma au suma pozitiva
// nr de elemente = lungimea maxima

int lungime(vector<int> v) {
    int lung = (v[0] <= 0) ? -1 : 0;
    int s = 0;
    for (auto aux : v) {
        s = s + aux;
        if (s > 0)
            lung ++;
    }
    return lung;
}


int main() {
    int n;
    vector<string> cuvinte;
    ifstream fin("statistics.in");
    ofstream fout("statistics.out");

    fin >> n;
    cuvinte.resize(n + 1);
    // citire vector de cuvinte
    for (int i = 1; i <= n; i++) {
        fin >> cuvinte[i];
    }
    vector<int> s(n);
    vector<int> rez(n);
    for (int j = 0; j <= 25; j++) {
        for (int i = 1; i <= n; i++) {
            // calculez ponderea fiecarei litere dintr-un cuvant
            s[i - 1] = calcul_pondere((char)(j + 'a'), cuvinte[i]);
        }
        // sortare descrescatoare a vectorului suma
        sort(s.begin(), s.end(), comparator);
        // adaug in vectorul rezultat nr de elemente din vectorul suma
        // pentru care suma elementelor este pozitiva
        rez.push_back(lungime(s));
    }
    // sortare descrescatoare a vectorului rezultat
    sort(rez.begin(), rez.end(), comparator);
    // solutia este maximul vectorului rezultat
    fout << rez[0] << " " << endl;

    fin.close();
    fout.close();
    return 0;
}
