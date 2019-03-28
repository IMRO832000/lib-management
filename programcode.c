#include <windows.h> 
#include<stdio.h>
#include<conio.h>	
#include<string.h>		
 #include<ctype.h> 
#include<dos.h>	//contains _dos_getdate 
#include<time.h>
#define RETURNTIME 15
//list of function prototype 
#define MAX 50
char qu[MAX][30],item[30]; 
int rear=0,front=0;
char catagories[][15]={"Computer","Electronics","Electrical","Civil","Mechnnical","Architecture"}; 
void returnfunc(void);
void addit();
void mainmenu(void); 
void addbooks(void); 
void deletebooks(void); 
void editbooks(void); 
void searchbooks(void); 
void issuebooks(void); 
void viewbooks(void);
void viewbooks1(void); 
void returnfunc1(void);
void closeapplication(void); 
int getdata();
int checkid(int); 
int t(void); 
void Password(); 
void issuerecord(); 
void loaderanim(); 
void suggestbooks(); 
void deq();
void enq();
void mainmenu1(); 
void option();
int Check(); 
void display();
void stumenu(void); 
void sort(float a[5],char b[5][100]); 
void schoice(void); 
void displaybooks(int);

COORD coord = {0, 0}; // sets coordinates to 0,0
//COORD max_buffer_size = GetLargestConsoleWindowSize(hOut); 
COORD max_res,cursor_size;
void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y; // X and Y coordinates 
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void delay(unsigned int mseconds)
{
clock_t goal = mseconds + clock(); 
while (goal > clock());
}
//list of global files that can be accessed form anywhere in program 
FILE *fp,*ft,*fs;
 


//list of global variable
 int s;
char findbook;
char password[10]={"codechamp"};


struct meroDate
{
int mm,dd,yy;
};
struct books
{
int id;
char stname[20]; char name[20]; char Author[20]; int quantity; float Price;
int count; int rackno; char *cat;
struct meroDate issued; struct meroDate duedate;
};
struct books a;
void Password(void)
{


system("cls");
char d[25]="Password Protected";
 
char ch,pass[10]; int i=0,j; gotoxy(10,4); for(j=0;j<20;j++)
{
delay(50); printf("*");
}
for(j=0;j<20;j++)
{
delay(50); printf("%c",d[j]);
}
for(j=0;j<20;j++)
{
delay(50); printf("*");
}
gotoxy(10,10); gotoxy(15,7); printf("Enter Password:");

while(ch!=13)
{
ch=getch();


if(ch!=13 && ch!=8){ putch('*');
pass[i] = ch; i++;
 
}
}
pass[i] = '\0'; if(strcmp(pass,password)==0)
{


gotoxy(15,9);
//textcolor(BLINK); 
printf("Password match"); 
gotoxy(17,10);
printf("Press any key to countinue.	");
getch(); mainmenu();
}
else
{
gotoxy(15,16);
printf("\aWarning!! Incorrect Password"); 
getch();
Password();
}

}
int Check(char *fname, char *str)
{
FILE *file; 
int r = 0;
char temp[10];
if((file = fopen(fname, "r")) == NULL) { return(-1);
}
 
while(fgets(temp,10, file) != NULL) { if((strcmp(temp, str))==0)
{
gotoxy(15,9);
printf("VALIDATION SUCCESSFUL");
mainmenu1();


r++;
}
}
if(r == 0) {
gotoxy(15,9);
printf("\aSORRY YOU AREN'T A MEMBER OF THIS LIBRARY ");
}


if(file) {
fclose(file);
}
return(0);
}
void option(){ system("cls"); int ch; gotoxy(20,3);
printf("\xB2\xB2\xB2\xB2\xB2\xB2 LIBRARY MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2"); gotoxy(20,5);
printf("\xB2\xB2\xB2\xB2\xB2 YOU WANT TO LOGIN AS A \n"); gotoxy(20,7);
printf("\xB2\xB2\xB2\xB2\xB2 (1)LIBRARIAN \n"); gotoxy(20,9);
 
printf("\xB2\xB2\xB2\xB2\xB2 (2)STUDENT \n"); gotoxy(20,11);
printf("YOUR CHOICE IS:");
gotoxy(35,11); scanf("%d",&ch); switch(ch){
case 1:
Password(); break;
case 2:
system("cls");
gotoxy(15,5);
printf("**********ENTER YOUR UNIQUE ID: ********** \n"); char s[11];
gotoxy(15,7); scanf("%s",&s);
Check("a.txt",s); break;
default:
{
gotoxy(10,23);
printf("\aWrong Entry!!Please re-entered correct option"); if(getch())
option();
}


}
}
int i1=0,i2=0,i3=0,i4=0,i5=0,i6=0;
int top1=-1,top2=-1,top3=-1,top4=-1,top5=-1,top6=-1;
 
int g=0,b=0,c=0,d=0,e=0,f=0;
char toplist1[5][100],toplist2[5][100],toplist3[5][100],toplist4[5][100],toplist5[5][100],toplist6[5][100];
float a1[5],a2[5],a3[5],a4[5],a5[5],a6[5];
char n1[5][100],n2[5][100],n3[5][100],n4[5][100],n5[5][100],n6[5][100];
void stumenu()
{
system("cls");
gotoxy(20,3);
printf("\xB2\xB2\xB2\xB2\xB2\xB2 LIBRARY MANAGEMENT SYSTEM \xB2\xB2\xB2\xB2\xB2\xB2"); gotoxy(20,5);
printf("\xB2\xB2\xB2\xB2\xB2\xB2 YOU HAVE SUCCESFULLY LOGGED IN AS A STUDENT\xB2\xB2\xB2\xB2\xB2\xB2"); gotoxy(20,6);
printf("\xB2\xB2\xB2\xB2\xB2\xB2 ENTER YOUR BRANCH \xB2\xB2\xB2\xB2\xB2\xB2"); gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\ 1=> Computer"); gotoxy(20,10);
printf("\xB2\xB2\xB2\xB2\ 2=> Electronics"); gotoxy(20,12);
printf("\xB2\xB2\xB2\xB2\ 3=> Electrical"); gotoxy(20,14);
printf("\xB2\xB2\xB2\xB2\ 4=> Civil"); gotoxy(20,16);
printf("\xB2\xB2\xB2\xB2\ 5=> Mechanical"); gotoxy(20,18);
printf("\xB2\xB2\xB2\xB2\ 6=> Architecture"); gotoxy(20,20);
printf("\xB2\xB2\xB2\xB2\ 7=> Back to main menu"); gotoxy(20,21);
 
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\ xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
int ch; scanf("%d",&ch); switch(ch){
case 1:
{
system("cls");
gotoxy(20,3);
printf("\xB2\xB2\xB2\xB2\xB2\xB2 ENTER THE BOOK NAME AND IT'S RATING ON SCALE OF 1-10\xB2\xB2\xB2\xB2\xB2\xB2\n"); gotoxy(25,5); scanf("%s",&n1[i1]); gotoxy(25,6); scanf("%f",&a1[i1]); printf("\n");
i1++; 
if(i1==10){
printf("That's all folks");
}




system("cls");
gotoxy(25,8);
printf("YOU WISH TO CONTINUE? (1)YES OR (2)NO\n");
gotoxy(25,10); int y; scanf("%d",&y); switch(y){
case 1: stumenu();
		break; 
case 2: mainmenu1();
}
}
break; case 2:
{
system("cls");
gotoxy(20,3);
printf("\xB2\xB2\xB2\xB2\xB2\xB2 ENTER THE BOOK NAME AND IT'S RATING ON SCALE OF 1-10\xB2\xB2\xB2\xB2\xB2\xB2\n"); gotoxy(25,5); scanf("%s",&n2[i2]); gotoxy(25,6);
scanf("%f",&a2[i2]);
 printf("\n");

i2++; 
if(i2==10)
{printf("That's all folks");
}




system("cls");
gotoxy(25,8);
printf("YOU WISH TO CONTINUE? (1)YES OR (2)NO\n");
gotoxy(25,10); int y; scanf("%d",&y);
 
switch(y){ case 1:
stumenu(); break;
case 2:
mainmenu1();
}
}
break; case 3:
{
system("cls");
gotoxy(20,3);
printf("\xB2\xB2\xB2\xB2\xB2\xB2 ENTER THE BOOK NAME AND IT'S RATING ON SCALE OF 1-10\xB2\xB2\xB2\xB2\xB2\xB2\n"); gotoxy(25,5); 
scanf("%s",&n3[i3]); gotoxy(25,6);
scanf("%f",&a3[i3]); printf("\n");

i3++; 
if(i3==10)
{printf("That's all folks");
}




system("cls");
gotoxy(25,8);
printf("YOU WISH TO CONTINUE? (1)YES OR (2)NO\n");
 
gotoxy(25,10); int y; scanf("%d",&y); switch(y){
case 1:
stumenu(); break;
case 2:
mainmenu1();
}
}
break; case 4:
{
system("cls");
gotoxy(20,3);
printf("\xB2\xB2\xB2\xB2\xB2\xB2 ENTER THE BOOK NAME AND IT'S RATING ON SCALE OF 1-10\xB2\xB2\xB2\xB2\xB2\xB2\n"); gotoxy(25,5); 
scanf("%s",&n4[i4]); gotoxy(25,6);
scanf("%f",&a4[i4]); printf("\n");

i4++; if(i4==10)
{printf("That's all folks");
}


system("cls");
 
gotoxy(25,8);
printf("YOU WISH TO CONTINUE? (1)YES OR (2)NO\n");
gotoxy(25,10);
int y; scanf("%d",&y); switch(y){
case 1:
stumenu(); break;
case 2:
mainmenu1();
}
}
break; case 5:
{
system("cls");
gotoxy(20,3);
printf("\xB2\xB2\xB2\xB2\xB2\xB2 ENTER THE BOOK NAME AND IT'S RATING ON SCALE OF 1-10\xB2\xB2\xB2\xB2\xB2\xB2\n"); gotoxy(25,5); 
scanf("%s",&n5[i5]); gotoxy(25,6);
scanf("%f",&a5[i5]); printf("\n");

i5++; if(i5==10)
{printf("That's all folks so chose another branch");
}
 


system("cls");
gotoxy(25,8);
printf("YOU WISH TO CONTINUE? (1)YES OR (2)NO\n");
gotoxy(25,10); int y; scanf("%d",&y); switch(y){
case 1:
stumenu(); break;
case 2:
mainmenu1();
}
}
break; case 6:
{
system("cls");
gotoxy(20,3);
printf("\xB2\xB2\xB2\xB2\xB2\xB2 ENTER THE BOOK NAME AND IT'S RATING ON SCALE OF 1-10\xB2\xB2\xB2\xB2\xB2\xB2\n"); gotoxy(25,5); 
scanf("%s",&n6[i6]); gotoxy(25,6);
scanf("%f",&a6[i6]); printf("\n");

i6++; if(i6==10)
 
{printf("That's all folks");
}


system("cls");
gotoxy(25,8);
printf("YOU WISH TO CONTINUE? (1)YES OR (2)NO\n");
gotoxy(25,10); int y; scanf("%d",&y); switch(y){
case 1:
stumenu(); break;
case 2:
mainmenu1();
}
}
break; case 7:
stumenu();
}
}
void sort(float x[5],char st[5][100])
{ 
int i,j;
float t;
char s[100]; 
for(i=0;i<4;i++){
for(j=0;j<4-i;j++){
if(x[j]>x[j+1])
{
 
t=x[j]; x[j]=x[j+1]; x[j+1]=t; strcpy(s,st[j]);
strcpy(st[j],st[j+1]);
strcpy(st[j+1],s);

}


}

}


}




void push1()
{
if(top1==9 ){
printf("Data limit exceeded");
}
else{
strcpy(toplist1[++top1],n1[g++]);
}
}
void push2()
{
if(top2==9 ){
printf("Data limit exceeded");
}
else{
strcpy(toplist2[++top2],n2[b++]);
 
}

}
void push3()
{
if(top3==9 ){
printf("Data limit exceeded");
}
else{
strcpy(toplist3[++top3],n3[c++]);
}
}
void push4()
{
if(top4==9 ){
printf("Data limit exceeded");
}
else{
strcpy(toplist4[++top4],n4[d++]);
}
}
void push5()
{
if(top5==9 ){
printf("Data limit exceeded");
}
else{
strcpy(toplist5[++top5],n5[e++]);
}
}
void push6()
 
{

if(top6==9 ){
printf("Data limit exceeded");
}
else{
strcpy(toplist6[++top6],n6[f++]);
}

}
void pop(char list[5][100],int limit){ if(limit==-1){
printf("List empty\n"); exit(0);
}
char x[100]; strcpy(x,list[limit]); printf("%s\n",x);

}
void displaybooks(int xy){
int x1,x2,x3,x4,x5,x6,i;
system("cls");
gotoxy(25,5); switch(xy){ case 1:
{
printf("COMPUTER BOOKS:\n");


for(x1=top1,i=7;x1>=0;x1--,i+=2){ gotoxy(25,i); pop(toplist1,x1);
 
}
returnfunc1();

}
break; case 2:
{


printf("ELECTRONIC BOOKS:\n");


for(x2=top2,i=7;x2>=0;x2--,i+=2){ gotoxy(25,i); pop(toplist2,x2);
}
returnfunc1();
}
break;

case 3:

{


printf("ELECTRICAL BOOKS:\n");


for(x3=top3,i=7;x3>=0;x3--,i+=2){ gotoxy(25,i); pop(toplist3,x3);
}
returnfunc1();
}
break;

case 4:

{
 


printf("CIVIL BOOKS:\n");


for(x4=top4,i=7;x4>=0;x4--,i+=2){ gotoxy(25,i); pop(toplist4,x4);
}
returnfunc1();
}
break;

case 5:

{


printf("MECHANICAL BOOKS:\n");


for(x5=top5,i=7;x5>=0;x5--,i+=2){ gotoxy(25,i); pop(toplist5,x5);
}
returnfunc1();
}
break;

case 6:

{




printf("ARCHITECTURE BOOKS:\n");


for(x6=top6,i=7;x6>=0;x6--,i+=2){ gotoxy(25,i);
 
pop(toplist6,x6);

}
returnfunc1();
}}

}
void schoice(){
int cho,i; system("cls");
gotoxy(20,6);
printf("\xB2\xB2\xB2\xB2\xB2\xB2 ENTER YOUR BRANCH \xB2\xB2\xB2\xB2\xB2\xB2"); gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\ 1=> Computer"); gotoxy(20,10);
printf("\xB2\xB2\xB2\xB2\ 2=> Electronics"); gotoxy(20,12);
printf("\xB2\xB2\xB2\xB2\ 3=> Electrical"); gotoxy(20,14);
printf("\xB2\xB2\xB2\xB2\ 4=> Civil"); gotoxy(20,16);
printf("\xB2\xB2\xB2\xB2\ 5=> Mechanical"); gotoxy(20,18);
printf("\xB2\xB2\xB2\xB2\ 6=> Architecture");


scanf("%d",&cho); switch(cho){
case 1:
{
sort(a1,n1); for(i=0;i<5;i++){
push1();
 
}
displaybooks(1);

}

break;

case 2:

{


sort(a2,n2); for(i=0;i<5;i++){
push2();

}
displaybooks(2);

}

break;

case 3:

{


sort(a3,n3); for(i=0;i<5;i++){
push3();

}
displaybooks(3);
}
break;

case 4:

{


sort(a4,n4); for(i=0;i<5;i++){
push4();
 
}
displaybooks(4);

}

break;

case 5:

{


sort(a5,n6); for(i=0;i<5;i++){
push5();

}
displaybooks(5);

}

break;

case 6:

{


sort(a6,n6); for(i=0;i<5;i++){
push6();

}
displaybooks(6);

}

}

}


int main()


{
option();
 
getch(); return 0;


}
void mainmenu1()
{
system("cls"); int i; gotoxy(20,3);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU"); printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); gotoxy(20,5);
printf("\xDB\xDB\xDB\xDB\xB2 1. Suggest Books"); gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB2 2. Provide review for books"); gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xB2 3. Check the best books on the basis of your reviews"); gotoxy(20,11);
printf("\xDB\xDB\xDB\xDB\xB2 4. Recently added books"); gotoxy(20,13);
printf("\xDB\xDB\xDB\xDB\xB2 5. Change Login"); gotoxy(20,15);
printf("\xDB\xDB\xDB\xDB\xB2 6. Close Application"); gotoxy(20,16);
printf("	");
gotoxy(20,17); t();
gotoxy(20,18);
printf("Enter your choice:"); switch(getch())
 
{

case '1':
suggestbooks(); break;
case '2': stumenu(); break;
case '3':
schoice(); break;
case '4':
viewbooks1(); break;
case '5':
option(); break;
case '6':
{
system("cls");
gotoxy(16,3);
printf("Thanks for using the Program.."); gotoxy(10,7);
printf("Exiting in 5 second	>");
//flushall(); delay(5000); exit(0);
}
break;


default:
 
{
gotoxy(10,23);
printf("\aWrong Entry!!Please re-entered correct option"); if(getch())
mainmenu1();
}


}

}
void suggestbooks()
{
system("cls"); enq();
}
void addit()
{
system("cls"); char q[11]; gotoxy(10,5); scanf("%s",q);
FILE *out = fopen("a.txt", "a");
fprintf(out, "%s", q); gotoxy(10,7);
printf("RECORD ADDED SUCCESSFULLY");
delay(2000); fclose(out); mainmenu();
}
void enq()
{
 
system("cls");
if (rear == MAX)
{printf("List is full");} else
{
int c;
char a[30]; gotoxy(5,5);
printf("Enter the name of the book \n"); gotoxy(5,7);
//scanf ("%[^\n]%*c", a);
scanf("%s",&a);
//fgets(a,30,stdin); rear = rear + 1; strcpy(qu[rear],a); if(front==0)
{front=1;} gotoxy(5,9);
printf("Do you wish to continue press 1 for YES and 0 for NO \n"); scanf("%d",&c);
switch(c){ case 1:
enq(); break;
case 0:
mainmenu1(); break;
default:
{printf("Enter the correct choice "); enq();
 
break;}
}}}
void deq()
{
if (front == 0)
{printf("That's all folks\ ");} else if(front == rear)
front = rear = 0; else
{
strcpy(item,qu[front]); strcpy(qu[front],0); front = front + 1; printf("%d",item);
}}
void display()
{
int e; system("cls"); int i;
if (front == 0) printf("Queue is empty"); else
{
for (i = front; i <= rear; i++)
{
printf("%d %s \n",i,qu[i]);
}
}
gotoxy(50,20);
 
printf("Press 1 to go back to Mainmenu "); scanf("%d",&e);
switch(e){ case 1:
mainmenu(); break;
}
}
void mainmenu()
{
system("cls"); int i; gotoxy(20,3);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU"); printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); gotoxy(20,5);
printf("\xDB\xDB\xDB\xDB\xB2 1. Add Books "); gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB2 2. Delete books"); gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xB2 3. Search Books"); gotoxy(20,11);
printf("\xDB\xDB\xDB\xDB\xB2 4. Issue Books"); gotoxy(20,13);
printf("\xDB\xDB\xDB\xDB\xB2 5. View Book list"); gotoxy(20,15);
printf("\xDB\xDB\xDB\xDB\xB2 6. View Suggested Book List "); gotoxy(20,17);
printf("\xDB\xDB\xDB\xDB\xB2 7. Edit Book's Record"); gotoxy(20,19);
 
printf("\xDB\xDB\xDB\xDB\xB2 8. Add a new student to library"); gotoxy(20,21);
printf("\xDB\xDB\xDB\xDB\xB2 9. Change Login"); gotoxy(20,23);
printf("\xDB\xDB\xDB\xDB\xB2 10. Close Application"); gotoxy(20,25);
printf("	");
gotoxy(20,26); t();
gotoxy(20,27);
printf("Enter your choice:"); switch(getch())
{
case '1': addbooks(); break;
case '2': deletebooks(); break;
case '3': searchbooks(); break;
case '4': issuebooks(); break;
case '5': viewbooks(); break;
case '6': display();
 
break; case '7':
editbooks(); break;
case '8':
addit(); break; case '9':
option(); break; case '10':
{
system("cls");
gotoxy(16,3);
printf("Thanks for using the Program.."); gotoxy(10,7);
printf("Exiting in 5 second	>");
//flushall(); delay(5000); exit(0);
}
break; default:
{
gotoxy(10,23);
printf("\aWrong Entry!!Please re-entered correct option"); if(getch())
mainmenu();
}
 
}

}
void addbooks(void) //funtion that add books
{
system("cls"); 
int i,s;
 gotoxy(20,5);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGOIES"); printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,7);
printf("\xDB\xDB\xDB\xDB\xB2 1. Computer"); gotoxy(20,9);
printf("\xDB\xDB\xDB\xDB\xB2 2. Electronics"); gotoxy(20,11);
printf("\xDB\xDB\xDB\xDB\xB2 3. Electrical"); gotoxy(20,13); printf("\xDB\xDB\xDB\xDB\xB2 4. Civil"); gotoxy(20,15);
printf("\xDB\xDB\xDB\xDB\xB2 5. Mechanical"); gotoxy(20,17);
printf("\xDB\xDB\xDB\xDB\xB2 6. Architecture"); gotoxy(20,19);
printf("\xDB\xDB\xDB\xDB\xB2 7. Back to main menu"); gotoxy(20,21);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\\xB2\xB2\xB2"); 
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); gotoxy(20,22);
printf("Enter your choice:"); 
scanf("%d",&s);
if(s==7)
mainmenu() ; 
system("cls");
fp=fopen("Bibek.dat","ab+"); 
if(getdata()==1)
{
a.cat=catagories[s-1]; fseek(fp,0,SEEK_END); fwrite(&a,sizeof(a),1,fp); fclose(fp); gotoxy(21,14);
printf("The record is sucessfully saved"); gotoxy(21,15);
printf("Save any more?(Y / N):"); if(getch()=='n')
mainmenu(); 
else
system("cls"); addbooks();
}

}
void deletebooks() //function that delete items from file fp
{
system("cls"); int d;
char another='y'; while(another=='y') //infinite loop
{
system("cls");
gotoxy(10,5);
 
printf("Enter the Book ID to delete:"); scanf("%d",&d); 
fp=fopen("Bibek.dat","rb+"); 
rewind(fp); 
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{


gotoxy(10,7);
printf("The book record is available"); gotoxy(10,8);
printf("Book name is %s",a.name); gotoxy(10,9);
printf("Rack No. is %d",a.rackno); findbook='t';
}
}
if(findbook!='t')
{
gotoxy(10,10);
printf("No record is found modify the search"); if(getch())
mainmenu();
}
if(findbook=='t' )
{
gotoxy(10,9);
printf("Do you want to delete it?(Y/N):"); if(getch()=='y')
 
{
FILE *ft;
ft=fopen("test.dat","wb+"); //temporary file for delete rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id!=d)
{
fseek(ft,0,SEEK_CUR);
fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
}	//we want to delete
}
fclose(ft); fclose(fp);
remove("Bibek.dat");
rename("test.dat","Bibek.dat"); //copy all item from temporary file to fp except that fp=fopen("Bibek.dat","rb+"); //we want to delete
if(findbook=='t')
{
gotoxy(10,10);
printf("The record is sucessfully deleted"); gotoxy(10,11);
printf("Delete another record?(Y/N)");
}
}
else mainmenu(); fflush(stdin); another=getch();
}
}
 
gotoxy(10,15); mainmenu();
}


void searchbooks()
{
system("cls"); int d;
printf("*****************************Search Books*********************************");
gotoxy(20,10);
printf("\xDB\xDB\xDB\xB2 1. Search By ID"); gotoxy(20,14);
printf("\xDB\xDB\xDB\xB2 2. Search By Name"); gotoxy( 15,20);
printf("Enter Your Choice");
fp=fopen("Bibek.dat","rb+"); //open file for reading propose rewind(fp); //move pointer at the begining of file 
switch(getch())
{
case '1':
{
system("cls");
gotoxy(25,4);
printf("****Search Books By Id****"); gotoxy(20,5);
printf("Enter the book id:"); scanf("%d",&d); gotoxy(20,7); printf("Searching	");
 
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{
delay(2);
gotoxy(20,7);
printf("The Book is available"); gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); gotoxy(20,9);
printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2"); gotoxy(20,10);
printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2"); gotoxy(20,11);
printf("\xB2 Author:%s ",a.Author);gotoxy(47,11);printf("\xB2"); gotoxy(20,12);
printf("\xB2 Quantity:%d ",a.quantity);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
gotoxy(20,13);
printf("\xB2 Price:Rs.%.2f",a.Price);gotoxy(47,13);printf("\xB2"); gotoxy(20,14);
printf("\xB2 Rack No:%d ",a.rackno);gotoxy(47,14);printf("\xB2"); gotoxy(20,15); printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); findbook='t';
}


}
 
if(findbook!='t') //checks whether conditiion enters inside loop or not
{
gotoxy(20,8);


printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); gotoxy(20,9);printf("\xB2"); gotoxy(38,9);printf("\xB2");
gotoxy(20,10);


printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)"); if(getch()=='y')
searchbooks(); else mainmenu(); break;
}
case '2':
{
char s[15]; system("cls");
gotoxy(25,4);
printf("****Search Books By Name****"); gotoxy(20,5);
printf("Enter Book Name:"); scanf("%s",s);
int d=0; while(fread(&a,sizeof(a),1,fp)==1)
{
 
if(strcmp(a.name,(s))==0) //checks whether a.name is equal to s or not
{
gotoxy(20,7);
printf("The Book is available"); gotoxy(20,8);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); gotoxy(20,9);
printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2"); gotoxy(20,10);
printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2"); gotoxy(20,11);
printf("\xB2 Author:%s",a.Author);gotoxy(47,11);printf("\xB2"); gotoxy(20,12);
printf("\xB2 Qantity:%d",a.quantity);gotoxy(47,12);printf("\xB2"); gotoxy(20,13);
printf("\xB2 Price:Rs.%.2f",a.Price);gotoxy(47,13);printf("\xB2"); gotoxy(20,14);
printf("\xB2 Rack No:%d ",a.rackno);gotoxy(47,14);printf("\xB2"); gotoxy(20,15); printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); d++;
}


}
if(d==0)
{
gotoxy(20,8);
 

printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); gotoxy(20,9);printf("\xB2"); gotoxy(38,9);printf("\xB2");
gotoxy(20,10);


printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); gotoxy(22,9);printf("\aNo Record Found");
}
gotoxy(20,17);
printf("Try another search?(Y/N)"); if(getch()=='y')
searchbooks(); else mainmenu(); break;
}
default :
getch(); searchbooks();
}
fclose(fp);
}
void issuebooks(void) //function that issue books from library
{
int t;


system("cls");
printf("********************************ISSUE SECTION**************************"); gotoxy(10,5);
printf("\xDB\xDB\xDB\xDb\xB2 1. Issue a Book"); gotoxy(10,7);
 
printf("\xDB\xDB\xDB\xDb\xB2 2. View Issued Book"); gotoxy(10,9);
printf("\xDB\xDB\xDB\xDb\xB2 3. Search Issued Book"); gotoxy(10,11);
printf("\xDB\xDB\xDB\xDb\xB2 4. Remove Issued Book"); gotoxy(10,14);
printf("Enter a Choice:"); switch(getch())
{
case '1': //issue book
{
system("cls"); int c=0;
char another='y'; while(another=='y')
{
system("cls");
gotoxy(15,4);
printf("***Issue Book section***"); gotoxy(10,6);
printf("Enter the Book Id:"); scanf("%d",&t); 
fp=fopen("Bibek.dat","rb");
fs=fopen("Issue.dat","ab+");
if(checkid(t)==0) //issues those which are present in library
{
gotoxy(10,8);
printf("The book record is available"); gotoxy(10,9);
printf("There are %d unissued books in library ",a.quantity);
 
gotoxy(10,10);
printf("The name of book is %s",a.name); gotoxy(10,11);
printf("Enter student name:"); scanf("%s",a.stname);
// struct dosdate_t d; //for current date
// _dos_getdate(&d);
// a.issued.dd=d.day;
// a.issued.mm=d.month;
//a.issued.yy=d.year; gotoxy(10,12);
printf("Issued date=%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy); gotoxy(10,13);
printf("The BOOK of ID %d is issued",a.id); a.duedate.dd=a.issued.dd+RETURNTIME; //for return date a.duedate.mm=a.issued.mm;
a.duedate.yy=a.issued.yy; if(a.duedate.dd>30)
{
a.duedate.mm+=a.duedate.dd/30; a.duedate.dd-=30;

}
if(a.duedate.mm>12)
{
a.duedate.yy+=a.duedate.mm/12; a.duedate.mm-=12;

}
gotoxy(10,14);
 
printf("To be return:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy); fseek(fs,sizeof(a),SEEK_END);
fwrite(&a,sizeof(a),1,fs); fclose(fs);
c=1;

}
if(c==0)
{
gotoxy(10,11);
printf("No record found");
}
gotoxy(10,15);
printf("Issue any more(Y/N):"); 
fflush(stdin); 
another=getche();
fclose(fp);

}


break;

}
case '2': //show issued book list
{
system("cls"); int j=4;
printf("*******************************Issued book list*******************************\n");
gotoxy(2,2);
printf("STUDENT NAME	CATEGORY ID BOOK NAME ISSUED DATE RETURN DATE");
FILE *fs;
fs=fopen("Issue.dat","rb"); 
while(fread(&a,sizeof(a),1,fs)==1)
 
{


gotoxy(2,j); printf("%s",a.stname); gotoxy(18,j); printf("%s",a.cat); gotoxy(30,j); printf("%d",a.id); gotoxy(36,j); printf("%s",a.name); gotoxy(51,j);
printf("%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy ); gotoxy(65,j);
printf("%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
//struct dosdate_t d;
//_dos_getdate(&d); gotoxy(50,25);
//		printf("Current date=%d-%d-%d",d.day,d.month,d.year); j++;

}
fclose(fs); gotoxy(1,25); returnfunc();
}
break;
case '3': //search issued books by id
{
system("cls");
gotoxy(10,6);
 
printf("Enter Book ID:"); int p,c=0;
char another='y'; 
while(another=='y')
{


scanf("%d",&p); fs=fopen("Issue.dat","rb"); while(fread(&a,sizeof(a),1,fs)==1)
{
if(a.id==p)
{
issuerecord(); gotoxy(10,12); printf("Press any key	");
getch(); issuerecord(); c=1;
}


}
fflush(stdin); 
fclose(fs); 
if(c==0)
{
gotoxy(10,8);
printf("No Record Found");
}
gotoxy(10,13);
printf("Try Another Search?(Y/N)");
 
another=getch();

}

}
break;
case '4': //remove issued books from list
{
system("cls"); int b;
FILE *fg; //declaration of temporary file for delete char another='y';
char another='y';
while(another=='y')
{
gotoxy(10,5);
printf("Enter book id to remove:"); 
scanf("%d",&b);
fs=fopen("Issue.dat","rb+");
while(fread(&a,sizeof(a),1,fs)==1)
{
if(a.id==b)
{
issuerecord(); findbook='t';
}
if(findbook=='t')
{
gotoxy(10,12);
printf("Do You Want to Remove it?(Y/N)"); if(getch()=='y')
{
fg=fopen("record.dat","wb+");
 
rewind(fs); while(fread(&a,sizeof(a),1,fs)==1)
{
if(a.id!=b)
{
fseek(fs,0,SEEK_CUR); fwrite(&a,sizeof(a),1,fg);
}
}
fclose(fs); fclose(fg);
remove("Issue.dat"); rename("record.dat","Issue.dat"); gotoxy(10,14);
printf("The issued book is removed from list");


}


}
if(findbook!='t')
{
gotoxy(10,15);
printf("No Record Found");
}

}
gotoxy(10,16);
printf("Delete any more?(Y/N)"); another=getch();
}

}
 
default: gotoxy(10,18);
printf("\aWrong Entry!!"); getch();
issuebooks(); break;
}
gotoxy(1,30); returnfunc();
}
void viewbooks(void) //show the list of book persists in library
{
int i=0,j; system("cls");
gotoxy(1,1);
printf("*********************************Book List*****************************"); gotoxy(2,2);
printf(" CATEGORY	ID   BOOK NAME	AUTHOR	QTY	PRICE	RackNo "); j=4;
fp=fopen("Bibek.dat","rb"); while(fread(&a,sizeof(a),1,fp)==1)
{
gotoxy(3,j); printf("%s",a.cat); gotoxy(16,j); printf("%d",a.id); gotoxy(22,j); printf("%s",a.name); gotoxy(36,j); printf("%s",a.Author);
 
gotoxy(50,j); printf("%d",a.quantity); gotoxy(57,j); printf("%.2f",a.Price); gotoxy(69,j); printf("%d",a.rackno);
printf("\n\n"); j++;
i=i+a.quantity;
}
gotoxy(3,25);
printf("Total Books =%d",i); fclose(fp);
gotoxy(35,25); returnfunc();
}
void viewbooks1(void) //show the list of book persists in library
{
int i=0,j; system("cls");
gotoxy(1,1);
printf("*********************************Book List*****************************"); gotoxy(2,2);
printf(" CATEGORY	ID   BOOK NAME	AUTHOR	QTY	PRICE	RackNo "); j=4;
fp=fopen("Bibek.dat","rb"); while(fread(&a,sizeof(a),1,fp)==1)
{
gotoxy(3,j); printf("%s",a.cat);
 
gotoxy(16,j); printf("%d",a.id); gotoxy(22,j); printf("%s",a.name); gotoxy(36,j); printf("%s",a.Author); gotoxy(50,j); printf("%d",a.quantity); gotoxy(57,j); printf("%.2f",a.Price); gotoxy(69,j); printf("%d",a.rackno);
printf("\n\n");
j++;
i=i+a.quantity;
}
gotoxy(3,25);
printf("Total Books =%d",i); fclose(fp);
gotoxy(35,25); returnfunc1();
}
void editbooks(void) //edit information about book
{
system("cls"); int c=0;
int d,e; gotoxy(20,4);
printf("****Edit Books Section****"); char another='y';
 
while(another=='y')
{
system("cls");
gotoxy(15,6);
printf("Enter Book Id to be edited:"); scanf("%d",&d); fp=fopen("Bibek.dat","rb+"); while(fread(&a,sizeof(a),1,fp)==1)
{
if(checkid(d)==0)
{
gotoxy(15,7);
printf("The book is availble"); gotoxy(15,8);
printf("The Book ID:%d",a.id); gotoxy(15,9);
printf("Enter new name:");scanf("%s",a.name); gotoxy(15,10);
printf("Enter new Author:");scanf("%s",a.Author); gotoxy(15,11);
printf("Enter new quantity:");scanf("%d",&a.quantity); gotoxy(15,12);
printf("Enter new price:");scanf("%f",&a.Price); gotoxy(15,13);
printf("Enter new rackno:");scanf("%d",&a.rackno); gotoxy(15,14);
printf("The record is modified"); fseek(fp,ftell(fp)-sizeof(a),0);
fwrite(&a,sizeof(a),1,fp); fclose(fp);
 
c=1;

}
if(c==0)
{
gotoxy(15,9);
printf("No record found");
}

}
gotoxy(15,16);
printf("Modify another Record?(Y/N)"); 
fflush(stdin);
another=getch() ;

}

returnfunc();

}
void returnfunc(void)
{
{
printf(" Press ENTER to return to main menu");
}
a:
if(getch()==13) //allow only use of enter 
mainmenu();
else goto a;
}
void returnfunc1(void)
{
{
printf(" Press ENTER to return to main menu");
 
}
a:
if(getch()==13) //allow only use of enter 
mainmenu1();
else goto a;
}
int getdata()
{
int t; 
gotoxy(20,3);
printf("Enter the Information Below"); 
gotoxy(20,4);
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"); 
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(20,5); printf("\xB2");gotoxy(46,5);printf("\xB2"); 
gotoxy(20,6); printf("\xB2");gotoxy(46,6);printf("\xB2"); 
gotoxy(20,7); printf("\xB2");gotoxy(46,7);printf("\xB2"); 
gotoxy(20,8); printf("\xB2");gotoxy(46,8);printf("\xB2"); 
gotoxy(20,9); printf("\xB2");gotoxy(46,9);printf("\xB2"); 
gotoxy(20,10); printf("\xB2");gotoxy(46,10);printf("\xB2"); 
gotoxy(20,11); printf("\xB2");gotoxy(46,11);printf("\xB2"); 
gotoxy(20,12);
 
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
gotoxy(21,5);
printf("Category:"); 
gotoxy(31,5); 
printf("%s",catagories[s-1]); 
gotoxy(21,6);
printf("Book ID:\t"); gotoxy(30,6); 
scanf("%d",&t); 
if(checkid(t) == 0)
{
gotoxy(21,13);
printf("\aThe book id already exists\a"); 
getch();
mainmenu(); 
return 0;
}
a.id=t; gotoxy(21,7);
printf("Book Name:");gotoxy(33,7); scanf("%s",a.name);
gotoxy(21,8); printf("Author:");gotoxy(30,8); scanf("%s",a.Author); gotoxy(21,9); printf("Quantity:");gotoxy(31,9); scanf("%d",&a.quantity); gotoxy(21,10); printf("Price:");gotoxy(28,10);
 
scanf("%f",&a.Price); gotoxy(21,11);
printf("Rack No:");gotoxy(30,11); scanf("%d",&a.rackno);
return 1;

}
int checkid(int t) //check whether the book is exist in library or not
{
rewind(fp); while(fread(&a,sizeof(a),1,fp)==1) if(a.id==t)
return 0; //returns 0 if book exits return 1; //return 1 if it not
}
int t(void) //for time
{
time_t t; time(&t);
printf("Date and time:%s\n",ctime(&t));


return 0 ;
}
void issuerecord() //display issued book's information
{
system("cls");
gotoxy(10,8);
printf("The Book has taken by Mr. %s",a.stname); gotoxy(10,9);
printf("Issued Date:%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy); gotoxy(10,10);
 
printf("Returning Date:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);

}
void loaderanim()
{
int loader; system("cls"); gotoxy(20,10); printf("LOADING.	");
printf("\n\n"); gotoxy(22,11);
for(loader=1;loader<20;loader++)
{
delay(100);printf("%c",219);}
}
