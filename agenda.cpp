
#include "agenda.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <algorithm>

constexpr double EARTH_R = 6371.0;

double haversine(double lat1, double lon1, double lat2, double lon2) {
    auto deg2rad = [](double d){ return d * M_PI / 180.0; };
    double dlat = deg2rad(lat2 - lat1);
    double dlon = deg2rad(lon2 - lon1);
    double a = std::pow(std::sin(dlat/2), 2) +
               std::cos(deg2rad(lat1)) * std::cos(deg2rad(lat2)) *
               std::pow(std::sin(dlon/2), 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));
    return EARTH_R * c;
}

void gerarAgenda(std::vector<Corretor>& corretores, std::vector<Imovel>& imoveis) {
    std::vector<Corretor*> avaliadores;
    for (auto& c : corretores)
        if (c.avaliador) avaliadores.push_back(&c);

    std::vector<std::vector<Imovel>> atribuicoes(avaliadores.size());

    std::sort(imoveis.begin(), imoveis.end(), [](const Imovel& a, const Imovel& b) {
        return a.id < b.id;
    });

    for (size_t i = 0; i < imoveis.size(); ++i) {
        atribuicoes[i % avaliadores.size()].push_back(imoveis[i]);
    }

    for (size_t i = 0; i < avaliadores.size(); ++i) {
        Corretor* c = avaliadores[i];
        auto& meusImoveis = atribuicoes[i];

        std::vector<bool> visitado(meusImoveis.size(), false);
        double atualLat = c->lat;
        double atualLng = c->lng;
        int hora = 9, minuto = 0;

        std::cout << "Corretor " << c->id << std::endl;

        for (size_t j = 0; j < meusImoveis.size(); ++j) {
            int idxMaisProximo = -1;
            double menorDist = 1e9;

            for (size_t k = 0; k < meusImoveis.size(); ++k) {
                if (!visitado[k]) {
                    double d = haversine(atualLat, atualLng, meusImoveis[k].lat, meusImoveis[k].lng);
                    if (d < menorDist) {
                        menorDist = d;
                        idxMaisProximo = k;
                    }
                }
            }

            visitado[idxMaisProximo] = true;
            double tempoDeslocamento = menorDist * 2;
            minuto += static_cast<int>(std::round(tempoDeslocamento));
            hora += minuto / 60;
            minuto %= 60;

            std::cout << std::setfill('0') << std::setw(2) << hora << ":"
                      << std::setw(2) << minuto << " Imóvel "
                      << meusImoveis[idxMaisProximo].id << std::endl;

            minuto += 60;
            hora += minuto / 60;
            minuto %= 60;

            atualLat = meusImoveis[idxMaisProximo].lat;
            atualLng = meusImoveis[idxMaisProximo].lng;
        }
        std::cout << std::endl;
    }
}
