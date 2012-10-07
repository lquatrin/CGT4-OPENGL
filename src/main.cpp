/*******************
 *         CG T4
 *   Leonardo Quatrin Campagnolo - 2910019
 *   ->Implementação de um braço mecânico
 *   ->Utilize 'q' e 'e' para mover o braço
 *   ->O braço que será movido é o marcado por verde
 *   ->Seta para cima e para baixo irão selecionar o braço que deseja movimentar
 *   ->Seta de esquerda e direita movimentam a base do braço
 *   ->'w' 's' 'd' 'a' para movimentação do carro
 *
 * Para o trabalho foi usado o glfw tendo como base o Exemplo básico da GLFW feito por Yuri Kunde Schlesner © 2011.
 * Site: http://www.glfw.org/
 */
#include <iostream>
#include <GL/glfw.h>
#include <GL/glut.h>
#include "base.hpp"
#include "Input.h"
#include "Carro.hpp"

void enableLight()
{
   glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER,GL_TRUE);
   glEnable(GL_DEPTH_TEST);
   glEnable(GL_LIGHTING);
   
   glEnable(GL_LIGHT0);

   GLfloat light_0_position[] = {10000.0f, 10000.0f, 500.0f, 1.0f};
   GLfloat light_0_difuse[] = { 0.5f, .5f, 0.f, 1.0f }; 
   GLfloat light_0_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
   GLfloat light_0_ambient[] = { 0.2f, 0.2f, 0.2f,  1.0f };
   
   glLightfv(GL_LIGHT0, GL_POSITION, light_0_position);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, light_0_difuse);
   glLightfv(GL_LIGHT0, GL_SPECULAR, light_0_specular);
   glLightfv(GL_LIGHT0, GL_AMBIENT, light_0_ambient);
   
   glEnable(GL_LIGHT1);
   
   GLfloat light_1_position[] = { -10000.0f, -10000.0f, 500.0f, 0.f };
   GLfloat light_1_difuse[] = { 0.f, 0.f, 1.0f, 1.0f}; 
   GLfloat light_1_specular[] = { 1.f, 1.f, 1.f, 1.0f  }; 
   GLfloat light_1_ambient[] = { 0.4f, 0.4f, 0.4f, 1.0f };

   glLightfv(GL_LIGHT1, GL_POSITION, light_1_position);
   glLightfv(GL_LIGHT1, GL_DIFFUSE, light_1_difuse);
   glLightfv(GL_LIGHT1, GL_SPECULAR, light_1_specular);
   glLightfv(GL_LIGHT1, GL_AMBIENT, light_1_ambient); 

   glEnable(GL_LIGHT2);
   
   GLfloat light_2_position[] = { 0.0f, 0.0f, 50000.0f, 0.f };
   GLfloat light_2_difuse[] = { 1.f, 1.f, 1.f, 1.0f}; 
   GLfloat light_2_specular[] = { 1.f, 1.f, 1.f, 1.0f  }; 
   GLfloat light_2_ambient[] = { 0.4f, 0.4f, 0.4f, 1.0f };

   glLightfv(GL_LIGHT2, GL_POSITION, light_2_position);
   glLightfv(GL_LIGHT2, GL_DIFFUSE, light_2_difuse);
   glLightfv(GL_LIGHT2, GL_SPECULAR, light_2_specular);
   glLightfv(GL_LIGHT2, GL_AMBIENT, light_2_ambient); 

   GLfloat lmodel_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
   
   glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
   glEnable(GL_COLOR_MATERIAL);
   GLfloat mat_specular[] = { 1.f, 1.f, 1.f, 1.f };
   GLfloat mat_shininess[] = { 60 };
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
   GLfloat mat_diffuse[] = { 0.2f, 0.2f, 0.2f,1.0f };
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   GLfloat mat_ambiental[] = { 0.2f, 0.2f, 0.2f,1.0f };
   glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambiental);

}

float r, g, b;
Carro *mCarro;
Input *p = new Input();

void initMyClasses()
{
   mCarro = new Carro();
}

int zoomz;
int zoom;
int yyy;
int xxx;
void render()
{
   xxx = zoom*sin(mCarro->_angulo*mCarro->TPI/360);
   yyy = -zoom*cos(mCarro->_angulo*mCarro->TPI/360);

   glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


   glPushMatrix();
   glLoadIdentity();
   gluLookAt( mCarro->_posicao(0,0)+xxx, mCarro->_posicao(1,0)+yyy, mCarro->_posicao(2,0)+zoomz,
      mCarro->_posicao(0,0), mCarro->_posicao(1,0), mCarro->_posicao(2,0),
              0  , 0  , 1  );
   

   glBegin(GL_QUADS);
   glColor3f(1.f,1.f,1.f);
   glNormal3f(.0f,.0f,1.f);
   glVertex3i(10000,10000,0);

   glNormal3f(.0f,.0f,1.f);
   glVertex3i(-10000,10000,0);

   glNormal3f(.0f,.0f,1.f);
   glVertex3i(-10000,-10000,0);

   glNormal3f(.0f,.0f,1.f);
   glVertex3i(10000,-10000,0);

   glNormal3f(.0f,.0f,1.f);
   glVertex3i(10000,10000,0);
   glEnd();

   glPushMatrix();
   glBegin(GL_LINES);
   glNormal3f(0.f,0.f,1.f);
      glColor3f(1.f,0.f,0.f);
      glVertex3i(0,0,0);
      glVertex3i(100,0,0);

      glColor3f(0.f,1.f,0.f);
      glVertex3i(0,0,0);
      glVertex3i(0,100,0);

      glColor3f(0.f,0.f,1.f);
      glVertex3i(0,0,0);
      glVertex3i(0,0,100);
   glEnd();
   glPopMatrix();
   
   mCarro->draw();

   // Exibe buffer na tela.
	glfwSwapBuffers();
   //glFlush();
}

void GLFWCALL functionname( int character, int action )
{
   if(character == 284 && action == GLFW_RELEASE)
   {
      if(mCarro->_minha_base->_marcado->_antBraco != NULL){
         mCarro->_minha_base->_marcado->mudaMarcado();
         mCarro->_minha_base->_marcado = mCarro->_minha_base->_marcado->_antBraco;
         mCarro->_minha_base->_marcado->mudaMarcado();
      }
   }
   if(character == 283 && action == GLFW_RELEASE)
   {
      if(mCarro->_minha_base->_marcado->_proxBraco != NULL){
         mCarro->_minha_base->_marcado->mudaMarcado();
         mCarro->_minha_base->_marcado = mCarro->_minha_base->_marcado->_proxBraco;
         mCarro->_minha_base->_marcado->mudaMarcado();
      }
   }


      if(action == GLFW_PRESS){
         p->keyboard[(char)character] = true;
      }else if(action == GLFW_RELEASE){
         p->keyboard[(char)character] = false;   
      }
}


int main()
{
   // Inicialização da biblioteca. Deve ser chamado antes de qualquer outra função da GLFW.
   glfwInit();
   p = new Input();
   initMyClasses();
   zoom = 3000;
   zoomz = 1500;
   // Seta janela para ser não redimensionavel.
   glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);
   // Abre janela, com tamanho 800x600, 8 bits de cor, 24 de profundidade, e 8 de stencil.
   glfwOpenWindow(800, 600, 8, 8, 8, 8, 24, 8, GLFW_WINDOW);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45, 800/600, 1, 50000);
   glMatrixMode(GL_MODELVIEW);
   glViewport(0, 0, 800, 600);

   glfwSetKeyCallback(functionname);

   enableLight();

   glEnable(GL_NORMALIZE);

   glShadeModel(GL_SMOOTH);

   bool running = true;

   while (running)
   {
      // Verifica se a tecla R esta pressionada.
      // Para receber eventos imediatamente quando uma tecla é pressionada (para, por exemplo, entrada de texto), registre
      // uma callback usando glfwSetKeyCallback/glfwSetCharCallback. (Consulte o manual.)
      if(p->keyboard['Q'])
      {
         if(mCarro->_minha_base->_marcado!= NULL)
            mCarro->_minha_base->_marcado->aumentaAngulo();
      }else if(p->keyboard['E'])
      {
         if(mCarro->_minha_base->_marcado != NULL)
            mCarro->_minha_base->_marcado->diminuiAngulo();
      }
      if(p->keyboard[(char)285])
      {
         mCarro->_minha_base->aumentaAngulo();
      }else if(p->keyboard[(char)286])
      {
         mCarro->_minha_base->diminuiAngulo();
      }

      if(p->keyboard['A'])
      {
         mCarro->aumentaAngulo();
      }else if(p->keyboard['D'])
      {
         mCarro->diminuiAngulo();
      }

      if(p->keyboard['W'])
      {
         mCarro->aumentaVelocidade();
      }else
      {
         mCarro->diminuiVelocidade();
      }

      if(p->keyboard['S'])
      {
         mCarro->diminuiVelocidade();
      }
      if(p->keyboard['Z'])
      {
         if(zoom < 6000){
            zoom += 20;
            zoomz += 10;
         }
      }else if(p->keyboard['X'])
      {
         if(zoom > 1500){
            zoom -= 20;
            zoomz -= 10;
         }
      }

      mCarro->update();
      // Pega a posição atual do mouse dentro da janela.
      int xpos, ypos;
      glfwGetMousePos(&xpos, &ypos);

      b = (float)xpos / 800.f;


      render();

		// Se a janela foi fechada, pare o loop.
		running = glfwGetWindowParam(GLFW_OPENED) != 0;
	}

	// De-inicializa a GLFW.
	glfwTerminate();
}