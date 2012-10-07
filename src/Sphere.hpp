/*Este .hpp contém a Classe Sphere
usado no trabalho pra desenhar uma esfera
A esfera é desenhada usando funções paramétricas.*/

#ifndef __SPHERE__HPP__
#define __SPHERE__HPP__

#include <cmath>
#include "Matriz.hpp"

/*Classe da Esfera*/
class Sphere
{
public:
   Sphere(float r)
   {
      _r = r;
      PI = 3.1415926f;
   }
   
   ~Sphere(){}

   /*Função paramétrica*/
   Matriz<3,1> retPoint(float s, float t)
   {
      Matriz<3,1> ret;
      ret(0,0) = _r * cos( (-1.f * PI)/2.f + (PI * s) )  *  cos( (-1.f * PI) + (2.f * PI * t) );
      ret(1,0) = _r * cos( (-1.f * PI)/2.f + (PI * s) )  *  sin( (-1.f * PI) + (2.f * PI * t) );
      ret(2,0) = _r * sin( (-1.f * PI)/2.f + (PI * s) );
      return ret;
   }
   
protected:
   float PI;
private:
   float _r;
   
};

#endif