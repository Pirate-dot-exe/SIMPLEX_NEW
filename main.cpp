#include "utils/tabela.h"
#include "utils/lpreader.h"
#include "utils/simplex.h"
#include "utils/opera_matrizes.h"
#include "utils/obtem_inversa.h"

#include <iostream>
#include <vector>
#include <string>
#include <regex>

int main(){
    //bool passo_a_passo = true;

    // Leitura do arquivo .lp
    std::string nomeArquivo = "C:/src/VSCode_Workspace/C/NewVersion_TrabSimplex/lista_problemas/exerc57.lp";
    Tabela tabela = lerArquivo(nomeArquivo);

    // Transforma a função para a forma padrão
    formalizar_tabela(tabela);

    // Obtem vetores C = [Ctn|Ctb] e X = [XN|XB]
    tabela.C = concatena_vetores(tabela.Ctn, tabela.Ctb);
    tabela.X = concatena_vetores(tabela.XN, tabela.XB);

    // Se necessário, transforma a tabela em um problema artificial
    if (tabela.problema_artificial){
        std::cout << "Necessita Problema Artificial" << std::endl;
        artificializar(tabela);
    }
    // Cria a matriz identidade correspondente a matriz B
    gera_identidade(tabela);
    // Transforma a matriz B em matriz identidade para facilitar a manipulação
    checa_identidade_B(tabela);
    // Gera a matriz A concatenando as matrizes N e B horizontalmente (expandindo linhas)
    tabela.matrix_A = concatena_matrizes(tabela.matrix_N, tabela.matrix_B);

    resolve_problema_artificial(tabela);

    std::regex padraoVarArt("a+\\d+");
    std::regex padraoVar("x+\\d+");
    int indice = 0;
    std::vector<double> aux;
    for (size_t i = 0; i < tabela.XA.size(); i++){
        if(std::regex_match(tabela.XA[i], padraoVarArt)){
            tabela.XN = separaVetor_abaixo(tabela.XA, i);
            tabela.XB = separaVetor_acima(tabela.XA, i);
            tabela.X = concatena_vetores(tabela.XN, tabela.XB);
            tabela.matrix_N = separaMatriz_abaixo(tabela.matrix_A, i);
            tabela.matrix_B = separaMatriz_acima(tabela.matrix_A, i+1);
            tabela.matrix_A = concatena_matrizes(tabela.matrix_N, tabela.matrix_B);
        }else if (std::regex_match(tabela.XA[i], padraoVar)){
            aux.push_back( tabela.C[indice] );
        }
    }

    for (std::string x : tabela.X){
        std::cout << x << " ";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < tabela.matrix_A.size(); i++){
        for (size_t j = 0; j < tabela.matrix_A[i].size(); j++){
            std::cout << tabela.matrix_A[i][j] << " ";
        }
        std::cout << std::endl;
    }
    for (double c : tabela.C){
        std::cout << c << " ";
    }
    std::cout << std::endl;


    while(tabela.problema){

    }

    return 0;
}