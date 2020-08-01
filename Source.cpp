#include<bits/stdc++.h>
#include<conio.h>
using namespace std;


//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

class Book
{
	int bookNo;
	string bookName;
	string authorName;

	public:
		void createBook()
		{
			cout<<"\nNEW BOOK REGISTRATION\n";
			cout<<"\nEnter the book no. : ";
			cin>>bookNo;
			cout<<"\nEnter the Book Name : ";
			cin>>bookName;
			cout<<"\nEnter the author's name : ";
			cin>>authorName;
			cout<<"\n\n Book is successfully registered.";
		}

		void showBook()
		{
			cout<<"\nBook no. : "<<bookNo;
			cout<<"\nBook Name : "<<bookName;
			cout<<"\nAuthor's Name : "<<authorName;
		}

		void modifyBook()
		{
			cout<<"\n Book no. : "<<bookNo;
			cout<<"\n Moodify Book Name : ";
			cin>>bookName;
			cout<<"\n Modify Author's Name : ";
			cin>>authorName;
		}

		int returnBookNo()
		{
			return bookNo;
		}

		void report()
		{
			cout<<bookNo<<setw(30)<<bookName<<setw(30)<<authorName<<"\n";
		}

};


//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

class Student
{
	int admissionNo;
	string name;
	char studentBookNo[6];
	int token;

	public:

		void createStudent()
		{
			system("clear");
			cout<<"\nNEW STUDENT REGISTRATION\n";
			cout<<"\nEnter student admission no. : ";
			cin>>admissionNo;
			cout<<"\nEnter student name : ";
			cin>>name;
			token = 0;
			studentBookNo[0]='/0';
			cout<<"\n\nStudent successfully registered";
			
		}

		void showStudent()
		{
			cout<<"\nAdmission no. : "<<admissionNo;
			cout<<"\nStudent name : ";
			cout<<name;
			cout<<"\nNo of book issued : "<<token;
			if(token == 1)
			{
				cout<<"\nBook no. : "<<studentBookNo;
			}
		}

		void modifyStudent()
		{
			cout<<"\nAdmission no. : "<<admissionNo;
			cout<<"\nModify Student name : ";
			cin>>name; 
		}

		int returnAdmissionNo()
		{
			return admissionNo;
		}

		char* returnStudentBookNo()
		{
			return studentBookNo;
		}

		int returnToken()
		{
			return token;
		}

		void addToken()
		{
			token=1;
		}

		void resetToken()
		{
			token = 0;
		}

		void getStudentBookNo(char sbn[])
		{
			strcpy(studentBookNo,sbn);
		}

		void report()
		{
			cout<<"\t"<<admissionNo<<setw(20)<<name<<setw(20)<<token<<"\n";
		}
	
};

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

fstream fp,fp1;
Book b;
Student s;

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

void writeBook()
{
	char c;
	fp.open("book.dat",ios::out|ios::app);
	do
	{
		system("clear");
		b.createBook();
		fp.write((char*)&b,sizeof(Book));
		cout<<"\n\nDo you want to add more record ..(y/n)";
		cin>>c;
	}while(c=='y' || c=='Y');
	fp.close();
}


void writeStudent()
{
	char c;
	fp.open("student.dat",ios::out|ios::app);
	do
	{
		system("clear");
		s.createStudent();
		fp.write((char*)&s,sizeof(Student));
		cout<<"\n\nDo you want to add more record ..(y/n)";
		cin>>c;
	}while(c=='y' || c=='Y');
	fp.close();
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

void displaySpecificStudent(int n)
{
	cout<<"\n\nSTUDENT DETAILS\n";
	int flag=0;
	fp.open("student.dat,ios::in");
	while(fp.read((char*)&s,sizeof(Student)))
	{
		if(s.returnAdmissionNo()==n)
		{
			s.showStudent();
			flag = 1;
		}
	}

	fp.close();
	if(flag==0)
	{
		cout<<"\n\nStudent doesn't Exist";
	}
	getch();
	getch();
}

void displaySpecificBook(int n)
{
	cout<<"\n\nBOOK DETAILS\n";
	int flag=0;
	fp.open("book.dat,ios::in");
	while(fp.read((char*)&b,sizeof(Book)))
	{
		if(b.returnBookNo()==n)
		{
			b.showBook();
			flag = 1;
		}
	}

	fp.close();
	if(flag==0)
	{
		cout<<"\n\nBook doesn't Exist";
	}
	getch();
	getch();
}


//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

void modifyBook()
{
	int n;
	int found=0;
	system("clear");
	cout<<"\n\n\t MODIFY BOOK RECORD";
	cout<<"\n\nEnter the book no. : ";
	cin>>n;

	fp.open("book.dat",ios::in|ios::out);
	while(fp.read((char*)&b,sizeof(Book)))
	{
		if(b.returnBookNo()==n)
		{
			b.showBook();
			cout<<"\nEnter the new details of book\n";
			b.modifyBook();
			int pos =-1*sizeof(b);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&b,sizeof(Book));
			cout<<"\n\n\t Record Updated";
			found = 1;
		}
	}

	fp.close();
	if(found==0)
	{
		cout<<"\n\nRecord not found";
	}

	getch();
	getch();


}

void modifyStudent()
{
	int n;
	int found=0;
	system("clear");
	cout<<"\n\n\t MODIFY STUDENT RECORD";
	cout<<"\n\nEnter the admission  no. of the student : ";
	cin>>n;

	fp.open("student.dat",ios::in|ios::out);
	while(fp.read((char*)&s,sizeof(Student)))
	{
		if(s.returnAdmissionNo()==n)
		{
			s.showStudent();
			cout<<"\nEnter the new details of the student\n";
			s.modifyStudent();
			int pos =-1*sizeof(s);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&s,sizeof(Student));
			cout<<"\n\n\t Record Updated";
			found = 1;
		}
	}

	fp.close();
	if(found==0)
	{
		cout<<"\n\nRecord not found";
	}

	getch();


}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

void deleteStudent()
{
	cout<<"\n\ndeleteStudent\n";
}

void deleteBook()
{
	cout<<"\n\n delete Book\n";
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

void displayAllStudent()
{
	cout<<"\n\ndisplayAllStudent\n";
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------


void displayAllBooks()
{
	cout<<"\n\n display all books\n";
}


//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

void bookIssue()
{
	cout<<"\n\nbook issue\n\n";
	getch();

}


//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

void bookDeposit()
{
	cout<<"\nbook deposit\n\n";
	getch();

}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

void adminMenu()
{
	system("clear");
	int ch;
	cout<<"\n\n\n\t\tADMINISTARTIVE MENU";
	cout<<"\n\n\t1. CREATE STUDENT RECORD";
	cout<<"\n\t2. DISPLAY ALL STUDENT RECORD";
	cout<<"\n\t3. DISPLAY SPECIFIC STUDENT RECORD";
	cout<<"\n\t4. MODIFY STUDENT RECORD";
	cout<<"\n\t5. DELETE STUDENT RECORD";
	cout<<"\n\t6. CREATE BOOK";
	cout<<"\n\t7. DISPLAY ALL BOOKS";
	cout<<"\n\t8. DISPLAY SPECIFIC BOOK";
	cout<<"\n\t9. MODIFY BOOK";
	cout<<"\n\t10. DELETE BOOK";
	cout<<"\n\t11. BACK TO MAIN MENU";
	cout<<"\n\n\n\t. Please Enter your choice";
	cin>>ch;
	int num;
	switch(ch)
	{
		case 1 : 
			system("clear");
			writeStudent();
			break;
		case 2 :
			displayAllStudent();
			break;
		case 3 : 
			system("clear");
			cout<<"\n\n\t Enter the admission no. :";
			cin>>num;
			displaySpecificStudent(num);
			break;
		case 4 :
			modifyStudent();
			break;
		case 5 :
			deleteStudent();
			break;
		case 6 : 
			system("clear");
			writeBook();
			break;
		case 7 :
			displayAllBooks();
			break;
		case 8 : 
			system("clear");
			cout<<"\n\n\tEnter the book no. : ";
			cin>>num;
			displaySpecificBook(num);
			break;
		case 9 :
			modifyBook();
			break;
		case 10 :
			deleteBook();
			break;
		case 11 : 
			return ;
		default : 
			cout<<"\a";
			break;

	}
	adminMenu();
}


//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

void introduction()
{
	system("clear");
	cout<<"\t\tLIBRARY MANAGEMENT SYSYTEM\n\n";
	cout<<"\t\t----AIT PUNE\n";
	getch();
}

//-------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------

int main()
{

	int choice;
	introduction();
	do
	{
		system("clear");
		cout<<"\n\n\t\t\tMAIN MENU";
		cout<<"\n\t\t1. BOOK ISSUE";
		cout<<"\n\t\t2. BOOK DEPOSIT";
		cout<<"\n\t\t3. ADMINISTARTIVE MENU";
		cout<<"\n\t\t4. EXIT";
		cout<<"\n\n Please select your choice\n";
		cin>>choice;
		switch(choice)
		{
			case 1 :
			{
				system("clear");
				bookIssue();
				break;
			}
			case 2 : 
				bookDeposit();
				break;
			case 3 : 
				adminMenu();
				break;
			case 4 : 
				return 0;
				break;
			default :
				cout<<"\a";
				break;
		} 
	}while(choice!=4);
	return 0;
}
