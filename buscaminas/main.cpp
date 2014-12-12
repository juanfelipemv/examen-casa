#include <iostream>
#include <sstream>
#include <string>
 #include<stdio.h>
 #include <stdlib.h>

using namespace std;


string tablero[6][6];
int posx[5];
int posy[5];

//asignacion - en todo tablero
 void iniciartablero()
 {
     for(int x=0;x<=5;x++)
     {
         for(int y=0;y<=5;y++){

            tablero[x][y]="-";
         }
     }
    tablero[0][0]=" ";
 }
int espacioslibres()
 {
     int cont=0;
     for(int x=0;x<=5;x++)
     {
         for(int y=0;y<=5;y++){
                if (tablero[x][y]=="-")
                {
                   cont+=1;
                }
         }

     }
      return cont;
 }






 void imprimirtablero()
 {
     for(int x=0;x<=5;x++)
     {
         for(int y=0;y<=5;y++){
                cout<<tablero[x][y]<<"  ";
         }
         cout<<endl;
     }
      cout<<endl;
 }



  void asignarnumeros()
 {
    for(int x=1;x<=5;x++)
    {
stringstream stream;
int numero = x;
string palabra;
stream << numero;
palabra = stream.str();
tablero[0][x]=palabra;
    }
for(int x=1;x<=5;x++)
    {
stringstream stream;
int numero = x;
string palabra;
stream << numero;
palabra = stream.str();
tablero[x][0]=palabra;
    }
 }


void asignarBombas(){

posx[1]= 1;
posy[1]= 2;
posx[2]= 1;
posy[2]= 3;
posx[3]= 1;
posy[3]= 4;
posx[4]= 1;
posy[4]= 5;
posx[5]= 2;
posy[5]= 5;

}

bool verificarbomba(int x,int y )
{
    for(int a=0;a<=5;a++){
        //SI HAY BOMBA
       if(posx[a]==x&&posy[a]==y)
        {
            return true;
        }
    }

    return false;

}


bool comprobarbomba(int x,int y )
{
    for(int a=0;a<=5;a++){
        //SI HAY BOMBA
       if(posx[a]==x&&posy[a]==y)
        {

            tablero[x][y]="X";
            imprimirtablero();
            return true;
        }
    }
    // SI NO HAY BOMBA
     tablero[x][y]=" ";
    return false;

}

int bombasAdyacentes(int x,int y)
{
    int contador=0;
    if(verificarbomba(x-1,y))
      {
          contador+=1;
      }
    if(verificarbomba(x+1,y))
      {
          contador+=1;
      }
   if(verificarbomba(x,y-1))
      {
          contador+=1;
      }
    if(verificarbomba(x,y+1))
      {
          contador+=1;
      }

      //diagonales
       if(verificarbomba(x+1,y+1))
      {
          contador+=1;
      }
       if(verificarbomba(x+1,y-1))
      {
          contador+=1;
      }
      if(verificarbomba(x-1,y+1))
      {
          contador+=1;
      }
      if(verificarbomba(x-1,y-1))
      {
          contador+=1;
      }

      return contador;
}



void extrareventon(int x,int y)
{

    comprobarbomba(x-1,y);

      comprobarbomba(x+1,y);

     comprobarbomba(x,y-1);

      comprobarbomba(x,y+1);


      //diagonales
        comprobarbomba(x+1,y+1);

        comprobarbomba(x+1,y-1);

       comprobarbomba(x-1,y+1);

       comprobarbomba(x-1,y-1);



}

int main()
{
   int x,y;
   int espacios;
   iniciartablero();
   asignarnumeros();
   asignarBombas();

cout<<endl;
cout<<endl;
cout<<"    BIENVENIDO AL BUSCAMINAS        "<<endl;
cout<<endl;
cout<<endl;
do{
    espacios=25;
   imprimirtablero();

cout<<"*************************************************"<<endl;
cout<<"       Ingrese coordenada en eje X  : "<<"\t";
cin>>x;
cout<<"       Ingrese coordenada en eje Y  : "<<"\t";
cin>>y;
cout<<"*************************************************"<<endl;

 if(x==y)
 {
extrareventon(x,y);

 }


if(comprobarbomba(x,y))
{
cout<<"              BOOM"<<endl;
cout<<"            GAME OVER "<<endl;
    break;
}
//si no hay bombas se hace el tiro
if(!comprobarbomba(x,y))
{

    cout<<"*************************************************"<<endl;
              cout<<"    Bombas Adyacentes :   "<<bombasAdyacentes(x,y)<<endl;
              cout<<"    Espacios Libres   :   "<<espacioslibres()<<endl;
    cout<<"*************************************************"<<endl;
    cout<<"                                                 "<<endl;
}
//se gana cuando solo qedan los espacios de las bombas en el tablero
if(espacioslibres()==5){
    cout<<"*************************************************"<<endl;
    cout<<"*************************************************"<<endl;
    cout<<"                                                 "<<endl;
    cout<<"              FELICIDADES                        "<<endl;
    cout<<"          HAS  GANADO LA PARTIDA                 "<<endl;
    cout<<"                                                 "<<endl;
    cout<<"*************************************************"<<endl;
    cout<<"*************************************************"<<endl;
    break;
}




  }while(true);
}
