#include <iostream>
#include <string>
using namespace std;

string uni(int n);
string dec(int n);
string cen(int n);
string mil(int n);

// CONVERTIDOR:
string numero_texto(int n) {
    if (n == 0) {
        return "cero";
    }

    string texto = "";

    // Designo las condiciones.
    if (n >= 1000) {
        texto += mil(n / 1000) + " mil ";
        n %= 1000;
    }

    if (n >= 100) {
        texto += cen(n / 100);
        n %= 100;
        if (n > 0) {
            texto += " ";
        }
    }

    if (n >= 10) {
        texto += dec(n);
    } else if (n > 0) {
        texto += uni(n);
    }

    return texto;
}

// UNIDADES A TEXTO:
string uni(int n) {
    const char* unidadestex[] = {"", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
    return unidadestex[n];
}

// DECENAS A TEXTO
string dec(int n) {
    const char* decenastext[] = {"", "diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
    if (n < 20) {
        const char* casoespecial[] = {"diez", "once", "doce", "trece", "catorce", "quince", "dieciséis", "diecisiete", "dieciocho", "diecinueve"};
        return casoespecial[n - 10]; // 10-19
    } else if (n % 10 == 0) {
        return decenastext[n / 10]; // 20, 30, 40...
    } else {
        return string(decenastext[n / 10]) + " y " + uni(n % 10); // Concateno decenas y unidades
    }
}

// CENTENAS A TEXTO
string cen(int n) {
    const char* centenastext[] = {"", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};
    if (n == 100) {
        return "cien";
    }
    return centenastext[n];
}

// MILES A TEXTO
string mil(int n) {
    if (n == 1) {
        return "";
    }
    return numero_texto(n);
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
