#include <iostream>
using namespace std;
#include <fstream>

// ls = linia de sus
// lj = linia de jos
// cs = coloana din stanga
// cd = coloana din dreapta
// t - tipul matricei (0 sau 1)
int  dei(int ls, int lj, int cs, int cd, int x, int y, int t) {
    // lm = linia de mijloc
    // cm = coloana de mijloc
    int lm, cm;
    if (lj - ls > 1 && cd - cs > 1) {
        // calculez linia de mijloc si coloana de mijloc
        lm = (lj + ls) / 2;
        cm = (cd + cs) / 2;
        // verific in ce cadran se afla x si y
        if (x <= lm) {
            if (y <= cm) {
                // cadran stanga sus
                return dei(ls, lm, cs, cm, x, y, t);
            } else {
                // cadran dreapta sus
                return dei(ls, lm, cm + 1, cd, x, y, t);
            }
        } else if (y <= cm) {
            // cadran stanga jos
            return dei(lm + 1, lj, cs, cm, x, y, t);
        } else {
            // cadran dreapta jos
            // este nevoie sa neg elementele matricei
            if (t == 0)
                t = 1;
            else
                t = 0;
            return dei(lm + 1, lj, cm + 1, cd, x, y, t);
        }
    } else {
            // cazul de baza cand matricei are dimensiunea 2 x 2
            if (x == lj && y == cd) {
                if (t == 0)
                    return 1;
                else
                    return 0;
            }
            return t;
    }
}

int main() {
    int n, x, y, t = 0, k;
    ifstream fin("walsh.in");
    ofstream fout("walsh.out");
    // citire date din fisier
    fin >> n >> k;
    for (int i = 1; i <= k; i++) {
        fin >> x >> y;
        // afisarea elementului de pe linia x, coloana y
        // matricea are dimensiunea n x n
        fout << dei(1, n, 1, n, x, y, t) << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
