/*****************************************************/
/*         Nilton Rodrigues Pereira             */
/*         Exercício-Programa (Trabalho 2)           */
/*****************************************************/

//Bibliotecas
#include <gl/gl.h>
#include <stdio.h>
#include <glut.h>
#include <stdlib.h>
#include <math.h>

//Protótipos da Rotinas
void Inicializa();
void Teclado(unsigned char tecla, int a, int b);
void TecladoEspecial(int teclaesp, int x, int y);
void Roda();
void Desenha();
void CarroFrenteCimaAtras();
void CarroLateral1();
void CarroLateral2();

//Declarações das variáveis globais
float  GIRAR = 0, CIMA=0, BAIXO=0, MOVER_Direita = 0, MOVER_Esquerda = 0, MOVER_Baixo = 0, MOVER_Cima = 0;

void Inicializa() //Rotina Para Inicialização de Parâmetros
{
     glClearColor(0, 1, 0, 1); //Cor da Janela
     glOrtho(-100, 100, -80, 100, -500, 500); //Define a subdvisião da janela de visualização
     glEnable(GL_DEPTH_TEST);
     glEnable(GL_LINE_SMOOTH);
}

void Teclado(unsigned char tecla, int a, int b) //Rotina Para uso do Teclado Padrão
{
     switch(tecla)
     {
       case 27:
            exit(0);// 'ESC' para terminar
       break;
       case 'a':// 'a' para mover o carro para o lado direito
            GIRAR = GIRAR - 3;
       break;
       case 's':// 's' para mover o carro para o lado Esquerdo
            GIRAR = GIRAR + 3;
       break;
       case 'A':// 'A' para mover o carro para o lado direito
            GIRAR = GIRAR - 3;
       break;
       case 'S':// 'S' para mover o carro para o lado Esquerdo
            GIRAR = GIRAR + 3;
       break;

       case 'w':// 'w' para mover o carro para cima
            CIMA = CIMA + 3;
       break;

       case 'z':// 'z' para mover o carro para baixo
            CIMA = CIMA - 3;
       break;

       case 'W':// 'W' para mover o carro para cima
            CIMA = CIMA + 3;
       break;

       case 'Z':// 'Z' para mover o carro para baixo
            CIMA = CIMA - 3;
       break;
     }
}

void TecladoEspecial(int teclaesp, int x, int y)
{
     switch(teclaesp)
     {
       case GLUT_KEY_UP://Seta direcional para cima
       glRotatef(MOVER_Cima, 1, 0, 0);
       MOVER_Cima = MOVER_Cima + 0.1;
       break;

       case GLUT_KEY_DOWN://Seta direcional para baixo
       glRotatef(MOVER_Baixo, 1, 0, 0);
       MOVER_Baixo = MOVER_Baixo - 0.1;
       break;

       case GLUT_KEY_LEFT://Seta direcional para Esquerda
       glRotatef(MOVER_Esquerda, 0, 1, 0);
       MOVER_Esquerda = MOVER_Esquerda + 0.1;
       break;

       case GLUT_KEY_RIGHT://Seta direcional para Direita
       glRotatef(MOVER_Direita, 0, 1, 0);
       MOVER_Direita = MOVER_Direita - 0.1;
       break;

     }
}

void Roda()//Rotina que desenha a Roda
{
     glPushMatrix();
     glRotatef(-GIRAR,0, 0, 1);//Girar carro
     glColor3f(0, 0, 0);//cor da roda
     glutSolidTorus(3, 8, 50, 50);//roda
     glTranslatef(0, 0,  2);
     glutSolidTorus(3, 8, 50, 50);
     glTranslatef(0, 0, -2);
     glTranslatef(0, 0,  3);
     glutSolidTorus(3, 8, 50, 50);
     glTranslatef(0, 0, -3);
     glTranslatef(0, 0,  4);
     glutSolidTorus(3, 8, 50, 50);
     glTranslatef(0, 0, -4);
     glTranslatef(0, 0,  5);
     glutSolidTorus(3, 8, 50, 50);
     glTranslatef(0, 0, -5);

     glColor3f(0.42, 0.42, 0.44);//Cor dos raios da roda

     glutWireTorus(2, 4, 5, 5);//raios das rodas

     glTranslatef(0, 0,  5);

     glutWireTorus(2, 4, 5, 5);

     glTranslatef(0, 0, -5);

     glColor3f(1, 1, 1);
     glBegin(GL_QUADS);//Parte interior da roda
        glVertex3f(-5,  5, 5.3);
        glVertex3f(-5, -5, 5.3);
        glVertex3f( 5, -5, 5.3);
        glVertex3f( 5,  5, 5.3);
     glEnd();

     glTranslatef(0, 0,  -5);

     glBegin(GL_QUADS);
        glVertex3f(-5,  5, 5.3);
        glVertex3f(-5, -5, 5.3);
        glVertex3f( 5, -5, 5.3);
        glVertex3f( 5,  5, 5.3);
     glEnd();

     glTranslatef(0, 0, 5);

     glPopMatrix();
}

void CarroFrenteCimaAtras()
{
    //VIDRO - Frente
    glColor4f(0.60, 0.95, 1, 0.5);
    glBegin(GL_POLYGON);
      glVertex3f(-6,  48,  -1);
      glVertex3f(-25, 30,  -1);
      glVertex3f(-25, 30, -48);
      glVertex3f(-6,  48, -48);
    glEnd();

    //VIDRO - Atras
    glColor4f(0.60, 0.95, 1, 0.5);
      glBegin(GL_POLYGON);
      glVertex3f(61, 48,  -2);
      glVertex3f(69, 28,  -2);
      glVertex3f(69, 28, -48);
      glVertex3f(61, 48, -48);
    glEnd();

    //LATARIA
    glColor3f(1, 0, 0);
     glBegin(GL_POLYGON); //Lataria cima do Vidro - Frente
        glVertex3f(-4, 50,   0);
        glVertex3f(-6, 48,   0);
        glVertex3f(-6, 48, -50);
        glVertex3f(-4, 50, -50);
     glEnd();

     glBegin(GL_POLYGON); //Lataria Lado Direito Vidro
        glVertex3f( -4, 50,  0);
        glVertex3f(-25, 30,  0);
        glVertex3f(-25, 30, -1);
        glVertex3f( -4, 50, -1);
     glEnd();

     glBegin(GL_POLYGON); //Lataria Lado Esquerdo Vidro
        glVertex3f( -4, 50, -48);
        glVertex3f(-25, 30, -48);
        glVertex3f(-25, 30, -50);
        glVertex3f( -4, 50, -50);
     glEnd();

      glBegin(GL_POLYGON); //Lataria Lado Esquerdo Vidro
        glVertex3f( -4, 50, -48);
        glVertex3f(-25, 30, -48);
        glVertex3f(-25, 30, -50);
        glVertex3f( -4, 50, -50);
     glEnd();

     glBegin(GL_POLYGON); //Capô
        glVertex3f(-25, 30,  0);
        glVertex3f(-60, 18,  0);
        glVertex3f(-60, 18, -5);
        glVertex3f(-65, 15, -10);
        glVertex3f(-65, 15, -40);
        glVertex3f(-60, 18, -45);
        glVertex3f(-60, 18, -50);
        glVertex3f(-25, 30, -50);
     glEnd();

      glBegin(GL_POLYGON); //Lataria Frente Perto Farois
        glVertex3f(-65, 15, -10);
        glVertex3f(-65, 10, -10);
        glVertex3f(-65, 10, -40);
        glVertex3f(-65, 15, -40);
     glEnd();

     glBegin(GL_POLYGON); //Lataria Traseira Perto Farois
        glVertex3f(69, 28,   0);
        glVertex3f(69, 20,   0);
        glVertex3f(69, 20, -50);
        glVertex3f(69, 28, -50);
     glEnd();

     glColor3f(0.42, 0.42, 0.44);
     glBegin(GL_POLYGON); //Parachoque frente
        glVertex3f(-65, 10,   0);
        glVertex3f(-63,  0,   0);
        glVertex3f(-63,  0, -50);
        glVertex3f(-65, 10, -50);
     glEnd();

     glColor3f(0.42, 0.42, 0.44);
     glBegin(GL_POLYGON); //Em baixo do carro
        glVertex3f(-63,  0,   0);
        glVertex3f( 65,  0,   0);
        glVertex3f( 65,  0, -50);
        glVertex3f(-63,  0, -50);
     glEnd();

     glBegin(GL_POLYGON); //Parachoque Traseiro
        glVertex3f(70,  5,   0);
        glVertex3f(70, 10,   0);
        glVertex3f(70, 10, -50);
        glVertex3f(70,  5, -50);
     glEnd();

     glBegin(GL_POLYGON); //Parachoque Traseiro Baixo
        glVertex3f(70, 5,   0);
        glVertex3f(65, 0,   0);
        glVertex3f(65, 0, -50);
        glVertex3f(70, 5, -50);
     glEnd();

     glColor3f(1, 0, 0);
     glBegin(GL_POLYGON); //Lataria cima do Vidro Frente
        glVertex3f(-4, 50,   0);
        glVertex3f(60, 50,   0);
        glVertex3f(60, 50, -50);
        glVertex3f(-4, 50, -50);
     glEnd();

     glBegin(GL_POLYGON); //Lataria cima do Vidro Traseiro
        glVertex3f(60, 50,   0);
        glVertex3f(61, 48,   0);
        glVertex3f(61, 48, -50);
        glVertex3f(60, 50, -50);
     glEnd();

      glBegin(GL_POLYGON); //Lataria Lado do Vidro Esquerdo
        glVertex3f(60, 50,  0);
        glVertex3f(69, 28,  0);
        glVertex3f(69, 28, -2);
        glVertex3f(60, 50, -2);
     glEnd();

     glBegin(GL_POLYGON); //Lataria Lado do Vidro Direito
        glVertex3f(60, 50, -50);
        glVertex3f(69, 28, -50);
        glVertex3f(69, 28, -48);
        glVertex3f(60, 50, -48);
     glEnd();

      glBegin(GL_POLYGON); //Lataria Traseira entre os farois
        glVertex3f(69, 20,  -5);
        glVertex3f(69, 13,  -5);
        glVertex3f(69, 13, -45);
        glVertex3f(69, 20, -45);
     glEnd();

     glBegin(GL_POLYGON); //Lataria Traseira parte Inclinada
        glVertex3f(70, 10,   0);
        glVertex3f(69, 13,   0);
        glVertex3f(69, 13, -50);
        glVertex3f(70, 10, -50);
     glEnd();

     glColor3f(0.3, 0.3, 0.3);
     glBegin(GL_LINES);
        glVertex3f(-65.2, 15, -10);
        glVertex3f(-65.2, 15, -40);
     glEnd();

      glBegin(GL_LINES);
        glVertex3f(-65.2, 13, -10);
        glVertex3f(-65.2, 13, -40);
     glEnd();

      glBegin(GL_LINES);
        glVertex3f(-65.2, 11, -10);
        glVertex3f(-65.2, 11, -40);
     glEnd();

     glBegin(GL_POLYGON); //Farol Cima Direita
        glVertex3f(-60, 18,   0);
        glVertex3f(-65, 15,   0);
        glVertex3f(-65, 15, -10);
        glVertex3f(-60, 18,  -5);
     glEnd();

     glBegin(GL_POLYGON); //Farol Cima Esquerda
        glVertex3f(-60, 18, -45);
        glVertex3f(-65, 15, -40);
        glVertex3f(-65, 15, -50);
        glVertex3f(-60, 18, -50);
     glEnd();

     glBegin(GL_POLYGON); //Farol Frente Direita
        glVertex3f(-65, 15,   0);
        glVertex3f(-65, 10,   0);
        glVertex3f(-65, 10, -10);
        glVertex3f(-65, 15, -10);
     glEnd();

     glBegin(GL_POLYGON); //Farol Frente Esquerda
        glVertex3f(-65, 15, -40);
        glVertex3f(-65, 10, -40);
        glVertex3f(-65, 10, -50);
        glVertex3f(-65, 15, -50);
     glEnd();

     glBegin(GL_POLYGON); //Farol Atrás Direita
        glVertex3f(69, 20,  0);
        glVertex3f(69, 13,  0);
        glVertex3f(69, 13, -5);
        glVertex3f(69, 20, -5);
     glEnd();

     glBegin(GL_POLYGON); //Farol Atrás Esquerda
        glVertex3f(69, 20, -50);
        glVertex3f(69, 13, -50);
        glVertex3f(69, 13, -45);
        glVertex3f(69, 20, -45);
     glEnd();
}

void CarroLateral1()
{
     //LATARIA
     glColor3f(0.26, 0.25, 0.25);
     glBegin(GL_POLYGON); //Linha Abaixo das Portas e cima das rodas
        glVertex3f(-30, 0, 0.1);
        glVertex3f( 40, 0, 0.1);
        glVertex3f( 40, 2, 0.1);
        glVertex3f(-30, 2, 0.1);
     glEnd();

     glBegin(GL_POLYGON); //Fundo da Roda Frente
        glVertex3f(-52,  0, 0.2);
        glVertex3f(-52,  5, 0.2);
        glVertex3f(-45, 12, 0.2);
        glVertex3f(-35, 12, 0.2);
        glVertex3f(-28,  5, 0.2);
        glVertex3f(-28,  0, 0.2);
     glEnd();

     glBegin(GL_POLYGON); //Fundo da Roda Atrás
        glVertex3f(38,  0, 0.2);
        glVertex3f(38,  5, 0.2);
        glVertex3f(45, 12, 0.2);
        glVertex3f(55, 12, 0.2);
        glVertex3f(62,  5, 0.2);
        glVertex3f(62,  0, 0.2);
     glEnd();

     glColor3f(0.42, 0.42, 0.44);//Cor do Parachoque
     glBegin(GL_POLYGON); //Parachoque Roda Frente
        glVertex3f(-52,  0, 00.1);
        glVertex3f(-52,  5, 00.1);
        glVertex3f(-47, 10, 00.1);
        glVertex3f(-65, 10, 00.1);
        glVertex3f(-65,  5, 00.1);
        glVertex3f(-63,  0, 00.1);
     glEnd();

     glBegin(GL_POLYGON); //Parachoque Roda Tras
        glVertex3f(62,  0, 00.1);
        glVertex3f(62,  5, 00.1);
        glVertex3f(57, 10, 00.1);
        glVertex3f(70, 10, 00.1);
        glVertex3f(70,  5, 00.1);
        glVertex3f(65,  0, 00.1);
     glEnd();

     glColor3f(1, 0, 0);//COR da lateral
     glBegin(GL_POLYGON); //Frente Cima Roda Lataria
        glVertex3f(-60, 10, 0);
        glVertex3f(-60, 18, 0);
        glVertex3f(-25, 30, 0);
        glVertex3f(-25,  2, 0);
        glVertex3f(-28,  2, 0);
        glVertex3f(-28,  5, 0);
        glVertex3f(-35, 12, 0);
        glVertex3f(-45, 12, 0);
        glVertex3f(-47, 10, 0);
     glEnd();

     glBegin(GL_POLYGON); //Primeira Porta
        glVertex3f(-25,  0, 0);
        glVertex3f(-25, 28, 0);
        glVertex3f( 22, 28, 0);
        glVertex3f( 22,  0, 0);
     glEnd();

     glBegin(GL_POLYGON); //Lataria Inclinada Primeira Porta
        glVertex3f(-25, 26, 0);
        glVertex3f(-25, 30, 0);
        glVertex3f( -4, 50, 0);
        glVertex3f( -2, 48, 0);
     glEnd();

     glBegin(GL_POLYGON); //Lataria Cima Primeira e Segunda Porta
        glVertex3f( -2, 48, 0);
        glVertex3f( -4, 50, 0);
        glVertex3f( 60, 50, 0);
        glVertex3f( 58, 48, 0);
     glEnd();

     glBegin(GL_POLYGON); //Lataria Entre Porta Primeira e Segunda
        glVertex3f(20, 28, 0);
        glVertex3f(20, 48, 0);
        glVertex3f(22, 48, 0);
        glVertex3f(22, 28, 0);
     glEnd();

     glBegin(GL_POLYGON); //Segunda Porta
        glVertex3f(22,  2, 0);
        glVertex3f(22, 28, 0);
        glVertex3f(69, 28, 0);
        glVertex3f(69, 20, 0);
        glVertex3f(65, 20, 0);
        glVertex3f(65, 13, 0);
        glVertex3f(69, 13, 0);
        glVertex3f(70, 10, 0);
        glVertex3f(58, 10, 0);
        glVertex3f(66, 12, 0);
        glVertex3f(45, 12, 0);
        glVertex3f(40,  5, 0);
        glVertex3f(40,  2, 0);
     glEnd();

     glBegin(GL_POLYGON); //Lataria na Segunda Porta entra a Primeira e Segunda janela
        glVertex3f(50, 28, 0);
        glVertex3f(50, 48, 0);
        glVertex3f(48, 48, 0);
        glVertex3f(48, 28, 0);
     glEnd();

     glBegin(GL_POLYGON); //Lataria Invertida Segunda Porta
        glVertex3f(58, 48, 0);
        glVertex3f(60, 50, 0);
        glVertex3f(69, 28, 0);
        glVertex3f(66, 28, 0);
     glEnd();

     //VIDROS
     glColor4f(0.60, 0.95, 1, 0.5);//Cor do vidro
     glBegin(GL_POLYGON); //Vidro Primeira Porta
        glVertex3f(-24, 28, 0.1);
        glVertex3f( -2, 48, 0.1);
        glVertex3f( 20, 48, 0.1);
        glVertex3f( 20, 28, 0.1);
     glEnd();

     glBegin(GL_POLYGON); //Vidro Segunda Porta Primeira Parte
        glVertex3f(22, 48, 0.1);
        glVertex3f(22, 28, 0.1);
        glVertex3f(48, 28, 0.1);
        glVertex3f(48, 48, 0.1);
     glEnd();

     glBegin(GL_POLYGON); //Vidro Segunda Porta Segunda Parte
        glVertex3f(50, 48, 0.1);
        glVertex3f(50, 28, 0.1);
        glVertex3f(66, 28, 0.1);
        glVertex3f(58, 48, 0.1);
     glEnd();

     glBegin(GL_POLYGON); //Fundo da Roda Frente
     glVertex3f(-65, 15, 0);
     glVertex3f(-65, 10, 0);
     glColor3f(1, 1, 1);

     glEnd();
}

void CarroLateral2()
{
    //LATARIA
     glColor3f(0.26, 0.25, 0.25);
     glBegin(GL_POLYGON); //Linha Preta Abaixo das Portas
        glVertex3f(-30, 0, -0.1);
        glVertex3f( 40, 0, -0.1);
        glVertex3f( 40, 2, -0.1);
        glVertex3f(-30, 2, -0.1);
     glEnd();

     glBegin(GL_POLYGON); //Fundo da Roda Frente
        glVertex3f(-52,  0, -0.2);
        glVertex3f(-52,  5, -0.2);
        glVertex3f(-45, 12, -0.2);
        glVertex3f(-35, 12, -0.2);
        glVertex3f(-28,  5, -0.2);
        glVertex3f(-28,  0, -0.2);
     glEnd();

     glBegin(GL_POLYGON); //Fundo da Roda Atrás
        glVertex3f(38,  0, -0.2);
        glVertex3f(38,  5, -0.2);
        glVertex3f(45, 12, -0.2);
        glVertex3f(55, 12, -0.2);
        glVertex3f(62,  5, -0.2);
        glVertex3f(62,  0, -0.2);
     glEnd();

     glColor3f(0.42, 0.42, 0.44);//Cor do Parachoque
     glBegin(GL_POLYGON); //Parachoque Roda Fkkkkrente
        glVertex3f(-52,  0, -00.1);
        glVertex3f(-52,  5, -00.1);
        glVertex3f(-47, 10, -00.1);
        glVertex3f(-65, 10, -00.1);
        glVertex3f(-65,  5, -00.1);
        glVertex3f(-63,  0, -00.1);
     glEnd();

     glBegin(GL_POLYGON); //Parachoque Roda Tras
        glVertex3f(62,  0, -00.1);
        glVertex3f(62,  5, -00.1);
        glVertex3f(57, 10, -00.1);
        glVertex3f(70, 10, -00.1);
        glVertex3f(70,  5, -00.1);
        glVertex3f(65,  0, -00.1);
     glEnd();

     glColor3f(1, 0, 0); //COR da lateral
     glBegin(GL_POLYGON); //Frente Cima Roda Lataria
        glVertex3f(-60, 10, 0);
        glVertex3f(-60, 18, 0);
        glVertex3f(-25, 30, 0);
        glVertex3f(-25,  2, 0);
        glVertex3f(-28,  2, 0);
        glVertex3f(-28,  5, 0);
        glVertex3f(-35, 12, 0);
        glVertex3f(-45, 12, 0);
        glVertex3f(-47, 10, 0);
     glEnd();

     glBegin(GL_POLYGON); //Primeira Porta
        glVertex3f(-25,  0, 0);
        glVertex3f(-25, 28, 0);
        glVertex3f( 22, 28, 0);
        glVertex3f( 22,  0, 0);
     glEnd();

     glBegin(GL_POLYGON); //Lataria Inclinada Primeira Porta
        glVertex3f(-25, 26, 0);
        glVertex3f(-25, 30, 0);
        glVertex3f( -4, 50, 0);
        glVertex3f( -2, 48, 0);
     glEnd();

     glBegin(GL_POLYGON); //Lataria Cima Primeira e Segunda Porta
        glVertex3f( -2, 48, 0);
        glVertex3f( -4, 50, 0);
        glVertex3f( 60, 50, 0);
        glVertex3f( 58, 48, 0);
     glEnd();

      glBegin(GL_POLYGON); //Lataria Entre Porta Primeira e Segunda
        glVertex3f(20, 28, 0);
        glVertex3f(20, 48, 0);
        glVertex3f(22, 48, 0);
        glVertex3f(22, 28, 0);
     glEnd();

     glBegin(GL_POLYGON); //Segunda Porta
        glVertex3f(22,  2, 0);
        glVertex3f(22, 28, 0);
        glVertex3f(69, 28, 0);
        glVertex3f(69, 20, 0);
        glVertex3f(65, 20, 0);
        glVertex3f(65, 13, 0);
        glVertex3f(69, 13, 0);
        glVertex3f(70, 10, 0);
        glVertex3f(58, 10, 0);
        glVertex3f(66, 12, 0);
        glVertex3f(45, 12, 0);
        glVertex3f(40,  5, 0);
        glVertex3f(40,  2, 0);
     glEnd();

     glBegin(GL_POLYGON); //Lataria na Segunda Porta entra a Primeira e Segunda janela
        glVertex3f(50, 28, 0);
        glVertex3f(50, 48, 0);
        glVertex3f(48, 48, 0);
        glVertex3f(48, 28, 0);
     glEnd();

     glBegin(GL_POLYGON); //Lataria Invertida Segunda Porta
        glVertex3f(58, 48, 0);
        glVertex3f(60, 50, 0);
        glVertex3f(69, 28, 0);
        glVertex3f(66, 28, 0);
     glEnd();

     //FAROIS
     glBegin(GL_POLYGON); //Farol Frente
        glVertex3f(-60, 10, 0.1);
        glVertex3f(-60, 18, 0.1);
        glVertex3f(-65, 15, 0.1);
        glVertex3f(-65, 10, 0.1);
     glEnd();

     glBegin(GL_POLYGON); //Farol Atrás
        glVertex3f(69, 20, 0.1);
        glVertex3f(65, 20, 0.1);
        glVertex3f(65, 13, 0.1);
        glVertex3f(69, 13, 0.1);
     glEnd();

     //VIDROS
     glColor4f(0.60, 0.95, 1, 0.5);
     glBegin(GL_POLYGON); //Vidro Primeira Porta
        glVertex3f(-24, 28, 0.1);
        glVertex3f( -2, 48, 0.1);
        glVertex3f( 20, 48, 0.1);
        glVertex3f( 20, 28, 0.1);
     glEnd();

     glBegin(GL_POLYGON); //Vidro Segunda Porta Primeira Parte
        glVertex3f(22, 48, 0.1);
        glVertex3f(22, 28, 0.1);
        glVertex3f(48, 28, 0.1);
        glVertex3f(48, 48, 0.1);
     glEnd();

     glBegin(GL_POLYGON); //Vidro Segunda Porta Segunda Parte
        glVertex3f(50, 48, 0.1);
        glVertex3f(50, 28, 0.1);
        glVertex3f(66, 28, 0.1);
        glVertex3f(58, 48, 0.1);
     glEnd();
}

void Desenha() //Rotina que Desenha
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(GIRAR,CIMA,BAIXO);//Mover o carro para qualquer sentido
    glTranslatef(0, 0, -50.2);
    glTranslatef(0, 0,  50.2);

    CarroLateral1();
    glTranslatef(0, 0, -50);
    CarroLateral2();
    glTranslatef(0, 0,  50);

    CarroFrenteCimaAtras();

    glTranslatef(50, 0, -5);
    Roda();
    glTranslatef(-50, 0, 5);
    glTranslatef( 50, 0, -51);
    Roda();
    glTranslatef(-50, 0, 51);

    glTranslatef(-40, 0, -5);
    Roda();
    glTranslatef(40, 0, 5);
    glTranslatef(-40, 0, -51);
    Roda();
    glTranslatef(40, 0, 51);

    glPopMatrix();

    glFlush();
    glutPostRedisplay();
}

int main()//Rotina Principal
{
    glutInitWindowSize(800,600);//Tamanho da tela
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Nilton Rodrigues Pereira - 5º Período SI UNIMONTES");
    glutDisplayFunc(Desenha);
    glutKeyboardFunc(Teclado);
    glutSpecialFunc(TecladoEspecial);
    Inicializa();
    glutMainLoop();
    return 0;
}
