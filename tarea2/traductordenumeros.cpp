#include <iostream>
#include <string>
using namespace std;

// Funciones específicas
string unidad(int num, bool esMiles = false);
string decena(int num, bool esMiles = false);
string centena(int num, bool esMiles = false);
string miles(int num);
string millones(int num);

// Función principal
string convertir_restantes(int num, bool esMiles = false) {
    if (num == 0) {
        return "";
    } else if (num < 100) {
        return decena(num, esMiles);
    } else {
        return centena(num, esMiles);
    }
}

string primer_convertidor(int num) {
    if (num == 0) {
        return "cero";
    }

    if (num >= 1000000) {
        return "FUERA DE RANGO OE"; 
    } else if (num >= 1000) {
        return miles(num);
    } else {
        return convertir_restantes(num);
    }
}

// Funciones específicas
string unidad(int num, bool esMiles) {
    if (num >= 1 && num <= 9) {
        switch (num) {
            case 1: return esMiles ? "un" : "uno";
            case 2: return "dos";
            case 3: return "tres";
            case 4: return "cuatro";
            case 5: return "cinco";
            case 6: return "seis";
            case 7: return "siete";
            case 8: return "ocho";
            case 9: return "nueve";
        }
    }
    return "";
}

string decena(int num, bool esMiles) {
    if (num >= 10 && num <= 19) {
        switch (num) {
            case 10: return "diez";
            case 11: return "once";
            case 12: return "doce";
            case 13: return "trece";
            case 14: return "catorce";
            case 15: return "quince";
            case 16: return "dieciséis";
            case 17: return "diecisiete";
            case 18: return "dieciocho";
            case 19: return "diecinueve";
        }
    } else if (num >= 20) {
        switch (num / 10) {
            case 2: return (num % 10 == 0) ? "veinte" : "veinti" + unidad(num % 10, esMiles);
            case 3: return (num % 10 == 0) ? "treinta" : "treinta y " + unidad(num % 10, esMiles);
            case 4: return (num % 10 == 0) ? "cuarenta" : "cuarenta y " + unidad(num % 10, esMiles);
            case 5: return (num % 10 == 0) ? "cincuenta" : "cincuenta y " + unidad(num % 10, esMiles);
            case 6: return (num % 10 == 0) ? "sesenta" : "sesenta y " + unidad(num % 10, esMiles);
            case 7: return (num % 10 == 0) ? "setenta" : "setenta y " + unidad(num % 10, esMiles);
            case 8: return (num % 10 == 0) ? "ochenta" : "ochenta y " + unidad(num % 10, esMiles);
            case 9: return (num % 10 == 0) ? "noventa" : "noventa y " + unidad(num % 10, esMiles);
        }
    } else {
        return unidad(num, esMiles);
    }
    return "";
}

string centena(int num, bool esMiles) {
    if (num >= 100) {
        switch (num / 100) {
            case 1: return (num % 100 == 0) ? "cien" : "ciento " + decena(num % 100, esMiles);
            case 2: return "doscientos " + decena(num % 100, esMiles);
            case 3: return "trescientos " + decena(num % 100, esMiles);
            case 4: return "cuatrocientos " + decena(num % 100, esMiles);
            case 5: return "quinientos " + decena(num % 100, esMiles);
            case 6: return "seiscientos " + decena(num % 100, esMiles);
            case 7: return "setecientos " + decena(num % 100, esMiles);
            case 8: return "ochocientos " + decena(num % 100, esMiles);
            case 9: return "novecientos " + decena(num % 100, esMiles);
        }
    } else {
        return decena(num, esMiles);
    }
    return "";
}

string miles(int num) {
    if (num >= 1000) {
        int miles = num / 1000;
        int resto = num % 1000;

        string milesTexto;
        if (miles == 1) {
            milesTexto = "mil";  
        } else {
            milesTexto = centena(miles, true) + " mil";  
        }

        if (resto > 0) {
            milesTexto += " " + centena(resto);
        }

        return milesTexto;
    } else {
        return centena(num);
    }
}


int main() {
    int numerito;
    cout << "Ingresa un numero entre 1 y 999999: ";
    cin >> numerito;

    if (numerito < 1 || numerito > 999999) {
        cout << "Ponte serio, esta fuera de rango." << endl;
        return 1;
    }

    string texto = primer_convertidor(numerito);
    cout << numerito << " = " << texto << endl;

    return 0;
}
