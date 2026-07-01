
long int decode1() {
long int j=900;
long int k=5958;
long int l=4555;

long int *b=&j;
long int *d=&k;
long int *n=&l;



long int a=*b;
long int c=*d;
long int m=*n;

// then other thign to add here i the following 
 a=c ;
 c=m;
 m=a;

 return a;
}

