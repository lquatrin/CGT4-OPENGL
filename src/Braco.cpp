#include "Braco.hpp"

Braco::Braco(int numeroDeBracos)
{
   TPI = 6.2831853071795864769252867665590057683943387987502116419498f;
   _sp = new Sphere(35.f);
   _altura = 300.f;
   _lados = 15.f;
   _angle = 0;
   _marcado = false;
   _antBraco = NULL;
   _proxBraco = NULL;
   _numero_de_adds = (float)(numeroDeBracos+1);
   numeroDeBracos = numeroDeBracos-1;
   _ps = new Pistao(100);
   if(!(numeroDeBracos < 0))
   {
      _proxBraco = new Braco(numeroDeBracos, 40.f);
      _proxBraco->_antBraco = this;
   }
}

Braco::Braco(int numeroDeBracos, float angle)
{
   TPI = 6.2831853071795864769252867665590057683943387987502116419498f;
   _altura = 300.f;
   _lados = 15.f;
   _angle = angle;
   _antBraco = NULL;
   _marcado = false;
   _sp = new Sphere(30.f);
   _proxBraco = NULL;
   _numero_de_adds = (float)(numeroDeBracos+1);
   numeroDeBracos = numeroDeBracos-1;
   _ps = new Pistao(100);
   if(!(numeroDeBracos < 0))
   {
      _proxBraco = new Braco(numeroDeBracos, _angle);
      _proxBraco->_antBraco = this;
   }
}

Braco::~Braco()
{
   if(_proxBraco != NULL)
      delete _proxBraco;
}

void Braco::draw()
{

   glPushMatrix();
   if(_marcado){
      glColor3f(0.0f,1.0f,0.f);
   }else{
      glColor3f(1.f,0.f,0.f);
   }


   /*Desenhar pistao*/
   if(_antBraco != NULL){
      float parsedAngle = (_angle*TPI)/360.f;
      Matriz<3,1> a1;
      Matriz<3,1> a2;
      a1.setZero();
      a2.setZero();
      a1(1,0) = -(_altura/3*-sin(parsedAngle));
      a1(2,0) = -(_altura/3*cos(parsedAngle));

      a2(1,0) = -(_altura/3*-sin(parsedAngle));
      a2(2,0) = -_altura/3-(_altura/3*cos(parsedAngle));
      a1 = normalizeVector3D(a1);
      a2 = normalizeVector3D(a2);

      Matriz<3,1> p1;
      Matriz<3,1> p2;
      p1.setZero();
      p2.setZero();
      p1(1,0) = -_lados;
      p1(2,0) = -_altura/3;
      p2(1,0) = ((_altura/3-_lados)*-sin(parsedAngle));
      p2(2,0) = (_altura/3*cos(parsedAngle));

      _ps->_deslocamento = sqrt( pow(p1(1,0) - p2(1,0) ,2) + pow(p1(2,0) - p2(2,0),2) ) - _ps->_altura;

      glPushMatrix();
      glPushMatrix();
      glTranslatef(0,-_lados,-(_altura/3));
      glRotatef(_angle,1.0f,0.0f,0.0f);

      Matriz<3,1> p;
      glBegin(GL_POLYGON);
      for(float x = 0; x < 1.f; x+=0.01f)
      {
         for(float y = 0; y < 1.f; y+=0.01f)
         {
            p = _ps->_sp->retPoint(x,y);
            glNormal3f(p(0,0),p(1,0),p(2,0));
            glVertex3f(p(0,0),p(1,0),p(2,0));
         }
      }
      glEnd();

      glPushMatrix();
      float dad2 = ((-_lados*cos(parsedAngle))
         +((_altura/2.f)*-sin(parsedAngle)));
      float dad = (_altura/2.f*cos(parsedAngle)
         +(-_lados*sin(parsedAngle)));
      if(!((dad > 0 && dad2 > 0) ||(dad < 0 && dad2 > 0)))
      {
         glRotatef(-(angleDotProduct2DYZ(a2,a1)*360)/TPI,1.0f,0.0f,0.0f);
      }else{
         glRotatef(-(angleDotProduct2DYZ(a2,a1)*360)/TPI,-1.0f,0.0f,0.0f);
      }

      float l1 = 10.f;
      glBegin(GL_QUAD_STRIP);
      glNormal3f(1.f,1.f,0.f);
      glVertex3f(l1,l1,_ps->_altura);
      glNormal3f(1.f,1.f,0.f);
      glVertex3f(l1,l1,0);

      glNormal3f(1.f,-1.f,0.f);
      glVertex3f(l1,-l1,_ps->_altura);
      glNormal3f(1.f,-1.f,0.f);
      glVertex3f(l1,-l1,0);

      glNormal3f(-1.f,-1.f,0.f);
      glVertex3f(-l1,-l1,_ps->_altura);
      glNormal3f(-1.f,-1.f,0.f);
      glVertex3f(-l1,-l1,0);

      glNormal3f(-1.f,1.f,0.f);
      glVertex3f(-l1,l1,_ps->_altura);
      glNormal3f(-1.f,1.f,0.f);
      glVertex3f(-l1, l1,0);

      glNormal3f(1.f,1.f,0.f);
      glVertex3f(l1,l1,_ps->_altura);
      glNormal3f(1.f,1.f,0.f);
      glVertex3f(l1,l1,0);
      glEnd();

      glPushMatrix();
      glTranslatef(0.f,0.f,_ps->_deslocamento);
      glBegin(GL_QUAD_STRIP);
      glNormal3f(1.f,1.f,0.f);
      glVertex3f(l1/2.f,l1/2.f,_ps->_altura);
      glNormal3f(1.f,1.f,0.f);
      glVertex3f(l1/2.f,l1/2.f,0);

      glNormal3f(1.f,-1.f,0.f);
      glVertex3f(l1/2.f,-l1/2.f,_ps->_altura);
      glNormal3f(1.f,-1.f,0.f);
      glVertex3f(l1/2.f,-l1/2.f,0);

      glNormal3f(-1.f,-1.f,0.f);
      glVertex3f(-l1/2.f,-l1/2.f,_ps->_altura);
      glNormal3f(-1.f,-1.f,0.f);
      glVertex3f(-l1/2.f,-l1/2.f,0);

      glNormal3f(-1.f,1.f,0.f);
      glVertex3f(-l1/2.f,l1/2.f,_ps->_altura);
      glNormal3f(-1.f,1.f,0.f);
      glVertex3f(-l1/2.f, l1/2.f,0);

      glNormal3f(1.f,1.f,0.f);
      glVertex3f(l1/2.f,l1/2.f,_ps->_altura);
      glNormal3f(1.f,1.f,0.f);
      glVertex3f(l1/2.f,l1/2.f,0);
      glEnd();
      glPopMatrix();
      glPopMatrix();

      glPopMatrix();
      glRotatef(_angle,1.0f,0.0f,0.0f);

      glTranslatef(0,-_lados,_altura/3);

      glBegin(GL_POLYGON);
      for(float x = 0; x < 1.f; x+=0.01f)
      {
         for(float y = 0; y < 1.f; y+=0.01f)
         {
            p = _ps->_sp->retPoint(x,y);
            glNormal3f(p(0,0),p(1,0),p(2,0));
            glVertex3f(p(0,0),p(1,0),p(2,0));
         }
      }
      glEnd();

      glPopMatrix();
   }else{
      float parsedAngle = (_angle*TPI)/360.f;
      Matriz<3,1> a1;
      Matriz<3,1> a2;
      a1.setZero();
      a2.setZero();
      a1(1,0) = -80-((-_lados*cos(parsedAngle))
         +((_altura/2.f)*-sin(parsedAngle)));
      a1(2,0) = -(_altura/2.f*cos(parsedAngle)
         +(-_lados*sin(parsedAngle)));

      a2(1,0) = -15-((-_lados*cos(parsedAngle))
         +((_altura/2.f)*-sin(parsedAngle)));
      a2(2,0) = -(_altura/2.f*cos(parsedAngle)
         +(-_lados*sin(parsedAngle)));
      a1 = normalizeVector3D(a1);
      a2 = normalizeVector3D(a2);

      Matriz<3,1> p1;
      Matriz<3,1> p2;
      p1.setZero();
      p2.setZero();
      p1(1,0) = -80;
      p2(1,0) = ((-_lados*cos(parsedAngle))
         +((_altura/2.f)*-sin(parsedAngle)));
      p2(2,0) = _altura/2.f*cos(parsedAngle)
         +(-_lados*sin(parsedAngle));

      _ps->_deslocamento = sqrt( pow(p1(1,0) - p2(1,0) ,2) + pow(p1(2,0) - p2(2,0),2) ) - _ps->_altura;

      glPushMatrix();
      glPushMatrix();
      glTranslatef(0,-80,0);
      glRotatef(_angle,1.0f,0.0f,0.0f);

      Matriz<3,1> p;
      glBegin(GL_POLYGON);
      for(float x = 0; x < 1.f; x+=0.01f)
      {
         for(float y = 0; y < 1.f; y+=0.01f)
         {
            p = _ps->_sp->retPoint(x,y);
            glNormal3f(p(0,0),p(1,0),p(2,0));
            glVertex3f(p(0,0),p(1,0),p(2,0));
         }
      }
      glEnd();
      glPushMatrix();

      float dad2 = ((-_lados*cos(parsedAngle))
         +((_altura/2.f)*-sin(parsedAngle)));
      float dad = (_altura/2.f*cos(parsedAngle)
         +(-_lados*sin(parsedAngle)));
      if((dad >= 15.f && dad2 > 0 )  || (dad >= -15.f && dad2 < 0))
      {
         glRotatef(-(angleDotProduct2DYZ(a2,a1)*360)/TPI,1.0f,0.0f,0.0f);
      }else{
         glRotatef(-(angleDotProduct2DYZ(a2,a1)*360)/TPI,-1.0f,0.0f,0.0f);
      }

      float l1 = 10.f;
      glBegin(GL_QUAD_STRIP);
      glNormal3f(1.f,1.f,0.f);
      glVertex3f(l1,l1,_ps->_altura);
      glNormal3f(1.f,1.f,0.f);
      glVertex3f(l1,l1,0);

      glNormal3f(1.f,-1.f,0.f);
      glVertex3f(l1,-l1,_ps->_altura);
      glNormal3f(1.f,-1.f,0.f);
      glVertex3f(l1,-l1,0);

      glNormal3f(-1.f,-1.f,0.f);
      glVertex3f(-l1,-l1,_ps->_altura);
      glNormal3f(-1.f,-1.f,0.f);
      glVertex3f(-l1,-l1,0);

      glNormal3f(-1.f,1.f,0.f);
      glVertex3f(-l1,l1,_ps->_altura);
      glNormal3f(-1.f,1.f,0.f);
      glVertex3f(-l1, l1,0);

      glNormal3f(1.f,1.f,0.f);
      glVertex3f(l1,l1,_ps->_altura);
      glNormal3f(1.f,1.f,0.f);
      glVertex3f(l1,l1,0);
      glEnd();

      glPushMatrix();
      glTranslatef(0.f,0.f,_ps->_deslocamento);
      glBegin(GL_QUAD_STRIP);
      glNormal3f(1.f,1.f,0.f);
      glVertex3f(l1/2.f,l1/2.f,_ps->_altura);
      glNormal3f(1.f,1.f,0.f);
      glVertex3f(l1/2.f,l1/2.f,0);

      glNormal3f(1.f,-1.f,0.f);
      glVertex3f(l1/2.f,-l1/2.f,_ps->_altura);
      glNormal3f(1.f,-1.f,0.f);
      glVertex3f(l1/2.f,-l1/2.f,0);

      glNormal3f(-1.f,-1.f,0.f);
      glVertex3f(-l1/2.f,-l1/2.f,_ps->_altura);
      glNormal3f(-1.f,-1.f,0.f);
      glVertex3f(-l1/2.f,-l1/2.f,0);

      glNormal3f(-1.f,1.f,0.f);
      glVertex3f(-l1/2.f,l1/2.f,_ps->_altura);
      glNormal3f(-1.f,1.f,0.f);
      glVertex3f(-l1/2.f, l1/2.f,0);

      glNormal3f(1.f,1.f,0.f);
      glVertex3f(l1/2.f,l1/2.f,_ps->_altura);
      glNormal3f(1.f,1.f,0.f);
      glVertex3f(l1/2.f,l1/2.f,0);
      glEnd();
      glPopMatrix();
      glPopMatrix();


      glPopMatrix();
      glRotatef(_angle,1.0f,0.0f,0.0f);

      glTranslatef(0,-_lados,_altura/2.f);

      glBegin(GL_POLYGON);
      for(float x = 0; x < 1.f; x+=0.01f)
      {
         for(float y = 0; y < 1.f; y+=0.01f)
         {
            p = _ps->_sp->retPoint(x,y);
            glNormal3f(p(0,0),p(1,0),p(2,0));
            glVertex3f(p(0,0),p(1,0),p(2,0));
         }
      }
      glEnd();

      glPopMatrix();
   }
   /*Desenhar pistao*/

   /*Desenhar braco*/
   glRotatef(_angle,1.0f,0.0f,0.0f);
   Matriz<3,1> p;
   glBegin(GL_POLYGON);
   for(float x = 0; x < 1.f; x+=0.01f)
   {
      for(float y = 0; y < 1.f; y+=0.01f)
      {
         p = _sp->retPoint(x,y);
         glNormal3f(p(0,0),p(1,0),p(2,0));
         glVertex3f(p(0,0),p(1,0),p(2,0));
      }
   }
   glEnd();

   glBegin(GL_QUAD_STRIP);
   glNormal3f(1.f,1.f,0.f);
   glVertex3f(_lados,_lados,_altura);
   glNormal3f(1.f,1.f,0.f);
   glVertex3f(_lados,_lados,0);
   glNormal3f(1.f,-1.f,0.f);
   glVertex3f(_lados,-_lados,_altura);
   glNormal3f(1.f,-1.f,0.f);
   glVertex3f(_lados,-_lados,0);
   glNormal3f(-1.f,-1.f,0.f);
   glVertex3f(-_lados,-_lados,_altura);
   glNormal3f(-1.f,-1.f,0.f);
   glVertex3f(-_lados,-_lados,0);
   glNormal3f(-1.f,1.f,0.f);
   glVertex3f(-_lados,_lados,_altura);
   glNormal3f(-1.f,1.f,0.f);
   glVertex3f(-_lados, _lados,0);
   glNormal3f(1.f,1.f,0.f);
   glVertex3f(_lados,_lados,_altura);
   glNormal3f(1.f,1.f,0.f);
   glVertex3f(_lados,_lados,0);
   glEnd();

   glBegin(GL_QUADS);
   glNormal3f(1.f,1.f,0.2f);
   glVertex3f(_lados,_lados,_altura);
   glNormal3f(1.f,-1.f,0.2f);
   glVertex3f(_lados,-_lados,_altura);
   glNormal3f(-1.f,-1.f,0.2f);
   glVertex3f(-_lados,-_lados,_altura);
   glNormal3f(-1.f,1.f,0.2f);
   glVertex3f(-_lados,_lados,_altura);

   glNormal3f(0.f,0.f,-1.f);
   glVertex3f(_lados,_lados,0);
   glNormal3f(0.f,0.f,-1.f);
   glVertex3f(_lados,-_lados,0);
   glNormal3f(0.f,0.f,-1.f);
   glVertex3f(-_lados,-_lados,0);
   glNormal3f(0.f,0.f,-1.f);
   glVertex3f(-_lados, _lados,0);
   glEnd(); 
   /*Desenhar braco*/

   //Transladar pro começo do outro braço
   glTranslatef(0,0,_altura);

   if(_proxBraco != NULL)
   {
      _proxBraco->draw();
   }
   glPopMatrix();
}

void Braco::aumentaAngulo()
{
   if(_ps->_deslocamento > _ps->_Min_deslocamento)
      _angle += 0.8f/_numero_de_adds;
}

void Braco::diminuiAngulo()
{
   if(_ps->_deslocamento < _ps->_Max_deslocamento)
      _angle -= 0.8f/_numero_de_adds;
}

void Braco::mudaMarcado()
{
   if(_marcado)
   {
      _marcado = false;
   }else
   {
      _marcado = true;
   }
}
