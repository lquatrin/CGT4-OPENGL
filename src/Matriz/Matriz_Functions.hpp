#ifndef ___MATRIZ_FUNCTIONS_HPP___
#define ___MATRIZ_FUNCTIONS_HPP___

#include "Matriz.hpp"
#include <cmath> 

//funções de matrizes/vetores
template<unsigned int m, unsigned int p, unsigned int n>
Matriz<m,n> operator*(const Matriz<m,p>& a, const Matriz<p,n>& b)
{
   Matriz<m,n> ret;
   ret.setZero();

   for(int i = 0; i < m; i++){
      for(int j = 0; j < n; j++){
         for(int k = 0 ; k < p ; k++){
            ret(i,j) += a(i,k) * b(k,j);
         }
      }

   }
   return ret;
}

template<unsigned int nc, unsigned int nl>
Matriz<nl,nc> operator*(const Matriz<nl,nc>& a,const float& d)
{
   Matriz<nl,nc> ret;
   for( int i = 0; i < nl; i ++)
   {
      for( int j = 0; j < nc ; j++)
         ret(i,j) = a(i,j) * d;     
   }
   ret(nl-1,nc-1) = 1;
   return ret;
}

inline float angleDotProduct2DYZ(Matriz<3,1> dirT,Matriz<3,1> vAngle)
{
   return acos((dirT(1,0)*vAngle(1,0)) + (dirT(2,0)*vAngle(2,0)));
}

inline Matriz<4,1> normalizeVector3D(Matriz<4,1> v)
{
   float dv = sqrt(pow(v(0,0),2) + pow(v(1,0),2) + pow(v(2,0),2));
   v(0,0) = v(0,0)/dv;
   v(1,0) = v(1,0)/dv;
   v(2,0) = v(2,0)/dv;
   v(3,0) = 1;
   return v;
}

inline Matriz<3,1> normalizeVector3D(Matriz<3,1> v)
{
   float dv = sqrt(pow(v(0,0),2) + pow(v(1,0),2) + pow(v(2,0),2));
   v(0,0) = v(0,0)/dv;
   v(1,0) = v(1,0)/dv;
   v(2,0) = v(2,0)/dv;
   return v;
}

//classe com algumas funções usada com  matrizes
class mFunctions{
public:

inline Matriz<3,1> normalizeVector2D(Matriz<3,1> v)
{
   float dv = sqrt(pow(v(0,0),2) + pow(v(1,0),2));
   v(0,0) = v(0,0)/dv;
   v(1,0) = v(1,0)/dv;
   v(2,0) = 1;
   return v;
}


inline Matriz<4,1> crossProduct3D(Matriz<4,1> v1,Matriz<4,1> v2)
{
   Matriz<4,1> res;
   res(0,0) = v1(1,0)*v2(2,0) - v2(1,0)*v1(2,0);
   res(1,0) = v1(2,0)*v2(0,0) - v2(2,0)*v1(0,0);
   res(2,0) = v1(0,0)*v2(1,0) - v2(0,0)*v1(1,0);
   res(3,0) = 1;
   return res;
}

/*
float dotProduct2D(Matriz<3,1> dirT,Matriz<3,1> vAngle)
{
   
}
*/
float angleDotProduct2D(Matriz<3,1> dirT,Matriz<3,1> vAngle)
{
   return acos((dirT(0,0)*vAngle(0,0)) + (dirT(1,0)*vAngle(1,0)));
}

Matriz<3,3> rotation2D(float graus)
{
   Matriz<3,3> ret;
   ret.setZero();
   ret(0,0) = cos(graus);
   ret(0,1) = -sin(graus);
   ret(1,0) = sin(graus);
   ret(1,1) = cos(graus);
   ret(2,2) = 1;
   return ret;
}

Matriz<4,4> rotation3Dx(float graus)
{
   Matriz<4,4> ret;
   ret.setZero();
   ret(0,0) = 1;
   ret(1,1) = cos(graus);
   ret(1,2) = -sin(graus);
   ret(2,1) = sin(graus);
   ret(2,2) = cos(graus);
   ret(3,3) = 1;
   return ret;
}

Matriz<4,4> rotation3Dy(float graus)
{
   Matriz<4,4> ret;
   ret.setZero();
   ret(0,0) = cos(graus);
   ret(0,2) = sin(graus);
   ret(1,1) = 1;
   ret(2,0) = -sin(graus);
   ret(2,2) = cos(graus);
   ret(3,3) = 1;
   return ret;
}

Matriz<4,4> rotation3Dz(float graus)
{
   Matriz<4,4> ret;
   ret.setZero();
   ret(0,0) = cos(graus);
   ret(0,1) = -sin(graus);
   ret(1,0) = sin(graus);
   ret(1,1) = cos(graus);
   ret(2,2) = 1;
   ret(3,3) = 1;
   return ret;
}

Matriz<3,3> Translate2D(float xi,float yi, float xf, float yf)
{
   Matriz<3,3> ret;
   ret.setZero();
   ret(0,0) = 1;
   ret(1,1) = 1;
   ret(2,2) = 1;
   ret(0,2) = xf-xi;
   ret(1,2) = yf-yi;
   return ret;
}

Matriz<4,4> Translate3D(float tx,float ty, float tz)
{
   Matriz<4,4> ret;
   ret.setZero();
   ret(0,0) = 1;
   ret(1,1) = 1;
   ret(2,2) = 1;
   ret(3,3) = 1;
   ret(0,3) = tx;
   ret(1,3) = ty;
   ret(2,3) = tz;
   return ret;
}

Matriz<3,3> Scale2D2(float xi,float yi)
{
   Matriz<3,3> ret;
   ret.setZero();
   ret(0,0) = xi;
   ret(1,1) = yi;
   ret(2,2) = 1;
   return ret;
}

Matriz<3,3> Scale2D1(float xi)
{
   Matriz<3,3> ret;
   ret.setZero();
   ret(0,0) = xi;
   ret(1,1) = xi;
   ret(2,2) = 1;
   return ret;
}

Matriz<4,4> Scale3D3(float Sx, float Sy, float Sz)
{
   Matriz<4,4> ret;
   ret.setZero();
   ret(0,0) = Sx;
   ret(1,1) = Sy;
   ret(2,2) = Sz;
   ret(3,3) = 1;
   return ret;
}

Matriz<4,4> Scale3D1(float Sxyz)
{
   Matriz<4,4> ret;
   ret.setZero();
   ret(0,0) = Sxyz;
   ret(1,1) = Sxyz;
   ret(2,2) = Sxyz;
   ret(3,3) = 1;
   return ret;
}

Matriz<3,1> negBasicXDirection()
{
   Matriz<3,1> direction;
   direction(0,0) = -1;
   direction(1,0) = 0;
   direction(2,0) = 1;
   return direction;
}


Matriz<3,1> BasicXDirection()
{
   Matriz<3,1> direction;
   direction(0,0) = 1;
   direction(1,0) = 0;
   direction(2,0) = 1;
   return direction;
}

};

#endif

