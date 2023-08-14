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

std::vector<std::string> separaVetor_acima(
    std::vector<std::string> vetor, int corte
){
    std::vector<std::string> novo_vetor;
    for (size_t i = 0; i < vetor.size(); i++){
        if (i > corte){
            novo_vetor.push_back(vetor[i]);
        }
    }
    return novo_vetor;
}
std::vector<std::string> separaVetor_abaixo(
    std::vector<std::string> vetor, int corte
){
    std::vector<std::string> novo_vetor;
    for (size_t i = 0; i < corte; i++){
        novo_vetor.push_back(vetor[i]);
    }
    return novo_vetor;
}

std::vector<double> separaVetor_acima(
    std::vector<double> vetor, int corte
){
    std::vector<double> novo_vetor;
    for (size_t i = 0; i < vetor.size(); i++){
        if (i > corte){
            novo_vetor.push_back(vetor[i]);
        }
    }
    return novo_vetor;
}
std::vector<double> separaVetor_abaixo(
    std::vector<double> vetor, int corte
){
    std::vector<double> novo_vetor;
    for (size_t i = 0; i < corte; i++){
        novo_vetor.push_back(vetor[i]);
    }
    return novo_vetor;
}

std::vector<std::vector<double>> separaMatriz_acima(
    std::vector<std::vector<double>> matriz, int corte
){
    std::vector<std::vector<double>> subMatriz;
    std::vector<double> novaLinha;
    for(size_t i = 0; i < matriz.size(); i++){
        for(size_t j = 0; j < matriz[i].size(); j++){
            if(j >= corte){
                novaLinha.push_back(matriz[i][j]);
            }
        }
        if(!novaLinha.empty()){
            subMatriz.push_back(novaLinha);
        }
        novaLinha.clear();
    }
    return subMatriz;
}

std::vector<std::vector<double>> separaMatriz_abaixo(
    std::vector<std::vector<double>> matriz, int corte
){
    std::vector<std::vector<double>> subMatriz;
    std::vector<double> novaLinha;
    for(size_t i = 0; i < matriz.size(); i++){
        for(size_t j = 0; j < corte; j++){
            novaLinha.push_back(matriz[i][j]);
        }
        subMatriz.push_back(novaLinha);
        novaLinha.clear();
    }
    return subMatriz;
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
    int tamanho = tabela.matrix_B.size();
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

void checa_identidade_B(Tabela& tabela){   
    for (size_t i = 0; i < tabela.matrix_B.size(); ++i) {
        for (size_t j = 0; j < tabela.matrix_B[i].size(); ++j) {
            if (tabela.matrix_B[i][j] == 1.0 && i != j) {
                troca_coluna(tabela, tabela.matrix_B, i, j);
                if(tabela.problema_artificial){
                    troca_coluna(tabela, tabela.XA, tabela.XN.size()+i, tabela.XN.size()+j);
                    troca_coluna(tabela, tabela.Cta, tabela.Ctn.size()+i, tabela.Ctn.size()+j);
                }else{
                    troca_coluna(tabela, tabela.X, tabela.XN.size()+i, tabela.XN.size()+j);
                    troca_coluna(tabela, tabela.C, tabela.Ctn.size()+i, tabela.Ctn.size()+j);
                }
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

std::vector<double> concatena_vetores(
    std::vector<double> vetor1, std::vector<double> vetor2
){
    vetor1.insert( vetor1.end(), vetor2.begin(), vetor2.end() );

    return vetor1;
}

std::vector<std::string> concatena_vetores(
    std::vector<std::string> vetor1, std::vector<std::string> vetor2
){
    vetor1.insert( vetor1.end(), vetor2.begin(), vetor2.end() );

    return vetor1;
}

std::vector<std::vector<double>> concatena_matrizes(
    std::vector<std::vector<double>> matriz1, std::vector<std::vector<double>> matriz2
)
{
    std::vector<std::vector<double>> matriz_resultante;
    for (int i = 0; i < matriz1.size(); i++){
        matriz1[i].insert( matriz1[i].end(), matriz2[i].begin(), matriz2[i].end() );
        matriz_resultante.push_back(matriz1[i]);
    }

    return matriz_resultante;
}

#endif