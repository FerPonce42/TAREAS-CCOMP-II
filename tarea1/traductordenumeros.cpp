#include <iostream>
#include <string>

using namespace std;

// CONVERTIDOR:
string numero_texto(int n) {
    if (n == 0) {
        return "cero";
    }

    string texto = "";

    // Arreglos de texto para unidades, decenas y centenas.
    const char* unidadestex[] = {"", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
    const char* decenastext[] = {"", "diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
    const char* centenastext[] = {"", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};

    // MILES
    if (n >= 1000) {
        int miles = n / 1000;
        texto += (miles == 1 ? "" : numero_texto(miles)) + " mil ";
        n %= 1000;
    }

    // CENTENAS
    if (n >= 100) {
        int centenas = n / 100;
        texto += (centenas == 1 && n % 100 == 0) ? "cien" : centenastext[centenas];
        n %= 100;
        if (n > 0) {
            texto += " ";
        }
    }

    // CASOS ESPECIALES 10-19
    if (n >= 10 && n < 20) {
        const char* casoespecial[] = {"diez", "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete", "dieciocho", "diecinueve"};
        texto += casoespecial[n - 10];
    }
    // CASOS ESPECIALES 21-29
    else if (n >= 21 && n < 30) {
        const char* casoespecial21_29[] = {"veintiuno", "veintidós", "veintitrés", "veinticuatro", "veinticinco", "veintiséis", "veintisiete", "veintiocho", "veintinueve"};
        texto += casoespecial21_29[n - 21];
    }
    // DECENAS Y UNIDADES
    else if (n >= 20) {
        texto += decenastext[n / 10];
        if (n % 10 > 0) {
            texto += " y " + string(unidadestex[n % 10]);
        }
    } else if (n > 0) {
        texto += unidadestex[n];
    }

    return texto;
}

// FINALMENTE:
int main() {
    int numerito;
    cout << "Ingresa un numero entre 1 - 999999: ";
    cin >> numerito;

    if (numerito < 1 || numerito > 999999) {
        cout << "Ponte serio, esta fuera de rango." << endl;
        return 1;
    }

    string texto = numero_texto(numerito);
    cout << numerito << " = " << texto << endl;

    return 0;
}
