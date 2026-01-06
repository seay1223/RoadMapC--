#include "contato.h"

Contato::Contato() {
    nome = "";
    telefone = "";
    email = "";
}

Contato::Contato(string nome, string telefone, string email)
    : nome(nome), telefone(telefone), email(email) {}
