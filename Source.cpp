#include<bits/stdc++.h>
using namespace std;

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

class Student
{
	int admissionNo;
	string name;
	int studentBookNo;
	int token;

	public:

		void createStudent()
		{
			system("clear");
			cout<<"\nNEW STUDENT REGISTRATION\n";
			cout<<"\nEnter student admission no. : ";
			cin>>admissionNo;
			
		}
	
};

int main()
{
	return 0;
}
