#include "Carro.hpp"
Carro::Carro()
{
   _minha_base = new base(4);
   _angulo = 0;
   _posicao.setZero();
   _posicao(0,0) = 200;
   _posicao(1,0) = 200;
   _posicao(2,0) = 145;
   _angulo_roda = 0.f;
   _velocidade = 0;
   TPI = 6.2831853071795864769252867665590057683943387987502116419498f;
}

Carro::~Carro()
{
   delete _minha_base;
}

void Carro::draw()
{
   glPushMatrix();
   glTranslatef(_posicao(0,0),_posicao(1,0),_posicao(2,0));
   glRotatef(_angulo,0,0,1);

   /*Desenha Rodas*/
   glPushMatrix();
   glColor3f(0.f,0.f,0.f);
   glTranslatef(-150,-300,-100);
   glRotatef(_angulo_roda,1,0,0);
   desenhaRoda();
   glPopMatrix();
   ///////////////////////////////////////////////////////
   glPushMatrix();
   glTranslatef(150,-300,-100);
   glRotatef(_angulo_roda,1,0,0);
   desenhaRoda();
   glPopMatrix();
   ///////////////////////////////////////////////////////
   glPushMatrix();
   glTranslatef(-150,100,-100);
   glRotatef(_angulo_roda,1,0,0);
   desenhaRoda();
   glPopMatrix();
   ///////////////////////////////////////////////////////
   glPushMatrix();
   glTranslatef(150,100,-100);
   glRotatef(_angulo_roda,1,0,0);
   desenhaRoda();
   glPopMatrix();
   /*Desenha Rodas*/

   /*Desenhando a frente do caminhao*/
   glColor3f(.5f,.2f,.0f);
   glBegin(GL_QUAD_STRIP);
   glNormal3f(0.2f,0.2f,-1.f);
   glVertex3f(150,200,-100);

   glNormal3f(-0.2f,0.2f,-1.f);
   glVertex3f(-150,200,-100);

   glNormal3f(0.2f,-0.2f,-1.f);
   glVertex3f(150,-100,-100);

   glNormal3f(-0.2f,-0.2f,-1.f);
   glVertex3f(-150,-100,-100);
   glEnd();

   glBegin(GL_QUAD_STRIP);
   glNormal3f(0.2f,0.2f,1);
   glVertex3f(150,200,300);

   glNormal3f(-0.2f,0.2f,1);
   glVertex3f(-150,200,300);

   glNormal3f(0.2f,-0.2f,1);
   glVertex3f(150,-100,300);

   glNormal3f(-0.2f,-0.2f,1);
   glVertex3f(-150,-100,300);
   glEnd();

   glBegin(GL_QUAD_STRIP);
   glNormal3f(1,1,0.2f);
   glVertex3f(150,200,300);
   glNormal3f(1,1,-0.2f);
   glVertex3f(150,200,-100);

   glNormal3f(-1,1,0.2f);
   glVertex3f(-150,200,300);
   glNormal3f(-1,1,-0.2f);
   glVertex3f(-150,200,-100);

   glNormal3f(-1,-1,0.2f);
   glVertex3f(-150,-100,300);
   glNormal3f(-1,-1,-0.2f);
   glVertex3f(-150,-100,-100);

   glNormal3f(1,-1,0.2f);
   glVertex3f(150,-100,300);
   glNormal3f(1,-1,-0.2f);
   glVertex3f(150,-100,-100);

   glNormal3f(1,1,0.2f);
   glVertex3f(150,200,300);
   glNormal3f(1,1,-0.2f);
   glVertex3f(150,200,-100);
   glEnd();
   /*Desenhando a frente do caminhao*/

   /*Desenhando a parte de tras do caminhao*/
   glColor3f(.0f,.5f,.7f);
   glBegin(GL_QUAD_STRIP);
   glNormal3f(1,-1,-0.2f);
   glVertex3f(150,-450,-100);

   glNormal3f(-1,-1,-0.2f);
   glVertex3f(-150,-450,-100);

   glNormal3f(1,1,-0.2f);
   glVertex3f(150,-100,-100);

   glNormal3f(-1,1,-0.2f);
   glVertex3f(-150,-100,-100);
   glEnd();

   glBegin(GL_QUAD_STRIP);
   glNormal3f(1,-1,0.2f);
   glVertex3f(150,-450,85);

   glNormal3f(-1,-1,0.2f);
   glVertex3f(-150,-450,85);

   glNormal3f(1,1,0.2f);
   glVertex3f(150,-100,85);

   glNormal3f(-1,1,0.2f);
   glVertex3f(-150,-100,85);
   glEnd();

   glBegin(GL_QUAD_STRIP);
   glNormal3f(1,-1,-0.2f);
   glVertex3f(150,-450,-100);
   glNormal3f(1,-1,0.2f);
   glVertex3f(150,-450,85);

   glNormal3f(-1,-1,-0.2f);
   glVertex3f(-150,-450,-100);
   glNormal3f(-1,-1,0.2f);
   glVertex3f(-150,-450,85);

   glNormal3f(-1,1,-0.2f);
   glVertex3f(-150,-100,-100);
   glNormal3f(-1,1,0.2f);
   glVertex3f(-150,-100,85);

   glNormal3f(1,1,-0.2f);
   glVertex3f(150,-100,-100);
   glNormal3f(1,1,0.2f);
   glVertex3f(150,-100,85);

   glNormal3f(1,-1,-0.2f);
   glVertex3f(150,-450,-100);
   glNormal3f(1,-1,0.2f);
   glVertex3f(150,-450,85);
   glEnd();
   /*Desenhando a parte de tras do caminhao*/

   /*Desenhando o vidro do caminhao*/
   glColor3f(.1f,.1f,.5f);
   glBegin(GL_QUAD_STRIP);
   glNormal3f(0,1,0);
   glVertex3f(150,201,300);
   glNormal3f(0,1,0);
   glVertex3f(150,201,100);

   glNormal3f(0,1,0);
   glVertex3f(-150,201,300);
   glNormal3f(0,1,0);
   glVertex3f(-150,201,100);
   glEnd();
   /*Desenhando o vidro do caminhao*/


   glPushMatrix();
   glScalef(1.0f,1.0f,1.0f);
   _minha_base->draw();
   glPopMatrix();

   glPopMatrix();

}

void Carro::update()
{
   float parsedAngle = (_angulo*TPI)/360.f;
   _posicao(0,0) += -sin(parsedAngle)*_velocidade;
   _posicao(1,0) += cos(parsedAngle)*_velocidade;
   _posicao(2,0) += 0*_velocidade;
}

void Carro::desenhaRoda()
{
   glRotatef(90,0,1,0);
   glBegin(GL_QUAD_STRIP);
   for(float angle = 0.f ; angle <= 6.4 ; angle+=0.63f)
   {
      glNormal3f(cos(angle),sin(angle),0);
      glVertex3f(cos(angle)*50.f,sin(angle)*50.f,20);
      glNormal3f(cos(angle),sin(angle),0);
      glVertex3f(cos(angle)*50.f,sin(angle)*50.f,-20);
   }
   glEnd();

   glBegin(GL_TRIANGLE_FAN);
   glNormal3f(0,1,0);
   glVertex3f(0.f,0.f,20);
   for(float angle = 0.f ; angle <= 6.30 ; angle+=0.02f)
   {
      glNormal3f(0,1,0);
      glVertex3f(cos(angle)*50.f,sin(angle)*50.f,20);
   }
   glEnd();

   glBegin(GL_TRIANGLE_FAN);
   glNormal3f(0,1,0);
   glVertex3f(0.f,0.f,-20);
   for(float angle = 0.f ; angle <= 6.30 ; angle+=0.02f)
   {
      glNormal3f(0,1,0);
      glVertex3f(cos(angle)*50.f,sin(angle)*50.f,-20);
   }
   glEnd();
}

void Carro::aumentaAngulo()
{
   _angulo += (_velocidade*0.8f)/(1+_velocidade);
}

void Carro::diminuiAngulo()
{
   _angulo -= (_velocidade*0.8f)/(1+_velocidade);
}

void Carro::aumentaVelocidade()
{
   if(_velocidade < 100.f){
      _velocidade += (20 + _velocidade*10)/600;
   }
   _angulo_roda -= _velocidade/10.f;
}

void Carro::diminuiVelocidade()
{
   if(_velocidade > 0.f){
      _velocidade -= (20 + _velocidade*10)/600;
      _angulo_roda -= _velocidade/10.f;
      if(_velocidade < 0.f){
         _velocidade = 0.f;
         _angulo_roda = 0.f;
      }
   }
}
