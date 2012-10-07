#ifndef ___BASE__HPP___
#define ___BASE__HPP___

#include "braco.hpp"
#include "Matriz.hpp"

class base
{
public:
   base(int numeroDeBracos);

   ~base();
   void draw();

   void aumentaAngulo();

   void diminuiAngulo();

   Braco *_marcado;
   Braco *_proxBraco;
private:
   Matriz<3,1> _posicaoCentro;
   float _raio;
   float _angulo_da_base;
   float _altura;
};

#endif