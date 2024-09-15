#include <iostream>
#include <string>

using namespace std;

// lo que le sigue de los mil
string convertir_restantes(int n, bool esMiles) {
    string texto = "";

    const char* unidadestex[] = {"", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
    const char* decenastext[] = {"", "diez", "veinte", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
    const char* centenastext[] = {"", "ciento", "doscientos", "trescientos", "cuatrocientos", "quinientos", "seiscientos", "setecientos", "ochocientos", "novecientos"};

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
        const char* casoespecial21_29[] = {"veintiuno", "veintidos", "veintitres", "veinticuatro", "veinticinco", "veintiseis", "veintisiete", "veintiocho", "veintinueve"};
        if (esMiles && n == 21) {
            texto += "veintiun";  // Caso especial
        } else {
            texto += casoespecial21_29[n - 21];
        }
    }
    // DECENAS Y UNIDADES
    else if (n >= 20) {
        texto += decenastext[n / 10];
        if (n % 10 > 0) {
            texto += " y " + string(unidadestex[n % 10]);
        }
    } else if (n > 0) {
        // Caso especial: "un" en lugar de "uno" si es seguido de "mil"
        if (n == 1 && esMiles) {
            texto += "un";
        } else {
            texto += unidadestex[n];
        }
    }

    return texto;
}

// CONVERTIDOR PRINCIPAL
string primer_convertidor(int n) {
    if (n == 0) {
        return "cero";
    }

    string texto = "";

    // MILES
    if (n >= 1000) {
        int miles = n / 1000;
        int resto = n % 1000;

        if (miles == 1) {
            texto += "mil";
        } else {
            texto += convertir_restantes(miles, true);  // `true` indica que estamos en la parte de miles
            texto += " mil";
        }

        n = resto;
    }

    // Añadimos la parte menor de 1000
    texto += convertir_restantes(n, false);  // `false` indica que ya no estamos en la parte de miles

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

    string texto = primer_convertidor(numerito);
    cout << numerito << " = " << texto << endl;

    return 0;
}