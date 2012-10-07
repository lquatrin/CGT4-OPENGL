/*Arquivo com as funções da classe input.*/
#include "Input.h"
#include <map>

Input::Input() 
{
   keyboard.insert ( std::pair<char,bool>('W',false) );
   keyboard.insert ( std::pair<char,bool>('S',false) );
   keyboard.insert ( std::pair<char,bool>('D',false) );
   keyboard.insert ( std::pair<char,bool>('A',false) );
   keyboard.insert ( std::pair<char,bool>('Q',false) );
   keyboard.insert ( std::pair<char,bool>('E',false) );
   keyboard.insert ( std::pair<char,bool>('Z',false) );
   keyboard.insert ( std::pair<char,bool>('X',false) );
   //
   keyboard.insert ( std::pair<char,bool>('O',false) );
   keyboard.insert ( std::pair<char,bool>('L',false) );
   keyboard.insert ( std::pair<char,bool>('I',false) );
   keyboard.insert ( std::pair<char,bool>('K',false) );
   keyboard.insert ( std::pair<char,bool>('U',false) );
   keyboard.insert ( std::pair<char,bool>('J',false) );

   //keyboard.insert ( std::pair<char,bool>((char)283,false) );
   //keyboard.insert ( std::pair<char,bool>((char)284,false) );
   keyboard.insert ( std::pair<char,bool>((char)285,false) );
   keyboard.insert ( std::pair<char,bool>((char)286,false) );
   //
}
Input::~Input() {}

void Input::reset()
{
   keyboard['W'] = false;
   keyboard['S'] = false;
   keyboard['D'] = false;
   keyboard['A'] = false;
   keyboard['Q'] = false;
   keyboard['E'] = false;
   //
   keyboard['O'] = false;
   keyboard['L'] = false;
   keyboard['I'] = false;
   keyboard['K'] = false;
   keyboard['U'] = false;
   keyboard['J'] = false;
   keyboard['Z'] = false;
   keyboard['X'] = false;

   //keyboard[(char)283] = false;
   //keyboard[(char)284] = false;
   keyboard[(char)285] = false;
   keyboard[(char)286] = false;
}
