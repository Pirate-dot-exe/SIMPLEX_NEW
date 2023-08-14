#ifndef EXIBICAO_H
#define EXIBICAO_H

#include <iostream>
#include <vector>
#include <string>

void exibeMatriz_double(std::vector<std::vector<double>> matriz, std::string nome = ""){
    std::cout << "Matriz " << nome << std::endl;
    for (size_t i = 0; i < matriz.size(); i++){
        for (size_t j = 0; j < matriz[i].size(); j++){
            std::cout << matriz[i][j] << " ";
        }
        std::cout << "\n";
    }
}
void exibeVetor_double(std::vector<double> vetor, std::string nome = ""){
    std::cout << "Vetor " << nome << std::endl;
    for (size_t i = 0; i < vetor.size(); i++){
        std::cout << vetor[i] << " ";
    }
}
void exibeVetor_string(std::vector<std::string> vetor, std::string nome = ""){
    std::cout << "Vetor " << nome << std::endl;
    for (size_t i = 0; i < vetor.size(); i++){
        std::cout << vetor[i] << " ";
    }
}

#endif