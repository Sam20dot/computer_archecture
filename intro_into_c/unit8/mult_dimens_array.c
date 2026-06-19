// this is the file which contains the multidemensional array infomations 
#include <stdio.h>


int main () {


	// this can be initialized in two ways as follow 
int matrix [3][3]={{3,4,3},{3,4,2},{3,4,5}};

// this way is so sufficient becouse can be used for dispaying the best and are esier to read other ways is 
int matrix2[3][3]={ 2,3,3,4,4,2,3,5,5};


// the display can be also achieved using for loop 
for(int i=0;i<3; i++) {

	for (int j=0;j<3;j++) {
		printf ("%d",matrix[j][i]);



	}
	printf ("\n");

}
	






}

