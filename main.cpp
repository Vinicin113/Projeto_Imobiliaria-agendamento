
#include <iostream>
#include <vector>
#include <string>
#include "corretor.h"
#include "cliente.h"
#include "imovel.h"
#include "agenda.h"

int main() {
    int numCorretores;
    std::cin >> numCorretores;
    std::vector<Corretor> corretores;

    for (int i = 0; i < numCorretores; ++i) {
        std::string telefone;
        int avaliador;
        double lat, lng;
        std::string nome;
        std::cin >> telefone >> avaliador >> lat >> lng;
        std::getline(std::cin >> std::ws, nome);
        corretores.emplace_back(telefone, avaliador, lat, lng, nome);
    }

    int numClientes;
    std::cin >> numClientes;
    std::vector<Cliente> clientes;
    for (int i = 0; i < numClientes; ++i) {
        std::string telefone, nome;
        std::cin >> telefone;
        std::getline(std::cin >> std::ws, nome);
        clientes.emplace_back(i + 1, telefone, nome);
    }

    int numImoveis;
    std::cin >> numImoveis;
    std::vector<Imovel> imoveis;
    for (int i = 0; i < numImoveis; ++i) {
        std::string tipo;
        int propId;
        double lat, lng, preco;
        std::string endereco;
        std::cin >> tipo >> propId >> lat >> lng >> preco;
        std::getline(std::cin >> std::ws, endereco);
        imoveis.emplace_back(tipo, propId, lat, lng, preco, endereco);
    }

    gerarAgenda(corretores, imoveis);
    return 0;
}
