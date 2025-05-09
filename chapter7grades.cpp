/*
File Name: chapter7grades
Programmer: Blake Jewell
Date: 05/25
Requirements: Write a program that gathers 5 student's names and 4 
of their test scores in arrays. Then, the program should average out 
their scores and assign them a letter grade from a seperate array.
*/

using namespace std;

#include <iostream>
#include <string>

string getnames();
double getgrades();
char getscore(double[],int);
void displayresults(double [],int, char[],string []);
int choose();

const int numofstudents = 5;
const int numofgrades = 4;

int main()
{
	int choice;
	do {
		double averages[numofstudents] = { 0, 0, 0, 0, 0 };
		char score[numofstudents];
		string namesarray[numofstudents];
		double grades[numofstudents][numofgrades];
		for (int count = 0; count < numofstudents;count++)
		{
			cout << "please enter the name of student #" << count + 1 << endl;
			namesarray[count] = getnames();
			for (int index = 0;index < numofgrades;index++)
			{
				cout << "Please enter score #" << index + 1 << endl;
				grades[count][index] = getgrades();
				averages[count] += grades[count][index];
			}
			averages[count] = averages[count] / numofgrades;
		}
		for (int count = 0; count < numofstudents; count++)
		{
			score[count] = getscore(averages, count);
		}
		displayresults(averages, numofstudents, score, namesarray);
		choice = choose();
	} while (choice == 1);
}
string getnames()
{
	string name;
	cin >> name;
	return name;
}
double getgrades()
{
	double grade;
	cin >> grade;
	while (grade < 0 || grade>100)
	{
		cout << "Unacceptable entry. Please enter a number between 1 and 100." << endl;
		cin >> grade;
	}
	return grade;
}
char getscore(double averages[], int num)
{
	char score = 'E';
	if (averages[num] > 90)
	{
		score = 'A';
	}
	else if (averages[num] > 80)
	{
		score = 'B';
	}
	else if (averages[num] >70)
	{
		score = 'C';
	}
	else if (averages[num] >60)
	{
		score = 'D';
	}
	else
	{
		score = 'F';
	}
	return score;
}
void displayresults(double averages[],int students,char grades[],string names[])
{
	cout << "Average Score / Letter Grade / Name" << endl;
	cout << "******************************************" << endl;
	for (int count = 0; count < students;count++)
	{
		cout << averages[count] <<"\t"<< grades[count] << "\t" << names[count] << endl;
	}
}
int choose()
{
	int choice;
	cout << "Would you like to run the program again? ENTER 1 for yes or 2 for no." << endl;
	cin >> choice;
	while (choice < 1 || choice >2)
	{
		cout << "Invalid selection. please select either 1 or 2." << endl;
		cin >> choice;
	}
	return choice;
}