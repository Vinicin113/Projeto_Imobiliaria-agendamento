
#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
public:
    int id;
    std::string nome;
    std::string telefone;

    Cliente(int id, std::string telefone, std::string nome);
};

#endif
