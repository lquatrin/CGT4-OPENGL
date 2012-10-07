#ifndef ___BRACO__HPP__
#define ___BRACO__HPP__

#include "Matriz.hpp"
#include "Sphere.hpp"
#include "pistao.hpp"
#include "Matriz_Functions.hpp"
#include <GL/glfw.h>

class Braco
{
public:
   Braco(int numeroDeBracos);

   Braco(int numeroDeBracos, float angle);

   ~Braco();

   void draw();

   void aumentaAngulo();

   void diminuiAngulo();

   void mudaMarcado();

   Braco *_proxBraco;
   Braco *_antBraco;
private:
   float _altura;
   float _lados;
   float _angle;
   bool _marcado;
   Sphere *_sp;
   Pistao *_ps;
   float _numero_de_adds;
   float TPI;

};

#endif