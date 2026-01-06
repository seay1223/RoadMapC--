#ifndef CONTATO_H
#define CONTATO_H

#include <string>
using namespace std;

class Contato {
public:
    string nome;
    string telefone;
    string email;

    Contato();
    Contato(string nome, string telefone, string email);
};

#endif
