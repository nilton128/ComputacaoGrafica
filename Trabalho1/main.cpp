/*****************************************************/
/*         Nilton Rodrigues Pereira            */
/*         Exercício-Programa (Trabalho 1)           */
/*****************************************************/

//Bibliotecas
#include <gl/gl.h>
#include <stdio.h>
#include <glut.h>
#include <stdlib.h>


/*protótipos */
void Inicializa();
void Teclado(unsigned char tecla, int a, int b);
void Quadrado ();
void QuadradoLinha();
void DesenhaN();
void DesenhaN1();
void DesenhaL();
void DesenhaT();
void DesenhaT1();
void DesenhaNome();
void Desenha();

void Inicializa() //Rotina Para Inicialização de Parâmetros
{
    glClearColor(1, 1, 1, 0); //Cor da Janela - Branco
    glOrtho(-50, 50, -50, 50, -50, 50); //Subdivisão da Janela - Eixo X, Y e Z: de -100 a 100
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
}

void Teclado(unsigned char tecla, int a, int b) //Rotina Para uso do Teclado Padrão
{
    switch(tecla)
    {
    case 27: // ESC para terminar
        exit(0);
        break;
    }
}

void Quadrado () //Desenha um Quadrado
{
    glBegin(GL_QUADS);
    //x    y   z
    glVertex3f(-50, -50, 0);
    glVertex3f(-50, -40, 0);
    glVertex3f(-40, -40, 0);
    glVertex3f(-40, -50, 0);
    glEnd();
}

void QuadradoLinha()
{
    Quadrado();

    glTranslatef( 20, 0, 0);
    Quadrado();
    glTranslatef( -20, 0, 0);

    glTranslatef( 40, 0, 0);
    Quadrado();
    glTranslatef( -40, 0, 0);

    glTranslatef( 60, 0, 0);
    Quadrado();
    glTranslatef( -60, 0, 0);

    glTranslatef( 80, 0, 0);
    Quadrado();
    glTranslatef( -80, 0, 0);

    glTranslatef( 100, 0, 0);
    Quadrado();
    glTranslatef( -100, 0, 0);

}

void DesenhaN()
{

    glBegin(GL_QUADS);
    //x    y   z
    glVertex3f(-20, 10, 1);
    glVertex3f(-15, 10, 1);
    glVertex3f(-15, 30, 1);
    glVertex3f(-20, 30, 1);
    glEnd();

}

void DesenhaN1()
{

    glBegin(GL_QUADS);
    //x    y   z
    glVertex3f(-15, 30, 1);
    glVertex3f(-15, 20, 1);
    glVertex3f(-5, 10, 1);
    glVertex3f(-5, 15, 1);
    glEnd();

}

void DesenhaL()
{
    glBegin(GL_QUADS);
    //x    y   z
    glVertex3f(20, 10, 1);
    glVertex3f(25, 10, 1);
    glVertex3f(25, 15, 1);
    glVertex3f(20, 15, 1);
    glEnd();

}

void DesenhaT()
{

    glBegin(GL_QUADS);
    //x    y   z
    glVertex3f(25, 25, 1);
    glVertex3f(25, 30, 1);
    glVertex3f(40, 30, 1);
    glVertex3f(40, 25, 1);
    glEnd();

}

void DesenhaT1()
{
    glBegin(GL_QUADS);
    //x    y   z
    glVertex3f(30, 10, 1);
    glVertex3f(35, 10, 1);
    glVertex3f(35, 25, 1);
    glVertex3f(30, 25, 1);
    glEnd();

}

void DesenhaNome()
{
    //Inicio do desenho das letras NILT
    glColor3f(1, 0, 0);//Cor das Figuras Geométricas que Formam a Letra "N"
    DesenhaN();
    //x y z
    glTranslatef(15,0,0);
    DesenhaN();
    glTranslatef(-15,0,0);

    DesenhaN1();
    glColor3f(0, 0, 1); //Cor das Figuras Geométricas que Formam a Letra "I"
    glTranslatef(25,0,0);
    DesenhaN();
    glTranslatef(-25,0,0);

    glColor3f(0 ,1, 0); //Cor das Figuras Geométricas que Formam a Letra "L"
    glTranslatef(35,0,0);

    DesenhaN();
    glTranslatef(-35,0,0);
    DesenhaL();

    glColor3f(1,1,0); //Cor das Figuras Geométricas que Formam a Letra "T"
    DesenhaT1();
    DesenhaT();

}

void Desenha() //Rotina que Desenha
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(0, 0, 0);
    //Inicio do tabuleiro
    glTranslatef(10,10,0);
    QuadradoLinha();
    glTranslatef(-10,-10,0);

    QuadradoLinha();
    glTranslatef(0,20,0);
    QuadradoLinha();
    glTranslatef(0,-20,0);

    glTranslatef(10,30,0);
    QuadradoLinha();
    glTranslatef(-10,-30,0);

    glTranslatef(0,40,0);
    QuadradoLinha();
    glTranslatef(0,-40,0);

    //Inicio das Linhas do lado direito
    glBegin(GL_LINES);
    glVertex3f(0, 10, 0); // Inicio da linha
    glVertex3f(40, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0, 20, 0); // Inicio da linha
    glVertex3f(30, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0, 30, 0); // Inicio da linha
    glVertex3f(20, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0, 40, 0); // Inicio da linha
    glVertex3f(10, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( -50, 0, 0); // Inicio da linha
    glVertex3f(50, 0, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( -50, 10, 0); // Inicio da linha
    glVertex3f(-10, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( -50, 20, 0); // Inicio da linha
    glVertex3f(-20, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( -50, 30, 0); // Inicio da linha
    glVertex3f(-30, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( -50, 40, 0);// Inicio da linha
    glVertex3f(-40, 50, 0); //Fim da linha
    glEnd();
    //----
    glBegin(GL_LINES);
    glVertex3f(0, 0, 0); // Inicio da linha
    glVertex3f(-50, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0, 10, 0); // Inicio da linha
    glVertex3f(-40, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0, 20, 0); // Inicio da linha
    glVertex3f(-30, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0, 30, 0); // Inicio da linha
    glVertex3f(-20, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(0, 40, 0); // Inicio da linha
    glVertex3f(-10, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( -50, 0, 0); // Inicio da linha
    glVertex3f(50, 0, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( -50, 10, 0); // Inicio da linha
    glVertex3f(-10, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( -50, 20, 0); // Inicio da linha
    glVertex3f(-20, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( -50, 30, 0); // Inicio da linha
    glVertex3f(-30, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( -50, 40, 0);// Inicio da linha
    glVertex3f(-40, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( -10, 0, 0);// Inicio da linha
    glVertex3f(-50, 40, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( -20, 0, 0);// Inicio da linha
    glVertex3f(-50, 30, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( -30, 0, 0);// Inicio da linha
    glVertex3f(-50, 20, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( -40, 0, 0);// Inicio da linha
    glVertex3f(-50, 10, 0); //Fim da linha
    glEnd();

    //Desenho das linhas do lado esquerdo
    glBegin(GL_LINES);
    glVertex3f( -50, 0, 0); // Inicio da linha
    glVertex3f(0, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( -40, 0, 0); // Inicio da linha
    glVertex3f(0, 40, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( -30, 0, 0); // Inicio da linha
    glVertex3f(0, 30, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( -20, 0, 0); // Inicio da linha
    glVertex3f(0, 20, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( -10, 0, 0); // Inicio da linha
    glVertex3f(0, 10, 0); //Fim da linha
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f( 40, 0, 0);// Inicio da linha
    glVertex3f( 50, 10, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( 30, 0, 0);// Inicio da linha
    glVertex3f( 50, 20, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( 20, 0, 0);// Inicio da linha
    glVertex3f( 50, 30, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( 10, 0, 0);// Inicio da linha
    glVertex3f( 50, 40, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( 0, 0, 0);// Inicio da linha
    glVertex3f( 50, 50, 0); //Fim da linha
    glEnd();
    //--------
    glBegin(GL_LINES);
    glVertex3f(50, 0, 0); // Inicio da linha
    glVertex3f(0, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(40, 0, 0); // Inicio da linha
    glVertex3f(0, 40, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(30, 0, 0); // Inicio da linha
    glVertex3f(0, 30, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(20, 0, 0); // Inicio da linha
    glVertex3f(0, 20, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(10, 0, 0); // Inicio da linha
    glVertex3f(0, 10, 0); //Fim da linha
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex3f( 40, 0, 0);// Inicio da linha
    glVertex3f( 50, 10, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( 30, 0, 0);// Inicio da linha
    glVertex3f( 50, 20, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( 20, 0, 0);// Inicio da linha
    glVertex3f( 50, 30, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( 10, 0, 0);// Inicio da linha
    glVertex3f( 50, 40, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f( 50, 0, 0);// Inicio da linha
    glVertex3f( 0, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(50, 10, 0); // Inicio da linha
    glVertex3f(10, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(50, 20, 0); // Inicio da linha
    glVertex3f(20, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(50, 30, 0); // Inicio da linha
    glVertex3f(30, 50, 0); //Fim da linha
    glEnd();

    glBegin(GL_LINES);
    glVertex3f(50, 40, 0); // Inicio da linha
    glVertex3f(40, 50, 0); //Fim da linha
    glEnd();
    DesenhaNome();
    glFlush();

}

int main() //Função Principal
{
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Nilton Rodrigues - 5º Período SI UNIMONTES - T1");
    glutDisplayFunc(Desenha);
    glutKeyboardFunc(Teclado);
    Inicializa();
    glutMainLoop();
    return 0;
}
