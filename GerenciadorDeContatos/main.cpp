#include <iostream>
#include <fstream>
#include <vector>
#include "contato.h"

using namespace std;

bool loginAdmin() {
    string senha;
    cout << "Senha do admin: ";
    cin >> senha;
    return senha == "admin123";
}

void cadastrarContato() {
    ofstream arq("contatos.txt", ios::app);
    Contato c;

    cout << "Nome: ";
    cin.ignore();
    getline(cin, c.nome);

    cout << "Telefone: ";
    getline(cin, c.telefone);

    cout << "Email: ";
    getline(cin, c.email);

    arq << c.nome << ";" << c.telefone << ";" << c.email << endl;
    arq.close();
}

void listarContatos() {
    ifstream arq("contatos.txt");
    string linha;

    while (getline(arq, linha)) {
        cout << linha << endl;
    }
    arq.close();
}

void removerContato() {
    ifstream arq("contatos.txt");
    vector<string> linhas;
    string nome, linha;

    cout << "Nome do contato a remover: ";
    cin.ignore();
    getline(cin, nome);

    while (getline(arq, linha)) {
        if (linha.find(nome) == string::npos) {
            linhas.push_back(linha);
        }
    }
    arq.close();

    ofstream arqOut("contatos.txt");
    for (string l : linhas)
        arqOut << l << endl;
    arqOut.close();
}

int main() {
    int opcao;

    if (!loginAdmin()) {
        cout << "Acesso negado!" << endl;
        return 0;
    }

    do {
        cout << "\n1 - Cadastrar\n2 - Remover\n3 - Ver contatos\n0 - Sair\nOpcao: ";
        cin >> opcao;

        switch (opcao) {
            case 1: cadastrarContato(); break;
            case 2: removerContato(); break;
            case 3: listarContatos(); break;
        }
    } while (opcao != 0);

    return 0;
}
