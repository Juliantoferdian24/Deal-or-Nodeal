#include "arrow.h"

int arrowmenu(int urutan,int xx, int yy){
    int c=3,d=4;
  if(urutan == xx+((yy-1)*4)){
    return c;
  }
  else{
    return d;
  }
}
void arrowmenu1(int a, int b){
  if(a == b){
    kuning();
  }
  else{
    normal();
  }
}
void arrow(int a, int b, int xx, int yy){
  if(a == xx && b == yy){
    birumuda();
  }
  else{
    merah();
  }
}
void arrowhere(int realposition,int arrowposition)
{
    if (realposition==arrowposition)
    {
        merah();
        printf("\t\t\t\t\t\t\t\n\t\t\t\t\t\t\t----------");
    }
    else
    {
        normal();
        printf("\t\t\t\t\t\t\t");
    }
}
