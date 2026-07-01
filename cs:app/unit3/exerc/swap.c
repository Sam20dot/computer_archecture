// let write the function which do the swap 
int  swap (int *a,int *b, int *c) {

    // then we take those values from those pointed values into the a,b ,c 
    int m=*a;
    int n=*b;
    int j=*c;

    // then do the calculations within the cpu and then we store the values back 
    // to mean that the values of m will stay the same 
    int sum=m+n;
    int sub=m-j;
    int average=(float)(m+n+j)/3;

    // then we bring back the actual values within the location where they well
    // this is the same update 
    *a= sum;
    *b=sub;
    *c=average;

    // to mean that here we are dealing with 
    return average;
    


}

int main () {

    int a=90;
    int c=90;
    int m=944;
    swap( &a,&c,&m);




}
