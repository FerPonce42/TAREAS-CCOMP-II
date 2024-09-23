#include <iostream>
using namespace std;

bool palindromo(char* p) {
    char* q = p;

    for (; *q; q++);
    q--; 

    while (p < q) {
        if (*p == ' ') {
            p++;
            continue;
        }
        if (*q == ' ') {
            q--;
            continue;
        }

        char charP = (*p >= 'A' && *p <= 'Z') ? *p + ('a' - 'A') : *p;
        char charQ = (*q >= 'A' && *q <= 'Z') ? *q + ('a' - 'A') : *q;

        if (charP != charQ) {
            return false;
        }
        p++;
        q--;
    }

    return true; 
}

int main() {
    char frase[] = "amo la paloma";
    char* p = frase;

    if (palindromo(p)) {
        cout << "ES PALINDROMO" << endl;
    } else {
        cout << "NO ES PALINDROMO" << endl;
    }

    return 0;
}
