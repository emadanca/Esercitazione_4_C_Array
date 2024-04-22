#include <iostream>
#include "Utils.hpp"

int main() {
    std::string fileName = "data.csv";
    double S;
    int n;
    double* w;
    double* r;

    if (!leggiDati(fileName, S, n, w, r))
    {
        std::cerr << "Errore durante la lettura dei dati." << std::endl;
        return -1;
    }

    double rateOfReturn, V;
    calcolaRendimento(S, n, w, r, rateOfReturn, V);

    std::cout << "S = " << S << ", n = " << n << std::endl;
    std::cout << "w = [";
    for (int i = 0; i < n; ++i) {
        std::cout << " " << w[i];
    }
    std::cout << " ]" << std::endl;
    std::cout << "r = [";
    for (int i = 0; i < n; ++i)
    {
        std::cout << " " << r[i];
    }
    std::cout << " ]" << std::endl;
    std::cout << "Rate of return of the portfolio: " << rateOfReturn << std::endl;
    std::cout << "V: " << V << std::endl;

    if (!esportaRisultati("result.txt", S, n, w, r, rateOfReturn, V))
    {
        std::cerr << "Errore durante l'esportazione dei risultati." << std::endl;
        return -1;
    }

    delete[] w;
    delete[] r;
}
