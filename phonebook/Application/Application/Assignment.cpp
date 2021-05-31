#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <string>
#include "phoneOrg.h"
using namespace std;

void menu(phoneBk* pp);
int main()
{
	phoneBk* user = new phoneBk;
	if (user->login() == true) {
		user->read();
		menu(user);
	}
	return 0;
}

void menu(phoneBk* pp)
{
	int choice, group;
	do
	{
		cout << "¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X\n";
		cout << "MENU\n";
		cout << "1. Phone record input\n";
		cout << "2. Display phone records info under a group (Family, Friend, or Junk)\n";
		cout << "3. Display a sorted list of phone records based on the nickname (Family, Friend, or Junk)\n";
		cout << "4. Quit\n";
		cout << "¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X\n";
		cout << "Please enter your choice (1, 2, 3, or 4):\n";
		cin >> choice;
		switch (choice)
		{
		case 1: 
			pp->input();
			break;
		case 2:
			do {
				//add to group from file
				cout << "\nDisplay phone records under:\n";
				cout << "1. Family\n";
				cout << "2. Friend\n";
				cout << "3. Junk\n";
				cout << "Please choose a group (1, 2, or 3) or enter 0 to end:\n";
				cin >> group;
				switch (group)
				{
					case 0:
						break;
					case 1:
						cout << "\n¡X FAMILY ¡X\n";
						pp->display(0);
						break;
					case 2:
						cout << "\n¡X FRIEND ¡X\n";
						pp->display(1);
						break;
					case 3:
						cout << "\n¡X JUNK ¡X\n";
						pp->display(2);
						break;
					default:
						cout << "No such group.\n"; break;
				}
			} while (group != 0);
			break;
		case 3:
			do {
				cout << "\nDisplay a sorted list of phone records based on the nickname under:\n";
				cout << "1. Family\n";
				cout << "2. Friend\n";
				cout << "3. Junk\n";
				cout << "Please choose a group (1, 2, or 3) or enter 0 to end:\n";
				cin >> group;
				switch (group)
				{
				case 0:
					break;
				case 1:
					cout << "\n¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X FAMILY ¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X\n";
					pp->sortNickName(0);
					cout << "¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X\n";
					break;
				case 2:
					cout << "\n¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X FRIEND ¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X\n";
					pp->sortNickName(1);
					cout << "¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X\n";
					break;
				case 3:
					cout << "\n¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X JUNK ¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X\n";
					pp->sortNickName(2);
					cout << "¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X¡X\n";
					break;
				default:
					cout << "No such group.\n"; break;
				}
			} while (group != 0);
			break;
		case 4:
			break;
		default:
			cout << "Invalid Input\nPlease enter again:\n"; break;
		}
	} while (choice != 4);
}
