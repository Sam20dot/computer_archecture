

// this  is the most usefull ways for writing the structure codes 
#include <stdio.h>



int main (){

// we write the structure as follow 
typedef struct {

char grades;
short int marks;


} students;
students s1;
s1.grades='A';
s1.marks=90;

printf ("\n the marks of the students are\n ");
printf ("\n student marks :%c and student marks :%hi",s1.grades,s1.marks);


// then let create almost ten structure of using typedef and also using the structure to see the different 
// five by five this is will takes almost 20 min to write this all the part 
// we are going to write the schematics which shows the database of small shop which sells the diferent products and use do the transaction using that platifom question says that :
// design 4 methods you can create the structure which will fit the customer and the user want to see which one he or she can choose :
// use want us to include the following :
/* 1. product structure 
 * 2. user structure 
 * 3. transaction structure 
 * 4. locations 
 * 5. balance this must be clean and well explainable not memorizable and finally you will show what was good and the      best way you choose 
 * now we can start !!!!! 
 * */


// format one 1 user structure 
struct user {

char name[5];// those are maximum 
char email[20];// maxim 
char password[6]; //mixuture of characters and then letters and for now we store them as plain text but in product 
		   //we have to incrypt the password of user 
unsigned long int user_id;


};
struct products {

char productName[20];
                     // here we will add pointing to the owner when we learned about pointer for now we put it like                       this 
unsigned long int productOwner;
unsigned long int amount;




};
// transactions 
struct transaction {
char time_stamp[10];
unsigned long int sender_id;
unsigned long int reciever_id;
unsigned long int amount;



};

//location where the user live but becouse we will use map by our self we will store user id and his or her location in longitudes and latitude 
struct location {
// to minimize the size we have to move from lowerst to the highest in the memory managment and arrangement 
short int longitude;
short int latitude;
long int user_id;




};
// now we can talk about the momennt where all of us we do what is truel amazing 
// balance 
struct balance {

unsigned long int amount;

};

// this is the ends of first format 
// let use it we are going to create the objects from all the structure using the hard way the books has fightened for long 

struct user usr1={.name="sam",.email="sam@gmail.com",.password="12345",.user_id=123433434556};
struct user usr2={.name="keve",.email="keve@gmail.com",.password="1234",.user_id=29999};
struct products pdt= {.productName="cassava",.productOwner=usr1.user_id,.amount=1000};
struct transaction trs={.time_stamp="11/11/2026",.sender_id=usr1.user_id,.reciever_id=usr2.user_id,.amount=1000};
struct location lcn1={.longitude=12,.latitude=30,.user_id=usr1.user_id};
struct balance blc= {.amount=1000};// we put here fewer infromation for learning purpose ;

// then we are going to display all infrmations from this user 
printf ("\n SAM AND KEVE USER FROM THE STRUCTURE UNIT4 STUDYING FOR SMALL DATABASE\n");

printf("\n user infromation user_id :%lu\n name:%s \n email:%s \n password:%s\n ",usr2.user_id,usr1.name,usr1.email,usr1.password);

// the product infrmations 
printf ("\n the product infromation:\n productOwner :%lu\n productName:%s\n cost :%lu \n ",pdt.productOwner,pdt.productName,pdt.amount);

// then transactions of the user 
printf ("\n the transaction infromation :\n time_stamp:%s\n sender_id:%lu reciever_id :%lu \n amount:%lu",trs.time_stamp,trs.sender_id,trs.reciever_id,trs.amount);

// then user locations 
printf ("\n user location infromations :\n user_id :%lu\n latitude:%hi\n longitude:%hi\n ",lcn1.user_id,lcn1.latitude,lcn1.longitude);

// then infomations of balance 
printf ("\n the infromation of balance :%lu\n",blc.amount);


// then we are going on the other type of the structure to make this works perfectly and well defined for being dispalyed we finished first part of displaying the struct which was 
// struct struct_name {};
// second type is this one 
// struct mystruct {} valiables ;
struct user_2 {

char name[20];
char email[20];
char password[20];
unsigned long  int user_id;



}
// then here we create the user imediatly 
usr11={.name="sam pray",.email="nizawe@gmail.com",.password="12345",.user_id=22222121212},
usr12={"sam", "sam@gmail.com","12345",21334323}
;

printf ("\nthe user has found that when the codes works better i can display them\n ");
printf ("\nuser name is :%s \n email:%s \n user password:%s\n and user_id is :%lu",usr11.name,usr11.email,usr11.password,usr11.user_id);











}
