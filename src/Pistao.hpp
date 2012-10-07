#ifndef __PISTAO__HPP__
#define __PISTAO__HPP__

#include "Sphere.hpp"
#include <GL/glfw.h>

class Pistao
{
public:
   Pistao(float altura)
   {
      _altura = altura;
      _deslocamento = 0;
      _Max_deslocamento = _altura - 20;
      _Min_deslocamento = 25;
      _sp = new Sphere(20);
   }

   ~Pistao()
   {

   }

   float _altura;
   float _deslocamento;
   float _Max_deslocamento;
   float _Min_deslocamento;
   Sphere *_sp;
private:

};

#endif
