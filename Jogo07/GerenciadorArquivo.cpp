#include "GerenciadorArquivo.h"
#include <string.h>
#include <cstdlib>
#include <stdlib.h>

GerenciadorArquivo::GerenciadorArquivo(){

}

GerenciadorArquivo::~GerenciadorArquivo(){

}

void GerenciadorArquivo::Load_jogo(){

}

int GerenciadorArquivo::Salva_jogo(){

    arquivo=fopen("Arquivo_Teste.txt","w");
    fclose(arquivo);
    return 1;
}

void GerenciadorArquivo::Load_Cenario(Cenario *c){

    printf("Carregando dados do cenario \n");
    arquivo = fopen("Arquivo_Teste.txt","r");
    std::string info;
    do{
    if(fgets(&info[0],100,arquivo) != "\n"){}
     printf("%s",&info[0]);
    }while(strcmp(&info[0],"Cenario \n")!=0 &&  strcmp(&info[0],"EOF")!=0 );
    fscanf(arquivo,"%s",&info[0]);
    printf(" ultima posicao x do Cenario %s \n",&info[0]);
    c->SetposX(stoi(info));
    fclose(arquivo);
}

void GerenciadorArquivo::Load_Chefao(){

}
void GerenciadorArquivo::Load_Fase(){

}

void GerenciadorArquivo::Load_Inimigo(Inimigo *i){

    printf("Carregando dados do inimigo \n");
    arquivo = fopen("Arquivo_Teste.txt","r");
    std::string info_inimigo;
    std::string name_inimigo;
    std::string id_inimigo;
    char aux;
    name_inimigo= i->Get_Name();
    id_inimigo=to_string(i->GetId());
    name_inimigo.append(id_inimigo);
    name_inimigo.append("\n");
    name_inimigo.append("\0");
    do{
    if(fgets(&info_inimigo[0],100,arquivo) != "\n"){}
     printf("%s",&info_inimigo[0]);
    }while(strcmp(&info_inimigo[0],&name_inimigo[0])!=0 &&  strcmp(&info_inimigo[0],"EOF")!=0 );
    fscanf(arquivo,"%s",&info_inimigo[0]);
    printf("ultima posicao do inimigo %s \n",&info_inimigo[0]);
    i->SetposX(stoi(info_inimigo));
    fscanf(arquivo,"%s",&info_inimigo[0]);
    printf("ultimo control do inimigo %s \n",&info_inimigo[0]);
    i->SetControl_posx(stoi(info_inimigo));
    fscanf(arquivo,"%s",&info_inimigo[0]);
    printf("ultimo deslocamento do inimigo %s \n",&info_inimigo[0]);
    i->SetDeslocamento(stoi(info_inimigo));
    fscanf(arquivo,"%s",&info_inimigo[0]);
    printf("ultima direcao do inimigo %s \n",&info_inimigo[0]);
    i->SetDirecao(stoi(info_inimigo));
    fclose(arquivo);

}

void GerenciadorArquivo::Load_Jogador(Jogador *j){

    printf("Carregando dados do jogador \n");
    arquivo = fopen("Arquivo_Teste.txt","r");
    std::string info_jogador;
    std::string id_jogador;
    std::string name_jogador;
    id_jogador.clear();
    id_jogador = to_string(j->GetId());
    id_jogador.append("\0");
    name_jogador.clear();
    name_jogador.append("Jogador");
    name_jogador.append("\0");
    name_jogador.append(id_jogador);
    name_jogador.append("\n");
    name_jogador.append("\0");
    do{
    if(fgets(&info_jogador[0],100,arquivo) != "\n"){}
     printf("%s",&info_jogador[0]);
    }while(strcmp(&info_jogador[0],&name_jogador[0])!=0 &&  strcmp(&info_jogador[0],"EOF")!=0 );
    fscanf(arquivo,"%s",&info_jogador[0]);
    printf(" ultima posicao x do player 1 %s \n",&info_jogador[0]);
    j->SetposX(stoi(info_jogador));
    fscanf(arquivo,"%s",&info_jogador[0]);
    printf(" ultima posicao y do player 1 %s \n",&info_jogador[0]);
    j->SetposY(stoi(info_jogador));
    fclose(arquivo);
}

int GerenciadorArquivo::Salva_Cenario(Cenario *c){

    printf("Salvando Cenario\n");
    arquivo = fopen("Arquivo_Teste.txt","a");
    std:: string info;
    printf("Pegando dados da posicao x \n");
    info= to_string(c->GetX());
    info.append("\n");
    info.append("\0");
    printf("escrevendo no arquivo \n");
    fprintf(arquivo,"Cenario \n");
    fprintf(arquivo,"%s",&info[0]);
    printf("Fechando o arquivo \n");
    fclose(arquivo);
    return 1;
}

int GerenciadorArquivo::Salva_Chefao(){

    return 1;
}

int GerenciadorArquivo::Salva_Fase(){

    return 1;
}

int GerenciadorArquivo::Salva_Inimigo(Inimigo *i){

   printf("Salvando inimigo\n");
    arquivo = fopen("Arquivo_Teste.txt","a");
    std:: string info_inimigo;
    std:: string name_inmigo;
    std::string id_inimigo;
    std::string aux;
    printf("Pegando dados da posicao x \n");
    info_inimigo = to_string(i->GetposX());
    info_inimigo.append("\n");
    info_inimigo.append("\0");
    aux=to_string(i->Getcontrol_posx());
    aux.append("\n");
    aux.append("\0");
    info_inimigo.append(&aux[0]);
    aux=to_string(i->Getdeslocamento());
    aux.append("\n");
    aux.append("\0");
    info_inimigo.append(&aux[0]);
    aux=to_string(i->Getdirecao());
    aux.append("\n");
    aux.append("\0");
    info_inimigo.append(&aux[0]);
    name_inmigo= i->Get_Name();
    id_inimigo=to_string(i->GetId());
    name_inmigo.append(id_inimigo);
    name_inmigo.append("\n");
    name_inmigo.append("\0");
    printf("escrevendo no arquivo \n");
    fprintf(arquivo,&name_inmigo[0]);
    fprintf(arquivo,"%s",&info_inimigo[0]);
    printf("Fechando o arquivo \n");
    fclose(arquivo);
    return 1;
}

int GerenciadorArquivo::Salva_Jogador(Jogador j){

    printf("Salvando jogador\n");
    arquivo = fopen("Arquivo_Teste.txt","a");
    std:: string info_jogador;
    std:: string info_y;
    std:: string id_jogador;
    std:: string name_jogador;
    info_y.clear();
    printf("pegando dados da posicao x \n");
    info_jogador = to_string(j.GetposX());
    info_jogador.append("\n");
    printf("pegando dados da posicao y \n");
    info_y = to_string(j.GetposY());
    info_y.append("\n");
    info_y.append("\0");
    info_jogador.append(&info_y[0]);
    info_jogador.append("\0");
    id_jogador.clear();
    id_jogador = to_string(j.GetId());
    id_jogador.append("\0");
    name_jogador.clear();
    name_jogador.append("Jogador");
    name_jogador.append("\0");
    name_jogador.append(id_jogador);
    name_jogador.append("\n");
    name_jogador.append("\0");

    printf("escrevendo no arquivo \n");
    fprintf(arquivo,&name_jogador[0]);
    fprintf(arquivo,"%s",&info_jogador[0]);
    printf("Fechando o arquivo \n");
    fclose(arquivo);

    return 1;
}

