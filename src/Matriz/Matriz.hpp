#ifndef __MY__MATRIZ__H__
#define __MY__MATRIZ__H__

#include <string>
#include <iostream>

//Classe básica de matriz usada no projeto
template<unsigned int nl, unsigned int nc = nl>
class Matriz
{
public:
   Matriz()
   {
      for( int i = 0; i < nc*nl; i ++)
      {
         _vet[i] = 0;     
      }
   }

   ~Matriz() {}

   void setZero()
   {
      for( int i = 0; i < nc*nl; i ++)
      {
         _vet[i] = 0;     
      }
   }

   Matriz& operator+=(const Matriz& o)
   {
      for( int i = 0; i < nc*nl; i ++)
      {
         _vet[i] += o._vet[i];     
      }
      return *this;
   }

   Matriz& operator+(const Matriz& o)
   {
      for( int i = 0; i < nc*nl; i ++)
      {
         _vet[i] += o._vet[i];     
      }
      return *this;
   }

   Matriz& operator-=(const Matriz& o)
   {
      for( int i = 0; i < nc*nl; i ++)
      {
         _vet[i] -= o._vet[i];     
      }
      return *this;
   }

   Matriz operator-(const Matriz& o)
   {
      for( int i = 0; i < nc*nl; i ++)
      {
         _vet[i] -= o._vet[i];     
      }
      return this;
   }

   Matriz& operator=(const Matriz& o)
   {
      for( int i = 0; i < nc*nl; i ++)
      {
         _vet[i] = o._vet[i];     
      }
      return *this;
   }

   const float& operator()(unsigned x, unsigned y) const
   {
      return _vet[x*nc + y];
   }

   float& operator()(unsigned  x, unsigned  y)
   {
      return _vet[x*nc+ y];
   }


private:
   float _vet[nl*nc];
};

#endif