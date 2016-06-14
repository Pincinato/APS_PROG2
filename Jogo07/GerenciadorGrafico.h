// CLASSE GERENCIADORA DAS FUNCOES DO ALLEGRO
// DATA DE MODIFICACAO: 18/05/2016

#ifndef GERENCIADORGRAFICO_H_INCLUDED
#define GERENCIADORGRAFICO_H_INCLUDED
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <iostream>

enum DIRECAO{DIREITA, ESQUERDA, CIMA, BAIXO};

class GerenciadorGrafico
{
private:
    const int LarguraTela = 800; // ATRIBUTO REFERENTE AO TAMANHO DA LARGURA DA TELA
    const int AlturaTela = 600; // ATRIBUTO REFERENTE AO TAMANHO DA ALTURA DA TELA
    const int FPS = 30; // ATRIBUTO REFERENTE A QUANTIDADE DE FLAMES POR SEGUNDO

    ALLEGRO_EVENT_QUEUE *FilaEventos; // ATRIBUTO REFERENTE AO PONTEIRO DA FILA DE EVENTOS
    ALLEGRO_DISPLAY *display; // ATRIBUTO REFERENTE AO PONTEIRO DO DISPLAY
    ALLEGRO_TIMER *timer; // ATRIBUTO REFERENTE AO PONTEIRO DO TIMER
    ALLEGRO_FONT *fonte; // ATRIBUTO REFERENTE AO PONTEIRO DA FONTE PADRAO
    ALLEGRO_BITMAP *tela_inicial;

public:
    // CONSTRUTORA DA CLASSE GERENCIADORGRAFICO
    GerenciadorGrafico();

    // DESTRUTORA DA CLASSE GERENCIADORGRAFICO
    ~GerenciadorGrafico();

    // METODO PARA UTILIZAR O PONTEIRO DA FILA DE EVENTOS
    ALLEGRO_EVENT_QUEUE *GetFilaEventos();

    // METODO PARA UTILIZAR O PONTEIRO DO DISPLAY
    ALLEGRO_DISPLAY *GetDisplay();

    // METODO PARA UTILIZAR O PONTEIRO DO TEMPORIZADOR
    ALLEGRO_TIMER *GetTimer();

    // METODO PARA INICIALIZAR O ALLEGRO
    int InitAllegro();

    // METODO PARA CRIAR O DISPLAY
    void CriaDisplay();

    // METODO PARA VERIFICAR SE O DISPLAY FOI CRIADO CORRETAMENTE
    int TestaDisplay();

    // METODO PARA INSTALAR OS AGENTES EXTERNOS
    void InstalaHardwares();

    // METODO PARA INICIALIZAR OS ADDONS DO ALLEGRO
    void InitAddons();

    // METODO PARA CRIAR A FILA DE EVENTOS
    void CriaFilaEventos();

    // METODO PARA CRIAR A FONTE PADRAO
    void CriaFonte();

    // METODO PARA CRIAR O TEMPORIZADOR
    void CriaTimer();

    // METODO PARA REGISTRAR OS SOURCES NA FILA DE EVENTOS
    void RegistraSources();

    void Pause(int o);

    void Tela_inicial(int o);

    void EscolhaJogadores(int o);

    void EscolheFase(int o);

    // PERGUNTAR AO PROFESSOR
    void DestroiTudo();
    void Init();
};

#endif // GERENCIADORGRAFICO_H_INCLUDED
