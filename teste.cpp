//
//  Transformacoes2
//
//  Created by Marcelo Costa on 15/12/12.
//  Copyright (c) 2012 Universidade Federal de Alagoas - UFAL. All rights reserved.
//



#include <iostream>
//LINUX #include <GL/glut.h>
#include <GL/glut.h>


void init (void)
{
  /* selecionar cor de fundo (preto) */
  glClearColor(0.0, 0.0, 0.0, 0.0);

  glMatrixMode(GL_PROJECTION); //Projecao 2D
  gluOrtho2D(0.0, 600.0, 0.0, 400.0); //Definindo os limites da Porta de Visao (ViewPort)

}

//desenha as transformacoes / Opengl= máquina de estado (cima -> baixo)
// Composicao de Matriz: Baixo -> Cima
void displayRet(void){
	
	//limpa o display
	/*glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1,0.0);
    
    glTranslatef(100,100,0.0);
    glRotatef(30,0,0,1);
    glTranslatef(-100,-100,0.0);
    
    glRecti(100,100,200,200);

    */

   /*   glColor3f(1.0,1.0,0.0);
   glBegin(GL_POLYGON);
        glVertex3f(249.0f,250.0f,-1.0f);
        glVertex3f(251.0f,250.0f,-1.0f);
        glVertex3f(249.0f,100.0f,-1.0f);
        glVertex3f(251.0f,100.0f,-1.0f);


    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(250.0f,250.0f);
        glVertex2f(300.0f,200.0f);
        glVertex2f(270.0f,270.0f);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(250.0f,250.0f);
        glVertex2f(300.0f,200.0f);
        glVertex2f(270.0f,270.0f);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(250.0f,250.0f);
        glVertex2f(300.0f,200.0f);
        glVertex2f(270.0f,270.0f);
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(250.0f,250.0f);
        glVertex2f(300.0f,200.0f);
        glVertex2f(270.0f,270.0f);
    glEnd();*/

  
  //executa os comandos
	glFlush();

}


void exit(unsigned char key, int x, int y)	{

	if( key == 'q' )
		exit(0);
}


int main(int argc, char *argv[]) {
	
	/* inicializa o sitema GLUT */
	glutInit(&argc, argv);									

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600,400);		
	glutInitWindowPosition(100,100);				
	glutCreateWindow("Retangulos");	

	//chama a funcao init e inicia as propriedades View Port
	init(); 
	/* Callback para mostrar objetos na tela */
	glutDisplayFunc(displayRet);					
	/* Callback para para interagir com teclado */
	glutKeyboardFunc(exit);						
	/* inicia o processamento dos eventos... */
	glutMainLoop();										

}