
#ifndef IMOVEL_H
#define IMOVEL_H

#include <string>

enum class TipoImovel { Casa, Apartamento, Terreno };

class Imovel {
public:
    static int nextId;
    int id;
    TipoImovel tipo;
    int proprietarioId;
    double lat, lng;
    double preco;
    std::string endereco;

    Imovel(std::string tipoStr, int propId, double lat, double lng, double preco, std::string endereco);
};

#endif
