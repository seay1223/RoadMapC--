#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <windows.h>
using namespace std;

int main() {
    ifstream arquivo("texto.txt");
    SetConsoleOutputCP(CP_UTF8);

    if (!arquivo) {
        cout << "Erro ao abrir o arquivo!\n";
        return 1;
    }

    vector<vector<char>> matriz; 
    string linha;

    int letras = 0, vogais = 0, consoantes = 0;
    int numeros = 0, especiais = 0, total = 0;

    string especiaisPermitidos = "!@#$%¨&*()_+{`^>:?<";

    while (getline(arquivo, linha)) {
        vector<char> linhaMatriz;

        for (char c : linha) {
            linhaMatriz.push_back(c);
        }

        matriz.push_back(linhaMatriz);
    }

    arquivo.close();

    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[i].size(); j++) {
            char c = matriz[i][j];
            total++;

            if (isalpha(c)) {
                letras++;
                char lower = tolower(c);

                if (lower == 'a' || lower == 'e' || lower == 'i' ||
                    lower == 'o' || lower == 'u')
                    vogais++;
                else
                    consoantes++;
            }
            else if (isdigit(c)) {
                numeros++;
            }
            else if (especiaisPermitidos.find(c) != string::npos) {
                especiais++;
            }
        }
    }

    cout << "\n--- MATRIZ DO ARQUIVO ---\n";
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[i].size(); j++) {
            cout << matriz[i][j];
        }
        cout << endl;
    }

    cout << "\n--- RESULTADO ---\n";
    cout << "Total: " << total << endl;
    cout << "Letras: " << letras << endl;
    cout << "Vogais: " << vogais << endl;
    cout << "Consoantes: " << consoantes << endl;
    cout << "Numeros: " << numeros << endl;
    cout << "Especiais: " << especiais << endl;

    return 0;
}
