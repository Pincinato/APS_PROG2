#include "GerenciadorArquivo.h"


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

void GerenciadorArquivo::Load_Cenario(){

}
//https://github.com/Pincinato/APS_PROG2.git
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
    //info_inimigo.erase(0);
    printf("ultima posicao do inimigo %s \n",&info_inimigo[0]);
    i->SetposX(stoi(info_inimigo));


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
    printf(" ultima posicao do player 1 %s \n",&info_jogador[0]);
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

int GerenciadorArquivo::Salva_Inimigo(Inimigo *i){

    printf("Salvando inimigo\n");
    arquivo = fopen("Arquivo_Teste.txt","a");
    std:: string info_inimigo;
    std:: string name_inmigo;
    std::string id_inimigo;
    printf("Pegando dados da posicao x \n");
    info_inimigo = to_string(i->GetposX());
    printf("cat /n \n");
    info_inimigo.append("\n");
    printf("cat com 0 \n");
    info_inimigo.append("\0");
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
    std:: string id_jogador;
    std:: string name_jogador;
    printf("pegando dados da posicao x \n");
    info_jogador = to_string(j.GetposX());
    printf("cat /n \n");
    info_jogador.append("\n");
    printf("cat com 0 \n");
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

