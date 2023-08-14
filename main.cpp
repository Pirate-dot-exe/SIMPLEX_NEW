#include "utils/tabela.h"
#include "utils/lpreader.h"
#include "utils/simplex.h"
#include "utils/exibicao.h"

#include <iostream>
#include <string>

int main(){
    //bool passo_a_passo = true;

    // Leitura do arquivo .lp
    std::string nomeArquivo = "C:/src/VSCode_Workspace/C/NewVersion_TrabSimplex/lista_problemas/exerc57.lp";
    Tabela tabela = lerArquivo(nomeArquivo);

    exibeVetor_string(tabela.X, "X");
    exibeMatriz_double(tabela.matrizA, "A");
    exibeVetor_double(tabela.C, "C");

    // Transforma a função para a forma padrão
    formalizar_tabela(tabela);

    exibeVetor_string(tabela.X);
    exibeMatriz_double(tabela.matrizA);
    exibeVetor_double(tabela.C);

    // Se necessário, transforma a tabela em um problema artificial
    if (tabela.problema_artificial){
        std::cout << "Necessita Problema Artificial" << std::endl;
        artificializar(tabela);
    }

    exibeVetor_string(tabela.X);
    exibeMatriz_double(tabela.matrizA);
    exibeVetor_double(tabela.C);
    // Cria a matriz identidade correspondente a matriz B
    gera_identidade(tabela);
    // Transforma a matriz B em matriz identidade para facilitar a manipulação
    checa_identidade_B(tabela);

    resolve_problema_artificial(tabela);

    while(tabela.problema){
        std::cout << std::endl;
    }

    return 0;
}