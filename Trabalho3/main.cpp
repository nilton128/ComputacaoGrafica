/*****************************************************/
/*         Nilton Rodrigues Pereira             */
/*         Exercício-Programa (Trabalho 3)           */
/*****************************************************/

//Bibliotecas
#include <gl/gl.h>
#include <stdio.h>
#include <glut.h>
#include <stdlib.h>
#include <math.h>

//Protótipos de funções
void Inicializa();
void Calcula();
void Teclado();
void Retangulo();
void Roda(float translateX, float translateY, float rotateMove);
void MovimentaRoda(int distInicial);
void Desenha();

//Variáveis Blobais
float MOV = 0, ACRES1 = 0.05, ACRES2 = 0.4, MOVE_DIR = 0, MOVE_ESQ = 0;
int vezDesenho = 0;

void Inicializa() //Função Para Inicialização de Parâmetros
{
     glClearColor(0.9, 0.9, 0.9, 0); //Cor da Janela - CINZA
     glOrtho(-100, 100, -80, 100, -100, 100); //Subdivisão da Janela
     glEnable(GL_DEPTH_TEST);
     glEnable(GL_LINE_SMOOTH);
}

void Calcula() //Função que faz o constante incremento das várias usadas no movimento da roda
{
     MOV = MOV + ACRES1;
     MOVE_DIR = MOVE_DIR - ACRES2;
     MOVE_ESQ = MOVE_ESQ + ACRES2;
}

void Teclado(unsigned char tecla, int a, int b) //Função Para uso do Teclado Padrão
{
     switch(tecla)
     {
       case 27: // ESC para terminar
            exit(0);
       break;
     }
}

void Retangulo() //Desenha um Retangulo
{
    /********PLATAFORMA********/
     glBegin(GL_POLYGON);
       glVertex3f(50, 60, 0);
       glVertex3f(60, 60, 0);
       glVertex3f(60, 65, 0);
       glVertex3f(45,65, 0);
       glVertex3f(0,20, 0);
       glVertex3f(0,10, 0);
     glEnd();

     glBegin(GL_POLYGON);
        glVertex3f(90, 45, 0);
        glVertex3f(90, 50, 0);
        glVertex3f(95, 50, 0);
        glVertex3f(95, 40, 0);
        glVertex3f(50, 40, 0);
        glVertex3f(50, 45, 0);
     glEnd();

     glBegin(GL_POLYGON);
        glVertex3f(40, 15, 0);
        glVertex3f(40, 20, 0);
        glVertex3f(35, 20, 0);
        glVertex3f(35, 10, 0);
        glVertex3f(95, 10, 0);
        glVertex3f(95, 15, 0);
     glEnd();
}

void Roda(float translateX, float translateY, float rotateMove) //Função que Desenha Roda
{
     glPushMatrix();
         glTranslatef(translateX, translateY, 0);
         glRotatef(rotateMove, 0, 0, 1);
         glColor3f(0, 0, 0);
         glutSolidTorus(1, 4, 50, 50);
         glColor3f(1, 0, 0); //1º Retangulo que fica no meio da Roda e que cruza com o 2ª
         glBegin(GL_QUADS);
         glVertex3f(-1, 4, 0);
         glVertex3f( 1, 4, 0);
         glVertex3f( 1,-4, 0);
         glVertex3f(-1,-4, 0);
         glEnd();

         glBegin(GL_QUADS); //2º Retangulo que fica no meio da Roda e que cruza com o 1º
         glVertex3f( 4,-1, 0);
         glVertex3f( 4, 1, 0);
         glVertex3f(-4, 1, 0);
         glVertex3f(-4,-1, 0);
         glEnd();
     glPopMatrix();
}

void MovimentaRoda(int distInicial) //Função Que Faz a Roda Movimentar
{
    vezDesenho = 0;//Variavel Controladora responsavel por informar qual IF será ativado e assim onde a roda será desenhada

    //IFS DE LIMITE - Responsaveis por limitar até onde a roda deve ser desenhada por um "IF DE DESENHO"
    if (MOV >= 60 + distInicial){
      vezDesenho = 1;
    }
    if (MOV >= 80 + distInicial){
      vezDesenho = 2;
    }
    if (MOV >= 85 + distInicial){
      vezDesenho = 3;
    }
    if (MOV >=90 + distInicial){
      vezDesenho = 4;
    }
    if (MOV >=105 + distInicial){
      vezDesenho = 5;
    }
    if (MOV >=150 + distInicial){
      vezDesenho = 6;
    }
    if (MOV >=153 + distInicial){
      vezDesenho = 7;
    }

    //IFs DE DESENHO - Desenham a roda andando sobre a linha ou em queda de um determinado ponto a outro.
    //Cada IF irá desenhar em um Local Espefico.
    if (vezDesenho == 0){
      Roda(-25+MOV+distInicial ,MOV+distInicial , MOVE_DIR);//Faz a roda subir
    }
    if (vezDesenho == 1){
      Roda(65, distInicial + 130 - MOV, MOVE_DIR);//Roda cair
    }
    if (vezDesenho == 2){
      Roda((-distInicial) - 5 + MOV, 50, MOVE_DIR);//Roda ir a direita
    }
    if (vezDesenho == 3){
      Roda(distInicial + 150 - MOV, 50, MOVE_ESQ);//Roda ir a Esquerda
    }
    if (vezDesenho == 4){
      Roda(45, distInicial + 130 - MOV, MOVE_DIR);//Roda cair
    }
    if (vezDesenho == 5){
      Roda((-distInicial-5) -55 + MOV, 20, MOVE_DIR);//Roda ir a direita
    }
    if (vezDesenho == 6){
      Roda(95, distInicial + 130 - MOV, MOVE_DIR);//Roda cair
    }
    if (vezDesenho == 7){  //IF que zera as variaveis e acarreta o inicio do processo novamente
      vezDesenho = 1;
      MOV = 0;
      MOVE_DIR = 0;
      MOVE_ESQ = 0;
   }

}

void Desenha() //Rotina que Desenha
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    MovimentaRoda(5); //Passando Argumentos de onde as rodas devem ser desenhadas inicialmente
    MovimentaRoda(-5);

    glColor3f (0, 1, 0);
    Retangulo();

    glFlush();
    glutPostRedisplay();
}

int main()//Função Principal
{
    glutInitWindowSize(700,600);//Dimensão da janela em pixels
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Nilton Rodrigues Pereira - 5º Período SI UNIMONTES");
    Inicializa();
    glutDisplayFunc(Desenha);
    glutKeyboardFunc(Teclado);
    glutIdleFunc(Calcula);
    glutMainLoop();
    return 0;
}
