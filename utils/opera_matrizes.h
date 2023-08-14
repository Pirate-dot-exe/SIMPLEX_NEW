#ifndef OPERA_MATRIZES_H
#define OPERA_MATRIZES_H

#include "tabela.h"

#include <iostream>
#include <vector>
#include <algorithm>

// Assinaturas de funções
void gera_identidade(Tabela& tabela);
// Manipula a matriz B e vetores relacionado para que fique uma matriz identidade
void checa_identidade_B(Tabela& tabela);
// Conjunto de funções para trocar elementos/colunas de vetores/matrizes
void troca_coluna(
    Tabela& tabela, std::vector<std::vector<double>>& matriz, int coluna_saida, int coluna_entrada
);  // Para operar matrizes (tipo double)
void troca_coluna(
    Tabela& tabela, std::vector<double>& vetor, int coluna_saida, int coluna_entrada
);  // Para operar vetores (tipo double)
void troca_coluna(
    Tabela& tabela, std::vector<std::string>& vetor, int coluna_saida, int coluna_entrada
);  // Para operar vetores (tipo string)
std::vector<std::string> disjuncao_vetores(std::vector<std::string> vetor1, std::vector<std::string> vetor2);
std::vector<double> disjuncao_vetores(std::vector<double> vetor1, std::vector<double> vetor2);
std::vector<double> subtrai_vetores(std::vector<double> vetor1, std::vector<double> vetor2);
//
std::vector<double> multiplicaMatrizes(
    std::vector<std::vector<double>> matriz, std::vector<double> vetor
);

std::vector<std::string> getXN(
    std::vector<std::string> X, int corte
){
    std::vector<std::string> XN;
    for (size_t i = 0; i < corte; i++){
        XN.push_back(X[i]);
    }
    return XN;
}
std::vector<std::string> getXB(
    std::vector<std::string> X, int corte
){
    std::vector<std::string> XB;
    for (size_t i = 0; i < X.size(); i++){
        if (i >= corte){
            XB.push_back(X[i]);
        }
    }
    return XB;
}

std::vector<double> getCtn(
    std::vector<double> C, int corte
){
    std::vector<double> Ctn;
    for (size_t i = 0; i < corte; i++){
        Ctn.push_back(C[i]);
    }
    return Ctn;
}
std::vector<double> getCtb(
    std::vector<double> C, int corte
){
    std::vector<double> Ctb;
    for (size_t i = 0; i < C.size(); i++){
        if (i >= corte){
            Ctb.push_back(C[i]);
        }
    }
    return Ctb;
}

std::vector<std::vector<double>> getMatrizN(
    std::vector<std::vector<double>> matrizA, int corte
){
    std::vector<std::vector<double>> matrizN;
    std::vector<double> linha;
    for(size_t i = 0; i < matrizA.size(); i++){
        for(size_t j = 0; j < corte; j++){
            linha.push_back(matrizA[i][j]);
        }
        matrizN.push_back(linha);
    }
    return matrizN;
}
std::vector<std::vector<double>> getMatrizB(
    std::vector<std::vector<double>> matrizA, int corte
){
    std::vector<std::vector<double>> matrizB;
    std::vector<double> linha;
    for(size_t i = 0; i < matrizA.size(); i++){
        for(size_t j = 0; j < matrizA[i].size(); j++){
            if (j >= corte){
                linha.push_back(matrizA[i][j]);
            }

        }
        matrizB.push_back(linha);
    }
    return matrizB;
}

double multiplica_vetores(
    std::vector<double> vetor1, std::vector<double> vetor2
){
    double valor = 0;
    for(size_t i = 0; i < vetor1.size(); i++){
        valor += vetor1[i] * vetor2[i];
    }
    return valor;
}

std::vector<double> multiplicaMatrizes(
    std::vector<std::vector<double>> matriz, std::vector<double> vetor
)
{
    int linhasMatriz = matriz.size();
    int colunasMatriz = matriz[0].size();
    std::vector<double> vetor_resultante;
    double soma = 0;

    for (int i = 0; i < linhasMatriz; i++){
        for (int j = 0; j < colunasMatriz; j++){
            std::cout << matriz[i][j] << " * " << vetor[j];
            soma += (matriz[i][j] * vetor[j]);
        }
        vetor_resultante.push_back(soma);
        soma = 0;
    }

    return vetor_resultante;
}

std::vector<double> multiplicaMatrizes(
    std::vector<double> vetor, std::vector<std::vector<double>> matriz
)
{
    int linhasMatriz = matriz.size();
    int colunasMatriz = matriz[0].size();
    std::vector<double> vetor_resultante;
    double soma = 0;

    for (int i = 0; i < colunasMatriz; i++){
        for (int j = 0; j < linhasMatriz; j++){
            std::cout << matriz[j][i] << " * " << vetor[j];
            soma += (matriz[j][i] * vetor[j]);
        }
        vetor_resultante.push_back(soma);
        soma = 0;
    }

    return vetor_resultante;
}
// Inicio das funções

std::vector<double> obtem_coluna(std::vector<std::vector<double>> matriz, int indice_coluna){
    std::vector<double> coluna;
    for (size_t i = 0; i < matriz.size(); i++){
        for (size_t j = 0; j < matriz[i].size(); j++){
            if(j == indice_coluna){
                coluna.push_back(matriz[i][j]);
            }
        }
    }
    return coluna;
}

std::vector<double> subtrai_vetores(std::vector<double> vetor1, std::vector<double> vetor2){
    std::vector<double> vetor_resultante;
    /*
    for (double v1 : vetor1){
        std::cout << v1 << " ";
    }
    std::cout << std::endl;
    for (double v2 : vetor2){
        std::cout << v2 << " ";
    }
    */
    for (size_t i = 0; i < vetor1.size(); i++){
        vetor_resultante.push_back(vetor1[i] - vetor2[i]);
    }
    return vetor_resultante;
}

std::vector<double> disjuncao_vetores(std::vector<double> vetor1, std::vector<double> vetor2){
    std::vector<double> vetor_resultante;

    for (double elemento : vetor1) {
        if (std::find(vetor2.begin(), vetor2.end(), elemento) == vetor2.end()) {
            vetor_resultante.push_back(elemento);
        }
    }

    return vetor_resultante;
}
std::vector<std::string> disjuncao_vetores(std::vector<std::string> vetor1, std::vector<std::string> vetor2){
    std::vector<std::string> vetor_resultante;

    for (std::string elemento : vetor1) {
        if (std::find(vetor2.begin(), vetor2.end(), elemento) == vetor2.end()) {
            vetor_resultante.push_back(elemento);
        }
    }

    return vetor_resultante;
}

void gera_identidade(Tabela& tabela){
    int tamanho = tabela.matrizA.size();
    std::vector<double> linha;
    for (int i = 0; i < tamanho; i++){
        for (int j = 0; j < tamanho; j++){
            if (i == j){
                linha.push_back(1.0);
            }else{
                linha.push_back(0.0);
            }
        }
        tabela.matriz_I.push_back(linha);
        linha.clear();
    }
}

void converte_identidade(
    Tabela& tabela, std::vector<std::vector<double>>& matriz
){   
    for (size_t i = 0; i < matriz.size(); ++i) {
        for (size_t j = 0; j < matriz[i].size(); ++j) {
            if (tabela.matrizA[i][j] == 1.0 && i != j) {
                troca_coluna(tabela, matriz, i, j);
                troca_coluna(tabela, tabela.X, tabela.X.size()+i, tabela.X.size()+j);
                troca_coluna(tabela, tabela.C, tabela.C.size()+i, tabela.C.size()+j);
            }
        }
    }
}

void apaga_coluna(
    Tabela& tabela, std::vector<double>& vetor, int coluna
){
    if (coluna >= 0 && coluna < vetor.size()) {
        vetor.erase(vetor.begin() + coluna);
    }
}
void apaga_coluna(
    Tabela& tabela, std::vector<std::string>& vetor, int coluna
){
    if (coluna >= 0 && coluna < vetor.size()) {
        vetor.erase(vetor.begin() + coluna);
    }
}
void apaga_coluna(
    Tabela& tabela, std::vector<std::vector<double>> matriz, int coluna
){
    for(size_t i = 0; i < matriz.size(); i++){
        if (coluna >= 0 && coluna < matriz[i].size()) {
            matriz[i].erase(matriz[i].begin() + coluna);
        }
    }
}
// Funções de troca de elementos, usadas para operar colunas de diferentes tipos da tabela
// Troca elementos vetor tipo double
void troca_coluna(
    Tabela& tabela, std::vector<double>& vetor, int coluna_saida, int coluna_entrada
){
    std::swap(vetor[coluna_saida], vetor[coluna_entrada]);
}
// Troca elementos vetor tipo string
void troca_coluna(
    Tabela& tabela, std::vector<std::string>& vetor, int coluna_saida, int coluna_entrada
){
    std::swap(vetor[coluna_saida], vetor[coluna_entrada]);
}
// Troca elementos matriz tipo double
void troca_coluna(
    Tabela& tabela, std::vector<std::vector<double>>& matriz, int coluna_saida, int coluna_entrada
)
{   
    for (int i = 0; i < matriz.size(); i++){
        std::swap(matriz[i][coluna_saida], matriz[i][coluna_entrada]);
    }
}

#endif