#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

string global_id , global_institute , global_name , global_type;


void logo();
int start_menu();
bool login_function();
void signup_function();
void account_list();
int login_menu();
bool login_institute();
void signup_institute();
void institute_details();
int final_menu();
void borrow_book();
void return_book();
void available_books();
void borrowed_books();
void add_book();
void all_books();
void all_borrowed_books();
void all_returned_books();
void all_students();
void all_fresh_books();

int main()
{
	bool a=0;
	int i=0;
	int switch_first;
	do
	{
		system("cls");
		if (i==0)
		{
			switch_first=start_menu();
			switch (switch_first)
			{
				case 1:
					{
						a=login_function();
						if(a==1)
							i=1;
						break;
					}
				case 2:
					{
						signup_function();
						break;
				 	}
				case 3:
					{
						account_list();
						break;
					}
				case 4:
					{
						logo();
						cout << "thank you for your time see you soon!!!!!!!!!!!!!";
						return 0;
					}
			}
			system("cls");
			if (a==0)
				continue;
		}
		if(i==1)
		{
			switch_first=login_menu();
			switch (switch_first)
			{
				case 1:
					{
						a=login_institute();
						if (a==0)
							i=2;
						break;
					}
				case 2:
					{
						signup_institute();
						break;
					}
				case 3:
					{
						institute_details();
						break;
					}
				case 4:
					{
						a=0;
						i=0;
						continue;
					}
			}
			if(a==1 && i==1)
				continue;
		}
		if(i==2)
			i=final_menu();
	}while(true);
}

void logo()
{
	cout << "\n\n\n";
	cout << "\t\t" << "     _____  _____               _____________" << endl;
	cout << "\t\t" << "     | ||| ///| |  --------\\    || |_     / |" << endl;
	cout << "\t\t" << "     |_|||/// |_|  --------/    | | |  \\   /|" << endl;
	cout << "\t\t" << "    ==============              |___________|" << endl;
	cout << "\t\t" << "    []          []                    []     " << endl;
	cout << "\t\t" << "    []          []                   /__\\   " << endl;
	cout << "\t\t" << "===================================================" << endl;
	cout << "\t\t\t" << " _      ___        ___  ______  " << endl; 
	cout << "\t\t\t" << "| |     |  \\      /  | |  ____| " << endl;
	cout << "\t\t\t" << "| |     | |\\\\    //| | | |____  " << endl;
	cout << "\t\t\t" << "| |     | | \\\\  // | | |____  | " << endl;
	cout << "\t\t\t" << "| |____ | |  \\\\//  | |  ____| | " << endl;
	cout << "\t\t\t" << "|______||_|   \\/   |_| |______| " << endl;
	cout << "\n\n\n================================================================================\n";
	
}

int start_menu()
{
	int A;
	do
	{
		logo();
		cout << "welcome!!!!!!!!!!!\n(1) If you signup your account will be saved you don't have to signup again.\n(2) You cannot login without an account)\n"
			 << "1. Login\n"
			 << "2. Create an account\n"
			 << "3. View all accounts\n"
			 << "4. Exit\n"
			 << "\t\t\tENTER YOUR COMMAND: ";
		cin >> A;
		system("cls");
	}while(A>4 && A<1);
	return A;
}

bool login_function()
{

	bool check=0;
	char answer='n';
	string id , password , institute;
	do
	{
		logo();
		
		string user_id , user_password;
		cout << "ENTER YOUR USER_NAME: ";
		cin >> user_id;
		cout << "ENTER YOUR PASSWORD: ";
		cin >> user_password;
		
		ifstream login_data("account_details.txt");
		while (login_data >> id >> password >> institute)
		{	
			if(id==user_id && password==user_password)
			{
				check=1;
				global_id=id;
				global_institute=institute;
			}
		}
		if(check==0)
		{
			cout << "INVALID DEYAILS DO YOU WANT TO TRY AGAIN!!!!(Y/N)";
			cin >> answer;
		}
		system("cls");
	}while(check==0 && (answer=='y' || answer=='Y'));
	return check;
}

void signup_function()
{
	do
	{
		logo();
		bool try_again=0;
		string id , password , institute;
		cout << "ENTER USER_NAME: ";
		cin >> id;
		cout << "ENTER PASSWORD: ";
		cin >> password;
		cout << "INSTITUTE NAME: ";
		cin >> institute;
		string stored_id , stored_institute , stored_password;
		ifstream login_data("account_details.txt");
		while(login_data >> stored_id >> stored_password >> stored_institute)
		{
			if (stored_id == id && stored_password==password)
			{
				cout << "Already in database..\n";
				system("pause");
				login_data.close();
				break;
				try_again = 1;
			}
		}
		system("cls");
		if (try_again)
			continue;
		else{
			cout << "Do you want to save this data(y/n): ";
			char a;
			cin >> a;
			if (a == 'n' || a == 'N'){
				break;
			}
		}
		ofstream signup_data("account_details.txt",ios::app);
		signup_data << id << "\t" << password << "\t" << institute << endl;
		break;
	}while(true);
}

void account_list()
{
	logo();
	string A,B,C;
	int id = 1;
	cout << "ID\t\t\t\tUSER_NAME\t\t\t\tINSTITUTE\n";
	ifstream data("account_details.txt");
	while(data >> A >> B >> C)
		cout << id++ << "\t\t\t\t" << A << "\t\t\t\t" << C << endl;
	system("pause");
	system("cls");
}

int login_menu()
{
	string id=global_id , institute=global_institute;
	int A;
	do
	{
		logo();
		cout << "USER_NAME: " << id << "\t\t\t" << "INSTITUTE: " << institute << endl
			 << "TO GET EXCESS YOU HAVE TO FILL A FORM FIRST TO GET REGISTERED <<(ADD ID)>>\n"
			 << "1. USER_LOGIN\n"
			 << "2. ADD USER\n"
			 << "3. VIEW ALL " << institute << " USERS\n"
			 << "4. LOG OUT\n"
			 << "ENTER YOUR COMMAND:";
		cin >> A;
		system("cls");
	}while(A>4 && A<1);
	return A;
}

bool login_institute()
{
	bool check=1;
	char answer='n';
	string name , password , type , file_name=global_institute+"_details.txt";
	do
	{
		logo();
		
		string user_name , user_password;
		cout << "ENTER YOUR USER NAME :";
		cin >> user_name;
		cout << "ENTER YOUR PASSWORD :";
		cin >> user_password;
		
		ifstream login_data(file_name.c_str());
		while (login_data >> name >> password >> type)
		{	
			if(name==user_name && password==user_password)
			{
				check=0;
				global_name=name;
				global_type=type;
			}
		}
		if(check==1)
		{
			cout << "INVALID DETAILS DO YOU WANT TO TRY AGAIN!!!!(Y/N)";
			cin >> answer;
		}
		system("cls");
	}while(check==1 && (answer=='y' || answer=='Y'));
	return check;
}

void signup_institute()
{
	do
	{
		logo();
		bool try_again=0;
		string name , password , type;
		cout << "ENTER YOUR NAME: ";
		cin >> name;
		cout << "ENTER PASSWORD: ";
		cin >> password;
		cout << "ACCOUNT TYPE\n1) for STUDENT[use='std']\n2) for LIBRARIAN[use='lib'])\nENTER TYPE: ";
		cin >> type;
		while(type!="std" && type!="lib")
		{
			cout << "wrong type........... Are you blind or dumb????............enter type again..........\n";
			cin >> type;
		}
		string stored_name , stored_type , stored_password;
		string file_name=global_institute+"_details.txt";
		ifstream login_data(file_name.c_str());
		while(login_data >> stored_name >> stored_password >> stored_type)
		{
			if (stored_name == name && stored_password==password)
			{
				cout << "we have this name registered !!!!!!!!!!!!!!!!!!!!! try again........\n";
				system("pause");
				login_data.close();
				try_again=1;
				break;
			}
		}
		system("cls");
		if (try_again)
			continue;
		else{
			cout << "Do you want to save this data(y/n): ";
			char a;
			cin >> a;
			if (a == 'n' || a == 'N'){
				break;
			}
		}
		ofstream signup_data(file_name.c_str() , ios::app);
		signup_data << name << "\t" << password << "\t" << type << endl;
		break;
	}while(true);
}

void institute_details()
{
	logo();
	string A,B,C;
	cout << "USER\t\t\t\tTYPE\n";
	string file_name=global_institute+"_details.txt";
	ifstream data(file_name.c_str());
	while(data >> A >> B >> C)
		cout << A << "\t\t\t\t" << C << endl;
	system("pause");
	system("cls");
}

int final_menu()
{
	bool exit=0;
	int control,i;
	do
	{
		logo();
		cout << "NAME: " << global_name << "\t\t\t" << "TYPE: " << global_type << endl;
		if (global_type=="std")
		{
			cout << "1. borrow book\n"
				 << "2. return book\n"
				 << "3. see available books\n"
				 << "4. see borrowed books\n"
				 << "5. exit\n"
				 << "ENTER YOUR COMMAND :";
			cin >> control;
			system("cls");
			switch(control)
			{
				case 1:
					{
						borrow_book();
						break;
					}
				case 2:
					{
						return_book();
						break;
					}
				case 3:
					{
						available_books();
						break;
					}
				case 4:
					{
						borrowed_books();
						break;
					}
				case 5:
						exit=1 ;
			}
		}
		
		if (global_type=="lib")
		{
			cout << "1. add book\n"
				 << "2. see all fresh books\n"
				 << "3. see all students\n"
				 << "4. see all borrowed books\n"
				 << "5. see all books\n"
				 << "6. see all returned books\n"
				 << "7. exit\n"
				 << "ENTER YOUR COMMAND :";
			cin >> control;
			system("cls");
			logo();
			switch (control)
			{
				case 1:
					{
						add_book();
						system("pause");
						break;
					}
				case 2:
					{
						all_fresh_books();
						system("pause");
						break;
					}
				case 3:
					{
						all_students();
						system("pause");
						break;
					}
				case 4:
					{
						all_borrowed_books();
						system("pause");
						break;
					}
				case 5:
					{
						all_books();
						system("pause");
						break;
					}
				case 6:
					{
						all_returned_books();
						system("pause");
						break;
					}
				case 7:
						exit=1;
			}
		}
		system("cls");
		if(exit==1)
			i=1;
	}while(exit==0);
	return i;
}

void borrow_book()
{
	bool latest=0;
	available_books();
	cout << "CHOOSE ANY BOOK: ";
	string mybook;
	cin >> mybook;
	string A,B,C,D,E;
	string RA,RB,RC,RD,RE;
	string file_name=global_institute+"_books.txt";
	ifstream book_details(file_name.c_str());
	while(book_details >> A >> B >> C >> D >> E)
	{
		if (A==mybook)
		{
			latest=0;
			if(E=="library")
			{
				latest=1;
				RA=A,RB=B,RC=C,RD="borrowed",RE=global_name;
			}
		}
	}
	if(latest==0)
		cout << "ARE YOU SERIOUS IS THERE ANY BOOK UP THERE LIKE THIS .................\n";
	else
		{
			ofstream book_details(file_name.c_str() , ios::app);
			book_details << RA << "\t" << RB<< "\t" << RC << "\t" << RD << "\t" << RE << endl;
			book_details.close();
			cout << "YOU HAVE BORROWED THE BOOK\n";
		}
	system("pause");
}

void return_book()
{
	bool latest=0;
	borrowed_books();
	cout << "CHOOSE ANY BOOK: ";
	string mybook;
	cin >> mybook;
	string A,B,C,D,E;
	string RA,RB,RC,RD,RE;
	string file_name=global_institute+"_books.txt";
	ifstream book_details(file_name.c_str());
	while(book_details >> A >> B >> C >> D >> E)
	{
		if (A==mybook)
		{
			latest=0;
			if(E==global_name)
			{
				latest=1;
				RA=A,RB=B,RC=C,RD="returned",RE="library";
			}
		}
	}
	if(latest==0)
		cout << "ARE YOU SERIOUS IS THERE ANY BOOK UP THERE LIKE THIS .................\n";
	else
		{
			ofstream book_details(file_name.c_str() , ios::app);
			book_details << RA << "\t" << RB<< "\t" << RC << "\t" << RD << "\t" << RE << endl;
			book_details.close();
			cout << "YOU HAVE RETURNED THE BOOK\n";
		}
		system("pause");
}

void available_books()
{
	cout << "following are available books if there is nothing then not a single book is available\n";
	bool latest=0;
	string file_name=global_institute+"_books.txt";
	string a,b,c,d,e,A,B,C,D,E;
	cout << "BOOK\tAuthor\tID\n";
	ifstream outer_file(file_name.c_str());
	while (outer_file >> a >> b >> c >> d >> e)
	{
		if(d=="available")
		{
			ifstream inner_file(file_name.c_str());
			while (inner_file >> A >> B >> C >> D >> E)
			{
				if (A==a && B==b && c==C)
				{
					latest=0;
					if(E=="library")
					{
						latest=1;
					}
				}
			}
			if (latest==1)
				cout << a << "\t" << b << "\t" << c << endl;
		}
	}
	system("pause");
}

void borrowed_books()
{
	logo();
	cout << "following are borrowed books if there is nothing then not a single book is borrowed\n";
	bool latest=0;
	string file_name=global_institute+"_books.txt";
	string a,b,c,d,e,A,B,C,D,E;
	cout << "BOOK\tAuthor\tID\n";
	ifstream outer_file(file_name.c_str());
	while (outer_file >> a >> b >> c >> d >> e)
	{
		if(d=="available")
		{
			ifstream inner_file(file_name.c_str());
			while (inner_file >> A >> B >> C >> D >> E)
			{
				if (A==a && B==b && c==C)
				{
					latest=0;
					if(E==global_name)
					{
						latest=1;
					}
				}
			}
			if (latest==1)
				cout << a << "\t" << b << "\t" << c << endl;
		}
	}
	system("pause");
}

void add_book()
{
	bool id;
	do
	{
		id=0;
		string A,B,C,D,E;
		cout << "ENTER BOOK NAME: ";
		cin >> A;
		cout << "ENTER AUTHOR NAME: ";
		cin >> B;
		cout << "ASSIGN BOOK ID: ";
		cin >> C;
		D="available", E="library";
		string file_name=global_institute+"_books.txt";
		string a,b,c,d,e;
		ifstream myfile(file_name.c_str());
		while(myfile >> a >> b >> c >> d >> e)
		{
			if(a==A || c==C)
			{
				cout << "UNAVILABLE NAME or ID.\n";
				myfile.close();
				id=1;
				break;
			}
		}
		if (id==1)
			continue;
		ofstream file(file_name.c_str(), ios::app);
		file << A  << "\t" << B << "\t" << C << "\t" << D << "\t" << E << endl;  
		file.close();
		cout << "BOOK HAS BEEN ADDED IN THE SYSTEM................................\n";
	}while(false);
}

void all_books()
{
	cout << "BOOK\tAuthor\tID\n";
	string file_name=global_institute+"_books.txt";
	string a,b,c,d,e;
	ifstream outer_file(file_name.c_str());
	while (outer_file >> a >> b >> c >> d >> e)
	{
		if(d=="available")
		{
			cout << a  << "\t" << b << "\t" << c << endl; 
		}
	}
}

void all_borrowed_books()
{
	bool latest=0;
	string file_name=global_institute+"_books.txt";
	string a,b,c,d,e,A,B,C,D,E;
	ifstream outer_file(file_name.c_str());
	while (outer_file >> a >> b >> c >> d >> e)
	{
		if(d=="available")
		{
			ifstream inner_file(file_name.c_str());
			while (inner_file >> A >> B >> C >> D >> E)
			{
				if (A==a && B==b && c==C)
				{
					latest=0;
					if(D=="borrowed")
					{
						latest=1;
					}
				}
			}
			if(latest==1)
			{
				cout << A << " is in poessission of " << E << endl;
			}
		}
	}
}

void all_returned_books()
{
	bool latest=0;
	string file_name=global_institute+"_books.txt";
	string a,b,c,d,e,A,B,C,D,E;
	ifstream outer_file(file_name.c_str());
	while (outer_file >> a >> b >> c >> d >> e)
	{
		if(d=="borrowed")
		{
			ifstream inner_file(file_name.c_str());
			while (inner_file >> A >> B >> C >> D >> E)
			{
				if (A==a && B==b && c==C)
				{
					latest=0;
					if(D=="returned")
					{
						latest=1;
					}
				}
			}
			if(latest==1)
			{
				cout << A << " is now returned " << endl;
			}
		}
	}
}

void all_students()
{
	string stored_name , stored_type , stored_password;
	string file_name=global_institute+"_details.txt";
	ifstream login_data(file_name.c_str());
	while(login_data >> stored_name >> stored_password >> stored_type)
	{
		if (stored_type=="std")
			cout << stored_name << endl;
	}
}

void all_fresh_books()
{
	bool latest=1;
	string file_name=global_institute+"_books.txt";
	string a,b,c,d,e,A,B,C,D,E;
	cout << "BOOK\tAuthor\tID\n";
	ifstream outer_file(file_name.c_str());
	while (outer_file >> a >> b >> c >> d >> e)
	{
		if(d=="available")
		{
			ifstream inner_file(file_name.c_str());
			while (inner_file >> A >> B >> C >> D >> E)
			{
				latest=1;
				if (A==a && B==b && c==C && d!=D)
				{
					latest=0;
					break;
				}
			}
			inner_file.close();
			if(latest)
			{
				cout << a  << "\t" << b << "\t" << c << endl;
			}
		}
	}
}