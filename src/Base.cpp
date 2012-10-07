#include "Base.hpp"
#include <GL/glfw.h>


base::base(int numeroDeBracos)
{
   _posicaoCentro.setZero();
   _posicaoCentro(0,0) = 0;
   _posicaoCentro(1,0) = -280;
   _posicaoCentro(2,0) = 80;

   _altura = 10;
   _raio = 100;
   _proxBraco = NULL;
   _angulo_da_base = 80.f;
   _marcado = NULL;

   numeroDeBracos = numeroDeBracos-1;
   if(!(numeroDeBracos < 0))
   {
      _proxBraco = new Braco(numeroDeBracos);
      _marcado = _proxBraco;
      _marcado->mudaMarcado();
   }
}

base::~base()
{
   if(_proxBraco != NULL)
      delete _proxBraco;
}

void base::draw()
{
   glPushMatrix();

   glTranslatef(_posicaoCentro(0,0),
      _posicaoCentro(1,0),
      _posicaoCentro(2,0));
   glRotatef(_angulo_da_base,0,0,1);
   glColor3f(1.f,1.f,1.f);

   glBegin(GL_QUAD_STRIP);
   for(float angle = 0.f ; angle <= 6.30 ; angle+=0.01f)
   {
      glNormal3f(cos(angle),sin(angle),1.0);
      glVertex3f(cos(angle)*_raio,sin(angle)*_raio,_altura);
      glNormal3f(cos(angle),sin(angle),1.0);
      glVertex3f(cos(angle)*_raio,sin(angle)*_raio,-_altura);
   }
   glEnd();

   glBegin(GL_TRIANGLE_FAN);
   glNormal3f(0,0,1.0);
   glVertex3f(0.f,0.f,_altura);
   for(float angle = 0.f ; angle <= 6.30 ; angle+=0.01f)
   {
      glNormal3f(0,0,1.0);
      glVertex3f(cos(angle)*_raio,sin(angle)*_raio,_altura);
   }
   glEnd();

   glBegin(GL_TRIANGLE_FAN);
   glNormal3f(0,0,1.0);
   glVertex3f(0.f,0.f,-_altura);
   for(float angle = 0.f ; angle <= 6.30 ; angle+=0.01f)
   {
      glNormal3f(0,0,-1.0);
      glVertex3f(cos(angle)*_raio,sin(angle)*_raio,-_altura);
   }
   glEnd();

   glPushMatrix();
   glTranslatef(0,0,_altura*2);
   glColor3f(1.f,0.f,0.f);
   float divide = 1.6f;
   glBegin(GL_QUAD_STRIP);
   for(float angle = 0.f ; angle <= 6.30 ; angle+=0.01f)
   {
      glNormal3f(cos(angle),sin(angle),1.0);
      glVertex3f(cos(angle)*_raio/divide,sin(angle)*_raio/divide,_altura);
      glNormal3f(cos(angle),sin(angle),1.0);
      glVertex3f(cos(angle)*_raio/divide,sin(angle)*_raio/divide,-_altura);
   }
   glEnd();

   glBegin(GL_TRIANGLE_FAN);
   glNormal3f(0,0,1.0);
   glVertex3f(0.f,0.f,_altura);
   for(float angle = 0.f ; angle <= 6.30 ; angle+=0.01f)
   {
      glNormal3f(0,0,1.0);
      glVertex3f(cos(angle)*_raio/divide,sin(angle)*_raio/divide,_altura);
   }
   glEnd();

   glBegin(GL_TRIANGLE_FAN);
   glNormal3f(0,0,1.0);
   glVertex3f(0.f,0.f,-_altura);
   for(float angle = 0.f ; angle <= 6.30 ; angle+=0.01f)
   {
      glNormal3f(0,0,-1.0);
      glVertex3f(cos(angle)*_raio/divide,sin(angle)*_raio/divide,-_altura);
   }
   glEnd();

   glPushMatrix();
   glTranslatef(0,0,_altura+.5f);
   float r = 80.f;
   glColor3f(.0f,.0f,1.0f);
   glBegin(GL_QUADS);
   glNormal3f(0.f,0.f,1.0);
   glVertex3f(r,r,0);
   glNormal3f(0.f,0.f,1.0);
   glVertex3f(-r,r,0);
   glNormal3f(0.f,0.f,1.0);
   glVertex3f(-r,-r,0); 
   glNormal3f(0.f,0.f,1.0);
   glVertex3f(r,-r,0);
   glEnd();
   glBegin(GL_QUADS);
   glNormal3f(0.f,0.f,1.0);
   glVertex3f(r,r,-10);
   glNormal3f(0.f,0.f,1.0);
   glVertex3f(-r,r,-10);
   glNormal3f(0.f,0.f,1.0);
   glVertex3f(-r,-r,-10);
   glNormal3f(0.f,0.f,1.0);
   glVertex3f(r,-r,-10);
   glEnd();
   glBegin(GL_QUAD_STRIP);
   glNormal3f(0.f,0.f,1.0);
   glVertex3f(r,r,0);
   glNormal3f(0.f,0.f,1.0);
   glVertex3f(r,r,-10);

   glNormal3f(0.f,0.f,1.0);
   glVertex3f(-r,r,0);
   glNormal3f(0.f,0.f,1.0);
   glVertex3f(-r,r,-10);

   glNormal3f(0.f,0.f,1.0);
   glVertex3f(-r,-r,0);
   glNormal3f(0.f,0.f,1.0);
   glVertex3f(-r,-r,-10);

   glNormal3f(0.f,0.f,1.0);
   glVertex3f(r,-r,0);
   glNormal3f(0.f,0.f,1.0);
   glVertex3f(r,-r,-10);

   glNormal3f(0.f,0.f,1.0);
   glVertex3f(r,r,0);
   glNormal3f(0.f,0.f,1.0);
   glVertex3f(r,r,-10);
   glEnd();
   glTranslatef(0.f,20.f,0.f);
   if(_proxBraco != NULL)
   {
      _proxBraco->draw();
   }

   glPopMatrix();
   glPopMatrix();
   glPopMatrix();
}

void base::aumentaAngulo()
{
   _angulo_da_base += 0.5f;
}

void base::diminuiAngulo()
{
   _angulo_da_base -= 0.5f;
}
