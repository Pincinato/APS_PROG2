#include "GerenciadorArquivo.h"


GerenciadorArquivo::GerenciadorArquivo(){

}

GerenciadorArquivo::~GerenciadorArquivo(){

}

void GerenciadorArquivo::Load_jogo(){

}

int GerenciadorArquivo::Salva_jogo(){

    return 1;
}

void GerenciadorArquivo::Load_Cenario(){

}

void GerenciadorArquivo::Load_Chefao(){

}
void GerenciadorArquivo::Load_Fase(){

}

void GerenciadorArquivo::Load_Inimigo(){

}

void GerenciadorArquivo::Load_Jogador(Jogador *j){

    arquivo = fopen("Arquivo_Teste.txt","r");
    std::string info_jogador;
    fscanf(arquivo,"%s",&info_jogador[0]);
    info_jogador.erase(0);
    j->SetposX(stoi(info_jogador));

}

int GerenciadorArquivo::Salva_Cenario(){


    return 1;
}

int GerenciadorArquivo::Salva_Chefao(){

    return 1;
}

int GerenciadorArquivo::Salva_Fase(){

    return 1;
}

int GerenciadorArquivo::Salva_Inimigo(){

    return 1;
}

int GerenciadorArquivo::Salva_Jogador(Jogador j){

    printf("Salvando jogador\n");
    arquivo = fopen("Arquivo_Teste.txt","wr");
    std:: string info_jogador;
    std:: string position;
    printf("pegando dados do sentido \n");
    info_jogador =to_string((j.GetDirecao(0)));
    printf("pegando dados da posicao x \n");
    position = to_string(j.GetX());
    printf("cat posicao \n");
    info_jogador.append(position);
    printf("cat /n \n");
    info_jogador.append("\n");
    printf("cat com 0 \n");
    info_jogador.append("\0");
    printf("escrevendo no arquivo \n");
    fprintf(arquivo,"%s",&info_jogador[0]);
    printf("Fechando o arquivo \n");
    fclose(arquivo);

    return 1;
}
