// this file contains the qualifier which is called const and we want to know if the 
// valiable which has been defined with that qualifier can be changed or not 
#include <stdio.h>

int main () {

    double name=90;
    const double nam=9999;

    printf (" values of name and nam is :%lf ,%lf ",name,nam);

    // can we change the nam as we can change the names :
    //let try 
    name=944;
     //nam=222;// here they give you error which says
             /* 1. Cannot assign to variable 'nam' with const-qualified type 'const double' [typecheck_assign_const]
                 const.c:8:5: Variable 'nam' declared const here
              * 
              * */

printf ("\n the value of name is :%lf ",name);
printf ("\n but sorry for changing the value of nam is not possible at all \n");


}

