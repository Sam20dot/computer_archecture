// this file is going to help us writing the function which will be decoded for long like this 
#include <stdio.h>

long exchange (long *px,long y) {

long x =*px;
*px=y;
return  x;


}

int add (int *a,int c ,int *d) {
int x=*a;
*a=c ;
*d =*a +c ;

}
