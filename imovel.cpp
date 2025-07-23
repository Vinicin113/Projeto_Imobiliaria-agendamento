
#include "imovel.h"

int Imovel::nextId = 1;

Imovel::Imovel(std::string tipoStr, int propId, double lat, double lng, double preco, std::string endereco)
    : proprietarioId(propId), lat(lat), lng(lng), preco(preco), endereco(endereco) {
    
    if (tipoStr == "Casa") tipo = TipoImovel::Casa;
    else if (tipoStr == "Apartamento") tipo = TipoImovel::Apartamento;
    else tipo = TipoImovel::Terreno;

    id = nextId++;
}
