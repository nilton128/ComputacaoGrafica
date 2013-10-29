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

void Inicializa();
void Calcula();
void Teclado();
void RetanguloPrimeiro();
void Roda(float translateX, float translateY, float rotateMove);
void MovimentaRoda(int distInicial);
void Desenha();

float MOV = 0, ACRES1 = 0.09, ACRES2 = 0.5, MOVE_DIR = 0, MOVE_ESQ = 0;
int vezDesenho = 0;

void Inicializa() //Rotina Para Inicialização de Parâmetros
{
     glClearColor(0.9, 0.9, 0.9, 0); //Cor da Janela - CINZA
     glOrtho(-100, 100, -80, 100, -100, 100); //Subdivisão da Janela
     glEnable(GL_DEPTH_TEST);
     glEnable(GL_LINE_SMOOTH);
}


int main(){

}
