#ifndef TABELA_H
#define TABELA_H

#include <vector>
#include <iostream>
#include <string>

struct Tabela
{
    bool tipo_funcao;  // Verifica se é Minimizar (true) ou Maximizar (false)
    bool problema = false;
    int iteracao;
    int num_var;
    std::vector<bool> linha_artificial;
    std::vector<std::string> X;     // Coluna [XN|XB]
    std::vector<std::string> XN;    // Coluna XN
    std::vector<std::string> XB;    // Coluna XB
    std::vector<std::string> restricoes;
    std::vector<std::string> limites;
    std::vector<double> C;      // Coeficiente [CtN|CtB]
    std::vector<double> Ctn;    // Coeficiente F(x) das variaveis não basicas
    std::vector<double> Ctb;    // Coeficiente F(x) das variaveis basicas
    std::vector<double> coluna_b;
    std::vector<std::vector<double>> matrix_N;  // Matriz N
    std::vector<std::vector<double>> matrix_B;  // Matriz B
    std::vector<std::vector<double>> matrix_A;  // Matriz A [B|N]
    std::vector<std::vector<double>> inversa_B; // Inversa de B
    std::vector<std::vector<double>> matriz_I;  // Matriz Identidade

    bool problema_artificial = false;   // ...auto explicativo
    std::vector<std::string> XA;        // Coluna variáveis artificiais
    std::vector<std::vector<double>> matriz_BA; // Matriz B do Problema Artificial
    std::vector<std::vector<double>> matriz_NA; // Matriz N do problema Artificial
    std::vector<double> Cta;            // Coeficiente F(x) artificial
};

void imprime_tabela(Tabela tabela){

    // Colunas XN e XB transpostas
    //std::cout << "XNt|XBt = [";
    for (size_t i = 0; i < tabela.XN.size(); i++){
        std::cout << tabela.XN[i] << " ";
    }
    std::cout << " | ";
    for (size_t i = 0; i < tabela.XB.size(); i++){
        std::cout << tabela.XB[i] << " ";
    }
    //std::cout << "]" << std::endl;
    std::cout << std::endl;
    // Matriz A = [N|B]
    //std::cout << "A = [N|B] = \n [";
    for (size_t i = 0; i < tabela.matrix_N.size(); i++){           // Linha de A
        for (size_t j = 0; j < tabela.matrix_N[i].size(); j++){    // Coluna de N
            std::cout << tabela.matrix_N[i][j] << " ";
        }
        if(!tabela.matrix_B.empty()){
            std::cout << " | ";
            for (size_t j = 0; j < tabela.matrix_B[i].size(); j++){    // Coluna de B
                std::cout << tabela.matrix_B[i][j] << " ";
            }
        }
        std::cout << " || " << tabela.coluna_b[i];              // Linha de b
        std::cout << std::endl;
    } 
    //std::cout << "]" << std::endl;
    // Coluna transposta Cn
    //std::cout << "Ctn|Ctb = [";
    for (double &variable : tabela.Ctn) {
        std::cout << variable << " ";
    }
    std::cout << " | ";
    for (double &varCb : tabela.Ctb){
        std::cout << varCb << " ";
    }
    //std::cout << "]";
}

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