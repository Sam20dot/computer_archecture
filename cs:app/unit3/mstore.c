// we declare the function which will be turned into assembly to examine how they works under the hood 
long mult2 (long, long);


// then we will write the function for stroing the vlaus which is the function whcih creturn no one 
void multstore (long x, long y, long *dest )  {

long t=mult2(x,y);
*dest=t;

}
