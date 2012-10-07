#ifndef __CARRO__HPP__
#define __CARRO__HPP__

#include "base.hpp"

class Carro
{
public:
   Carro();

   ~Carro();

   void draw();

   void update();

   void desenhaRoda();
   
   void aumentaAngulo();
   void diminuiAngulo();

   void aumentaVelocidade();
   void diminuiVelocidade();

   base *_minha_base;
   Matriz<3,1> _posicao;
   float _angulo;
   float TPI;
private:
   float _velocidade;
   float _angulo_roda;
};



#endif