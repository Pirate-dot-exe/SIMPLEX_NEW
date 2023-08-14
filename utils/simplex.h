#ifndef SIMPLEX_H
#define SIMPLEX_H

#include <string>
#include <vector>

#include "tabela.h"
#include "opera_matrizes.h"
#include "obtem_inversa.h"

// Assinaturas de funções
void formalizar_tabela(Tabela& tabela);
void artificializar(Tabela& tabela);

bool checa_solucao_otima(std::vector<double> C_chapeu){
    for (int elemento : C_chapeu) {
        if (elemento < 0) {
            return false;
        }
    }
    return true;
}

void formalizar_tabela(Tabela& tabela){

    tabela.num_var = tabela.XN.size();
    int linha = 0;
    int indice_limite = 0;

    for(std::string &limite : tabela.limites){
        tabela.linha_artificial.push_back(true);
        if ( (limite == "<" || limite == ">") || (limite == "<=" || limite == ">=")){

            tabela.num_var++;
            std::string xB = "x" + std::to_string(tabela.num_var);
            tabela.XB.push_back(xB);
            tabela.Ctb.push_back(0.0);

            tabela.linha_artificial[linha] = false;
            if( !tabela.matrix_B.empty()){
                for (size_t i = 0; i < tabela.coluna_b.size(); i++){
                    if( i == linha ){
                        tabela.matrix_B[i].push_back(1.0);
                    }else{
                        tabela.matrix_B[i].push_back(0.0);
                    }
                }
            }else{
                for (size_t i = 0; i < tabela.coluna_b.size(); i++){

                    std::vector<double> nova_linha;

                    if( i == linha ){
                        nova_linha.push_back(1.0);
                        tabela.matrix_B.push_back(nova_linha);
                    }else{
                        nova_linha.push_back(0.0);
                        tabela.matrix_B.push_back(nova_linha);
                    }
                    nova_linha.clear();
                }
            }

            tabela.limites[indice_limite] = "=";
        }else{
            tabela.problema_artificial = true;
        }
        indice_limite++;
        linha++;
    }
}

void artificializar(Tabela& tabela){

    // Gera coluna de coeficientes e matriz temporarias para o problema artificial
    int cta_size = tabela.C.size();
    for (int i = 0; i < cta_size; i++){
        tabela.Cta.push_back(0.0);
        tabela.XA.push_back(tabela.X[i]);
    }
    
    // Artificializa o problema
    int linha = 0;
    for(std::string &limite : tabela.limites){

        if (limite == "=" && tabela.linha_artificial[linha]){

            tabela.num_var++;
            std::string xA = "a" + std::to_string(tabela.num_var);
            tabela.XA.push_back(xA);
            tabela.Cta.push_back(1.0);

            if( !tabela.matrix_B.empty()){
                for (size_t i = 0; i < tabela.coluna_b.size(); i++){
                    if( i == linha ){
                        tabela.matrix_B[i].push_back(1.0);
                    }else{
                        tabela.matrix_B[i].push_back(0.0);
                    }
                }
            }else{
                for (size_t i = 0; i < tabela.coluna_b.size(); i++){

                    std::vector<double> nova_linha;

                    if( i == linha ){
                        nova_linha.push_back(1.0);
                        tabela.matrix_B.push_back(nova_linha);
                    }else{
                        nova_linha.push_back(0.0);
                        tabela.matrix_B.push_back(nova_linha);
                    }
                    nova_linha.clear();
                }
            }
        }
        linha++;
    }
}

void resolve_problema_artificial(Tabela& tabela){
    // Resolve o problema artificial
    bool soluca_otima = false;
    tabela.matriz_BA = tabela.matrix_B;
    tabela.matriz_NA = tabela.matrix_N;
    while(tabela.problema_artificial){

        tabela.inversa_B = calcula_inversa(
            tabela.matriz_BA, tabela.matriz_I
        );
        std::cout << "BI" << std::endl;
        for (size_t i = 0; i < tabela.inversa_B.size(); i++){
            for (size_t j = 0; j < tabela.inversa_B[i].size(); j++){
                std::cout << tabela.inversa_B[i][j] << " ";
            }
            std::cout << "\n";
        }  
        
        std::vector<double> XB_chapeu = multiplicaMatrizes(
            tabela.inversa_B, tabela.coluna_b
        );
        std::cout << "XBC" << std::endl;
        for (size_t i = 0; i < XB_chapeu.size(); i++){
            std::cout << XB_chapeu[i] << " "; 
        }  
        std::cout << "\n";

        std::vector<double> CTB;
        CTB.assign(tabela.Cta.begin() + tabela.Ctn.size(), tabela.Cta.end());
        std::vector<double> Lambda_t = multiplicaMatrizes(
            CTB, tabela.inversa_B 
        );
        std::cout << "CTB" << std::endl;
        for (size_t i = 0; i < CTB.size(); i++){
            std::cout << CTB[i] << " "; 
        }  
        std::cout << "\n";
        std::cout << "Lambda_t" << std::endl;
        for (size_t i = 0; i < Lambda_t.size(); i++){
            std::cout << Lambda_t[i] << " "; 
        }  
        std::cout << "\n";

        std::cout << "NA" << std::endl;
        for (size_t i = 0; i < tabela.matriz_NA.size(); i++){
            for (size_t j = 0; j < tabela.matriz_NA[i].size(); j++){
                std::cout << tabela.matriz_NA[i][j] << " ";
            }
            std::cout << "\n";
        }  
        std::vector<double> C_chapeu;
        std::vector<std::vector<double>> colunasN;
        for (size_t i = 0; i < tabela.Ctn.size(); i++){
            colunasN.push_back(obtem_coluna(tabela.matriz_NA, i));
            C_chapeu.push_back(tabela.Cta[i] - multiplica_vetores(colunasN[i], Lambda_t));
        }
        std::cout << "\n";
        std::cout << "ColunasN" << std::endl;
        for (size_t i = 0; i < colunasN.size(); i++){
            for (size_t j = 0; j < colunasN[i].size(); j++){
                std::cout << colunasN[i][j] << " "; 
            }
            std::cout << "\n";
        }  
        
        std::cout << "\n";
        std::cout << "C_chapeu" << std::endl;
        for (size_t i = 0; i < C_chapeu.size(); i++){
            std::cout << C_chapeu[i] << " "; 
        }  
        std::cout << "\n";

        soluca_otima = checa_solucao_otima(C_chapeu);
        if (soluca_otima){
            std::cout << "Solucao Basica Viavel (SBV) para o problema artificial encontrada! \n";
            tabela.problema_artificial = false;
        }else{
            int var_entrada = 0;
            for (size_t i = 0; i < C_chapeu.size(); i++){
                if (C_chapeu[i] < C_chapeu[var_entrada]){
                    var_entrada = i;
                }
            }

            std::vector<double> Y = multiplicaMatrizes(tabela.inversa_B, colunasN[var_entrada]);
            int var_saida = 0;
            double E = 9999;
            for (size_t i = 0; i < XB_chapeu.size(); i++){
                if (XB_chapeu[i]/Y[i] >= 0 && XB_chapeu[i]/Y[i] < E){
                    var_saida = i;
                }   
            }

            std::cout << "Sai: " << tabela.XA[var_saida + tabela.XN.size()] << std::endl;
            std::cout << "Entra: " << tabela.XA[var_entrada] << std::endl;

            troca_coluna(tabela, tabela.matrix_A, var_saida + tabela.XN.size(), var_entrada);
            troca_coluna(tabela, tabela.XA, var_saida + tabela.XN.size(), var_entrada);
            troca_coluna(tabela, tabela.Cta, var_saida + tabela.XN.size(), var_entrada);
            tabela.matriz_BA = separaMatriz_acima(tabela.matrix_A, tabela.XN.size());
            tabela.matriz_NA = separaMatriz_abaixo(tabela.matrix_A, tabela.XN.size());

            for (std::string x : tabela.XA){
                std::cout << x << " ";
            }
            std::cout << std::endl;
            for (size_t i = 0; i < tabela.matrix_A.size(); i++){
                for (size_t j = 0; j < tabela.matrix_A[i].size(); j++){
                    std::cout << tabela.matrix_A[i][j] << " ";
                }
                std::cout << std::endl;
            }
            for (double c : tabela.Cta){
                std::cout << c << " ";
            }
            std::cout << std::endl;
            std::cout << "Step" << std::endl;
            int command;
            std::cin >> command;
        }
    }
}
#endif