#ifndef TABELA_H
#define TABELA_H

#include <vector>
#include <iostream>
#include <string>

struct Tabela
{
    bool problema = false;              // Verifica se o problema já foi resolvido
    bool problema_artificial = false;   // Verifica se o problema artificial já foi resolvido
    std::vector<bool> linha_artificial; // Verifica se as linhas precisarão de variaveis artificiais

    std::vector<std::string> restricoes;
    std::vector<std::string> limites;
    int iteracao;
    int num_var;
    bool tipo_funcao;                   // Verifica se é Minimizar (true) ou Maximizar (false)

    std::vector<std::string> X;                 // Coluna [XN|XB]
    std::vector<double> C;                      // Coeficiente [CtN|CtB]
    std::vector<double> coluna_b;               // Coluna b
    std::vector<std::vector<double>> matrizA;   // Matriz A [B|N]
    std::vector<std::vector<double>> matriz_I;  // Matriz Identidade
};

#endif

/*
    std::cout << "Matriz A" << std::endl;
    for (int i = 0; i < tabela.matrix_A.size(); i++){           // Linha de A
        for (int j = 0; j < tabela.matrix_A[i].size(); j++){    // Coluna de N
            std::cout << tabela.matrix_A[i][j] << " ";
        }
        std::cout << std::endl;
    }
*/