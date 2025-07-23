
#include "corretor.h"

int Corretor::nextId = 1;

Corretor::Corretor(std::string telefone, bool avaliador, double lat, double lng, std::string nome)
    : telefone(telefone), avaliador(avaliador), lat(lat), lng(lng), nome(nome) {
    id = nextId++;
}
