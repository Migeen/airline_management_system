#include<iostream>
#include<process.h>
#include<string.h>
#include<dos.h> 
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<conio.h>
#include<windows.h>
#include<ctype.h>

#define ENTER 13
#define SPACE 32
#define BKSP 8
#define ESC 27
#define TAB 9

using namespace std;

const int ROW =10,COL =10;

COORD c = {0, 0};                //for border
void gotoxy (int x, int y)              
{
 c.X = x; c.Y = y; // goto X and Y coordinates
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
struct admin_details
{
	char country[20],destination[20];
	char flight_num[20],date[20],time[20];
	int price;
	
}S;
struct customer_details
{
	char country[20],destination[20];
	char flight_num[20],date[20],time[20];
	int price;
	char userid[20];
}C,D;

class main_menu{
	public:
		void opening();
		void menu();
};
class admin{
	public:
		void admin_home();
		void admin_login();
		void admin_register();
		void admin_menu();
		void add_flights();
		void remove_flights();
		void edit_flights();
		void view_flights();
		void flight_details();
		
};
class customer{
	public:
	void customer_menu();
	void login();
	void register_user();
	void cus_menu();
	void book_flights();
	void view_flights();
	void cancel_flights();
	void view_booked_flights();
	void customer_flights();
};

struct details_customer
{
	char userid[20],password[20];
	
}P;
//
//
class shape{
      public:
		void line_hor(int,int,int,char);
	    void line_ver(int,int,int,char);
	    void box(int x1,int y1,int x2,int y2);
};
//**************************************************************************


void shape::box(int x1,int y1,int x2,int y2)
{
     for(int col=x1;col<x2 ;col++)
     {
      gotoxy(col,y1);
      printf("%c",196);
      gotoxy(col,y2);
      printf("%c",196);
      }

     for(int row=y1;row<y2;row++)
     {
      gotoxy(x1,row);
      printf("%c",179);
      gotoxy(x2,row);
      printf("%c",179);
      }
     gotoxy(x1,y1);
     printf("%c",218);
     gotoxy(x1,y2);
     printf("%c",192);
     gotoxy(x2,y1);
     printf("%c",191);
     gotoxy(x2,y2);
     printf("%c",217);
}

void shape::line_hor(int column1,int column2,int row, char c)
{
	for(column1;column1 <= column2;column1++){
		gotoxy(column1,row);
		cout<< c;
	}
}

void shape::line_ver(int row1,int row2, int column,char c)
{
	for(row1 ; row1 <= row2 ; row1++){
		gotoxy(column,row1);
		cout<<c;
	}
}

void main_menu::opening(){
	main_menu M;
	shape s;
 	s.box(0,6,115,20);
	gotoxy(45,14);
	cout<<"AIRLINE RESERVATION SYSTEM";
	getch();
	M.menu();
}
void main_menu::menu(){
	main_menu M;
	admin A;
	customer C;
	system("cls");
	gotoxy(50,7);
	cout<<"MAIN MENU";
	gotoxy(50,9);
	cout<<"1. ADMIN MENU ";
	gotoxy(50,11);
	cout<<"2. CUSTOMER MENU";
	gotoxy(50,13);
	cout<<"3. EXIT ";
	char num;
	gotoxy(55,18);
	printf("Enter your choice: ");
	gotoxy(75,18);
	cin>>num;
	
	switch(num)
	{
		case '1':
			A.admin_home();
			break;
		case '2':
			C.customer_menu();
		    break;
	    case '3':
	    	system("cls");
	    	exit(0);
	    	break;
		default:
			gotoxy(33,24);
		    cout<<"Invalid choice!!! Please try again . . .";
			system("pause");
			system("cls");
			M.menu();
		    break;	
	}
}

void admin::admin_home()
{
	system("cls");
	admin A;
	ifstream fin;
	fin.open("security.bin",ios::in|ios::out);
	if(fin)
	{
		A.admin_login();
	}
	else
	{
		A.admin_register();
	}
}
void admin::admin_login(){
	system("cls");
	admin A;
	char id[20],pass[20],userid[20],password[20];
	gotoxy(50,7);
	cout<<"A D M I N - L O G I N";
	gotoxy(52,11);
	cout<<"Username: " ;
	gotoxy(52,15);
	cout<<"Password: ";
	gotoxy(62,11);
	cin>>id;
	gotoxy(62,15);
	int i=0;
	char ch;
	while(1){
		ch=getch();
		if(ch==ENTER){
			pass[i]='\0';
			break;
		}
		else if(ch==BKSP){
			if(i>0){
				i--;
				pass[i]='\0';
				cout<<"\b \b";
			}
		}
		else if(ch==SPACE||ch==ESC||ch==TAB){
			continue;
		}
		else{
			pass[i]=ch;
			i++;
			cout<<"*";
		}
	}
	ifstream fin;
	fin.open("security.bin",ios::in|ios::binary);
	while(fin>>userid>>password){
		if(strcmp(id,userid)==0 && strcmp(pass,password)==0){
			gotoxy(47,19);
			cout<<"L O G I N - S U C C E S S F U L!!";
			getch();
			A.admin_menu();
		}
		else{
			gotoxy(47,19);
			cout<<"Error!! please try again ";
			getch();
			A.admin_login();
		}
	}
	fin.close();
}
void admin::admin_register(){
	system("cls");
	admin A;
	char id[20],pass[20],password[20],userid[20];
	gotoxy(50,7);
	cout<<"A D M I N - R E G I S T E R";
	gotoxy(52,11);
	cout<<"Enter the Username: ";
	gotoxy(52,15);
	cout<<"Enter the Password: ";
	gotoxy(62,11);
	cin>>userid;
	gotoxy(62,15);
		int i=0;
	char ch;
	while(1){
		ch=getch();
		if(ch==ENTER){
			password[i]='\0';
			break;
		}
		else if(ch==BKSP){
			if(i>0){
				i--;
				password[i]='\0';
				cout<<"\b \b";
			}
		}
		else if(ch==SPACE||ch==ESC||ch==TAB){
			continue;
		}
		else{
			password[i]=ch;
			i++;
			cout<<"*";
		}
	}
	//cin>>password;
	ofstream fout;
	fout.open("security.bin",ios::app|ios::binary);
	fout<<userid<<" "<<password<<endl;
	gotoxy(30,16);
	cout<<"REGISTRATION-SUCCESSFULL !!";
	gotoxy(30,17);
	cout<<"Redirectring to Login Page !!";
	getch();
	fout.close();
	A.admin_login();
}

void admin::admin_menu(){
	admin A;
	main_menu M;
	system("cls");
	gotoxy(50,5);
	cout<<"ADMIN MENU";
	gotoxy(50,8);
	cout<<"1. DISPLAY FlIGHTS ";
	gotoxy(50,10);
	cout<<"2. ADD FLIGHTS  ";
	gotoxy(50,12);
	cout<<"3. REMOVE FLIGHTS ";
	gotoxy(50,14);
	cout<<"4. EDIT FLIGHTS  ";
	gotoxy(50,16);
	cout<<"5. EXIT TO MAIN MENU ";
	char num;
	
	gotoxy(50,19);
	printf("Enter your choice: ");
	gotoxy(70,19);
	cin>>num;
		switch(num)
	{
		case '1':
			A.view_flights();
			break;
		case '2':
	    	A.add_flights();
		    break;
	    case '3':
			A.remove_flights();
	    	break;
	    case '4':
	    	A.edit_flights();
	    	break;
	    case '5':
	    	system("cls");
	    	M.menu();
	    	break;
		default:
			gotoxy(45,23);
		    cout<<"Invalid choice!!! Please try again . . .";
			system("pause");
			system("cls");
			A.admin_menu();
		    break;	
	}
}

void admin::view_flights(){
	system("cls");
	admin A;
	ifstream fin;
	fin.open("flight.bin",ios::in|ios::binary);
	cout<<"SN\t\tCOUNTRY\t\tFLIGHT_NO\t\tPRICE\t\tDESTINATION\t\tDATE\t\tTIME";
	int i=1,x=2;
	fin.read((char*)&S,sizeof(S));
	while(fin)
	{
		gotoxy(1,x);
		cout<<i;
		gotoxy(16,x);
		cout<<S.country;
		gotoxy(32,x);
		cout<<S.flight_num;		
		gotoxy(56,x);
		cout<<S.price;		
		gotoxy(72,x);
		cout<<S.destination;
		gotoxy(96,x);
		cout<<S.date;
		gotoxy(113,x);
		cout<<S.time;		
		i++;
		x++;
		fin.read((char*)&S,sizeof(S));
	}
	fin.close();
	getch();
	system("cls");
	A.admin_menu();
}

void admin::add_flights(){	
	system("cls");
	admin A;	
	ofstream fout;
	fout.open("flight.bin",ios::app|ios::binary);
	gotoxy(37,7);
	cout<<"Enter The Country Name: ";
	gotoxy(60,7);
	cin>>S.country;
	fflush(stdin);
	gotoxy(37,9);
	cout<<"Enter The Flight Number: ";
	gotoxy(61,9);
	cin>>S.flight_num;
	fflush(stdin);
	gotoxy(37,11);
	cout<<"Enter the Price: ";
	gotoxy(53,11);
	cin>>S.price;
	fflush(stdin);
	gotoxy(37,13);
	cout<<"Enter the Destination: ";
	gotoxy(60,13);
	cin>>S.destination;
	fflush(stdin);
	gotoxy(37,15);
	cout<<"Enter the date: ";
	gotoxy(52,15);
	cin>>S.date;
	fflush(stdin);
	gotoxy(37,17);
	cout<<"Enter the time: ";
	gotoxy(52,17);
	cin>>S.time;
	fflush(stdin);
	fout.write((char*)&S,sizeof(S));
	fout.close();
	gotoxy(37,19);
	cout<<"Record Added Successfully";
	getch();
	system("cls");
	A.admin_menu();
}

void admin::remove_flights(){
		system("cls");
		admin A;
		char num[10];
		ifstream fin;
		ofstream fout;
		fin.open("flight.bin",ios::in|ios::binary);
		fout.open("Newflight.bin",ios::app|ios::binary);
		gotoxy(35,5);
		cout<<"Enter the flight number to remove: ";
		cin>>num;
		fin.read((char*)&S,sizeof(S));
		while(!fin.eof())
		{
			if(strcmp(num,S.flight_num)==0)
			{
				gotoxy(50,8);
				cout<<"Country Name: "<<S.country;
				gotoxy(50,9);
				cout<<"Flight Number: "<<S.flight_num;
				gotoxy(50,10);
				cout<<"Ticket Price: "<<S.price;
				gotoxy(50,11);
				cout<<"Destination: "<<S.destination;
				gotoxy(50,12);
				cout<<"Time: "<<S.time;
				gotoxy(50,13);
				cout<<"Date: "<<S.date;				
				gotoxy(35,15);
				cout<<"Are You Sure You Want To Remove This Record(Y/N): ";
				char ch;
				gotoxy(84,15);
				cin>>ch;
				if(ch=='Y'||ch=='y')
				{
				gotoxy(35,17);
				cout<<"R E C O R D - R E M O V E D - S U C C E S S F U L L Y !!!";
				}
				else
				{				
					A.admin_menu();			
				}
				getch();
			}
			else
			{
			fout.write((char*)&S,sizeof(S));
			}
		fin.read((char*)&S,sizeof(S));
		}
	fin.close();
	fout.close();
	remove("flight.bin");
	rename("Newflight.bin","flight.bin");
	getch();
	A.admin_menu();
}
	
void admin::edit_flights(){
		system("cls");
		admin A;
		char num[20];
		ifstream fin;
		ofstream fout;
		fin.open("flight.bin",ios::in|ios::binary);
		fout.open("Newflight.bin",ios::app|ios::binary);
		gotoxy(40,5);
		cout<<"Enter the flight number to edit: ";
		gotoxy(73,5);		
		cin>>num;
		fin.read((char*)&S,sizeof(S));
		while(!fin.eof())
		{
			if(strcmp(num,S.flight_num)==0)
			{
				gotoxy(50,7);
				cout<<"Previous Records: ";
				gotoxy(50,8);
				cout<<"Country Name: "<<S.country;
				gotoxy(50,9);
				cout<<"Flight Number: "<<S.flight_num;
				gotoxy(50,10);
				cout<<"Ticket Price: "<<S.price;
				gotoxy(50,11);
				cout<<"Destination: "<<S.destination;
				gotoxy(50,12);
				cout<<"Time: "<<S.time;
				gotoxy(50,13);
				cout<<"Date: "<<S.date;
				gotoxy(50,14);
				cout<<"New Records: ";
				gotoxy(50,15);
				cout<<"Enter Country Name: ";
				gotoxy(70,15);
				cin>>S.country;
				gotoxy(50,16);
				cout<<"Enter Flight Number: ";
				gotoxy(71,16);
				cin>>S.flight_num;
				gotoxy(50,17);
				cout<<"Enter Price: ";
				gotoxy(63,17);
				cin>>S.price;
				gotoxy(50,18);
				cout<<"Enter Destination: ";
				gotoxy(69,18);
				cin>>S.destination;
				gotoxy(50,19);
				cout<<"Enter Time: ";
				gotoxy(62,19);
				cin>>S.time;
				gotoxy(50,20);
				cout<<"Enter Date: ";
				gotoxy(62,20);
				cin>>S.date;				
				fout.write((char*)&S,sizeof(S));
				gotoxy(50,22);
				cout<<"Records Updated Successfully";
			}
			else
			{
			fout.write((char*)&S,sizeof(S));
			}
		fin.read((char*)&S,sizeof(S));
		}
		getch();
	fin.close();
	fout.close();
	remove("flight.bin");
	rename("Newflight.bin","flight.bin");
	A.admin_menu();
}


void customer::customer_menu(){
	main_menu M;
	customer C;
	system("cls");
	gotoxy(50,5);
	cout<<"LOGIN MENU";
	gotoxy(52,7);
	cout<<"1. REGISTER";
	gotoxy(52,9);
	cout<<"2. LOGIN";
	gotoxy(52,11);
	cout<<"3. EXIT TO MAIN MENU";
	char num;
	gotoxy(50,15);
	printf("Enter your choice: ");
	gotoxy(70,15);
	cin>>num;
		switch(num)
	{
		case '1':
			C.register_user();
			break;
		case '2':
			C.login();
		    break;
	    case '3':
	    	M.menu();
	    	break;
		default:
			gotoxy(30,19);
		    cout<<"Invalid choice!!! Please try again . . .";
			system("pause");
			system("cls");
			C.customer_menu();
		    break;	
	}
}
	
void customer::login(){
	system("cls");
	customer C;
	system("cls");
	char id[20],pass[20];
	gotoxy(50,7);
	printf("C U S T O M E R - L O G I N");
	gotoxy(52,11);
	cout<<"Username: " ;
	gotoxy(52,15);
	cout<<"Password: ";
	gotoxy(62,11);
	cin>>id;
	gotoxy(62,15);
	int i=0;
	char ch;
	while(1){
		ch=getch();
		if(ch==ENTER){
			pass[i]='\0';
			break;
		}
		else if(ch==BKSP){
			if(i>0){
				i--;
				pass[i]='\0';
				cout<<"\b \b";
			}
		}
		else if(ch==SPACE||ch==ESC||ch==TAB){
			continue;
		}
		else{
			pass[i]=ch;
			i++;
			cout<<"*";
		}
	}
	ifstream fin;
	fin.open("customer.bin",ios::in|ios::binary);
	fin.read((char*)&P,sizeof(P));
	if(!fin) {
		
		gotoxy(30,16);
        cout<<"No Records Found !! ";
        getch();
        return;
    }
	while(!fin.eof())
	{
		if(strcmp(id,P.userid)==0)
		{
			if(strcmp(pass,P.password)==0)
			{
			gotoxy(48,19);
			cout<<"L O G I N - S U C C E S S F U L!!";
			getch();
			C.cus_menu();
			}
			else
			{
			gotoxy(48,19);
			cout<<"Error!! please try again ";
			getch();
			C.login();
			}
		}
		else
		{
			gotoxy(48,19);
			cout<<"Error!! please try again ";
			getch();
			C.login();
		}
		fin.read((char*)&P,sizeof(P));
	}
	fin.close();
}
void customer::register_user(){
	l1:
	system("cls");
	customer C;
	ifstream fin;
	ofstream fout;
	//char password[20],userid[20];
	gotoxy(50,7);
	printf("C U S T O M E R - R E G I S T E R");
	gotoxy(52,11);
	cout<<"Enter the Username: ";
	gotoxy(52,15);
	cout<<"Enter the Password: ";
	gotoxy(72,11);
	char user_ID[20];
	cin>>user_ID;
	fin.open("customer.bin",ios::in|ios::binary);
	fin.read((char*)&P,sizeof(P));
	while(fin)
	{
		if(strcmp(user_ID,P.userid)==0)
		{
			gotoxy(22,24);
			cout<<"ID-ALREADY-EXIST !! ENTER NEW ID . . . ";
			getch();
			goto l1;
		}
		fin.read((char*)&P,sizeof(P));
	}
	fin.close();
	
	strcpy(P.userid,user_ID);
	gotoxy(72,15);
	int i=0;
	char ch;
	while(1){
		ch=getch();
		if(ch==ENTER){
			P.password[i]='\0';
			break;
		}
		else if(ch==BKSP){
			if(i>0){
				i--;
				P.password[i]='\0';
				cout<<"\b \b";
			}
		}
		else if(ch==SPACE||ch==ESC||ch==TAB){
			continue;
		}
		else{
			P.password[i]=ch;
			i++;
			cout<<"*";
		}
	}
	fout.open("customer.bin",ios::app|ios::binary);
	fout.write((char*)&P,sizeof(P));
	gotoxy(48,19);
	cout<<"YOUR REGISTRATION IS SUCESSFULL!";
	gotoxy(48,20);
	cout<<"REDIRECTING TO LOGIN PAGE!!";
	getch();
	fout.close();
	C.login();
}
void customer::cus_menu(){
	main_menu M;
	customer C;
	system("cls");
	gotoxy(50,5);
	cout<<"CUSTOMER MENU";
	gotoxy(52,8);
	cout<<"1. BOOK FLIGHTS";
	gotoxy(52,10);
	cout<<"2. CANCEL FLIGHTS";
	gotoxy(52,12);
	cout<<"3. VIEW FLIGHTS" ;
	gotoxy(52,14);
	cout<<"4. VIEW BOOKED FLIGHTS";
	char num;
	gotoxy(52,16);
	cout<<"5. GO TO MAIN MENU";
	
	gotoxy(50,18);
	printf("Enter your choice: ");
	gotoxy(70,18);
	cin>>num;
	
	switch(num){
		case '1':
			  C.book_flights();
			break;
		case '2':
			  C.cancel_flights();
			break;
		case '3':
			  C.view_flights();
			break;
		case '4':
			  C.view_booked_flights();
			break;
		case '5':
			system("cls");
			M.menu();
	    	break;
		default:
			gotoxy(25,22);
		    cout<<"Invalid choice!!! Please try again . . .";
			system("pause");
			system("cls");
			C.cus_menu();
		    break;	
				
	}
}

void customer::book_flights(){
	L1:
	system("cls");
	admin A;
	customer CU;
	ifstream fin;
	fin.open("flight.bin",ios::in|ios::binary);
	fin.read((char*)&S,sizeof(S));
	cout<<"SN\t\tCOUNTRY\t\tFLIGHT_NO\t\tPRICE\t\tDESTINATION\t\tDATE\t\tTIME";
	int i=1,x=2;
	while(fin)
	{
		gotoxy(1,x);
		cout<<i;
		gotoxy(16,x);
		cout<<S.country;
		gotoxy(32,x);
		cout<<S.flight_num;		
		gotoxy(56,x);
		cout<<S.price;		
		gotoxy(72,x);
		cout<<S.destination;
		gotoxy(96,x);
		cout<<S.date;
		gotoxy(113,x);
		cout<<S.time;
		fin.read((char*)&S,sizeof(S));
		i++;
		x++;
	}
	fin.close();
	ofstream fout;
	cout<<endl<<endl;
	cout<<"Enter the Flight Number To Book: ";
	cin>>C.flight_num;
	ifstream iff;
	fout.open("cus_flight.bin",ios::app|ios::binary);
	iff.open("flight.bin",ios::in|ios::binary);
	iff.read((char*)&S,sizeof(S));
	while(iff)
	{
		if(strcmp(S.flight_num,C.flight_num)==0)
		{
			strcpy(C.country,S.country);
			strcpy(C.flight_num,S.flight_num);
			C.price=S.price;
			strcpy(C.date,S.date);
			strcpy(C.time,S.time);
			strcpy(C.destination,S.destination);
			strcpy(C.userid, P.userid);
			fout.write((char*)&C,sizeof(C));
			goto l2;
		}
		iff.read((char*)&S,sizeof(S));
	}
	cout<<"ERROR!! ENTER VALID FLIGHT NUMBER . . . ";
	getch();
	goto L1;
	l2:
	iff.close();
	cout<<"Country : "<<C.country<<endl;	
	cout<<"Flight No : "<<C.flight_num<<endl;
	cout<<"Price : "<<C.price<<endl;
	cout<<"Destination : "<<C.destination<<endl;
	cout<<"Date : "<<C.date<<endl;
	cout<<"Time : "<<C.time<<endl;
	cout<<endl<<endl<<"Flight Has Been Booked Successfully";
	getch();
	fout.close();
	CU.cus_menu();
	system("cls");
	
}
	
void customer::cancel_flights()
{
		system("cls");
		admin A;
		customer CU;
		char id[20];
		ifstream fin;
		ofstream fout;
		fin.open("cus_flight.bin",ios::in|ios::binary);
		fout.open("New_flight.bin",ios::app|ios::binary);
		cout<<"Enter the customer id to  cancel: ";
		cin>>id;
		fin.read((char*)&C,sizeof(C));
		while(!fin.eof())
		{
			if(strcmp(id,C.userid)==0)
			{
				cout<<endl;
				cout<<"Country Name: "<<C.country;
				cout<<endl;
				cout<<"Flight Number: "<<C.flight_num;
				cout<<endl;
				cout<<"Ticket Price: "<<C.price;
				cout<<endl;
				cout<<"Destination: "<<C.destination;
				cout<<endl;
				cout<<"Time: "<<C.time;
				cout<<endl;
				cout<<"Date: "<<C.date;				
				cout<<endl<<"Are You Sure You Want to cancel This Flights(Y/N): ";
				char ch;
				cin>>ch;
				if(ch=='Y'||ch=='y')
				{
				cout<<endl;
				cout<<"F L I G H T S -  C A N C E L L E D - S U C C E S S F U L L Y !!!";
				}
				else
				{
					CU.cus_menu();				
				}
				getch();
			}
			else
			{
			fout.write((char*)&C,sizeof(C));
			}
		fin.read((char*)&C,sizeof(C));
		}
	fin.close();
	fout.close();
	remove("cus_flight.bin");
	rename("New_flight.bin","cus_flight.bin");
	getch();
	CU.cus_menu();
}

void customer::view_flights()
{
	system("cls");
	admin A;
	customer CU;
	ifstream fin;
	fin.open("flight.bin",ios::in|ios::binary);
	fin.read((char*)&S,sizeof(S));
	cout<<"SN\t\tCOUNTRY\t\tFLIGHT_NO\t\tSEAT\t\tPRICE\t\tDESTINATION\t\tTIME\\DATE";
	int i=1,x=2;
	while(fin)
	{
		gotoxy(1,x);
		cout<<i;
		gotoxy(16,x);
		cout<<S.country;
		gotoxy(32,x);
		cout<<S.flight_num;		
		gotoxy(56,x);
		cout<<S.price;		
		gotoxy(72,x);
		cout<<S.destination;
		gotoxy(96,x);
		cout<<S.date;
		gotoxy(113,x);
		cout<<S.time;	
		fin.read((char*)&S,sizeof(S));
		i++;
		x++;
	}
	fin.close();
	getch();
	system("cls");
	CU.cus_menu();
}

void customer::view_booked_flights()
{
	system("cls");
	customer CU;
	char id[20];
	ifstream iff;
	iff.open("cus_flight.bin",ios::in|ios::binary);
	cout<<"Enter Your ID: ";
	cin>>id;
	int i=1,x=2;
	iff.read((char*)&C,sizeof(C));
	while(!iff.eof())
	{
		if(strcmp(id,C.userid)==0)
		{
		gotoxy(1,x);
		cout<<i;
		gotoxy(16,x);
		fflush(stdin);
		cout<<C.country;
		gotoxy(32,x);
		fflush(stdin);
		cout<<C.flight_num;
		gotoxy(56,x);
		cout<<S.price;	
		gotoxy(72,x);
		cout<<S.destination;
		gotoxy(96,x);
		cout<<S.date;
		gotoxy(113,x);
		cout<<S.time;	
		}
		iff.read((char*)&C,sizeof(C));
		i++;
		x++;
	}

	iff.close();
	getch();
	system("cls");
	CU.cus_menu();
}

int main(){
	main_menu M;
	M.opening();
	return 0;
}

