#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <fstream>
#include <string>
#include "phoneOrg.h"

using namespace std;

//phoneRec methods
void phoneRec::setName(const char* nm) //set name
{
	strcpy(name, nm);
}
const char* phoneRec::getName() const // get name
{
	return name;
}
void phoneRec::setNickName(const char* nn) //set nickname
{
	strcpy(nickName, nn);
}
const char* phoneRec::getNickName() const //get nickname
{
	return nickName;
}
void phoneRec::setEmail(const char* em) //set email
{
	strcpy(emailAddr, em);
}
const char* phoneRec::getEmail() const//get email
{
	return emailAddr;
}
void phoneRec::setPhoneNo(int phn) //set phone number
{
	phoneNo = phn;
}
int phoneRec::getPhoneNo() const//get phone number
{
	return phoneNo;
}
void phoneRec::setLastCall(int dt) //set last call datetime
{
	lastCall = dt;
}
int phoneRec::getLastCall() const //get last call datetime
{
	return lastCall;
}

//phoneBk methods
phoneBk::phoneBk()
{
	ne[0] = ne[1] = ne[2] = 0;
}
void phoneBk::input()
{
	phoneRec person;
	char pName[80], pNickName[25], pEmail[30], add;
	int pPhoneNo, pLastCall, grp;
	bool nexistFam = true, nexistFd = true, nexistJ = true;
	bool existed[3] = { 0 };
	ofstream fout("contacts", ios::app);
	cin.get();

	cout << "\nPlease enter the name: ";
	cin.getline(pName, 80);
	person.setName(pName);

	cout << "Please enter the nickname: ";
	cin.getline(pNickName, 25);
	person.setNickName(pNickName);

	cout << "Please enter the email address: ";
	cin.getline(pEmail, 30);
	person.setEmail(pEmail);

	cout << "Please enter the phone number: ";
	cin >> pPhoneNo;
	person.setPhoneNo(pPhoneNo);

	cout << "Please enter the last-call date-time: ";
	cin >> pLastCall;
	person.setLastCall(pLastCall);
	do {
		cout << "\nPlease choose a group (1: Family, 2: Friend, 3: Junk - can be under more than 1 group) or enter 0 to end: ";
		cin >> grp;

		switch (grp)
		{
		case 1:
			if (nexistFam == true)
			{
				addGrp(0, person);
				nexistFam = false;
				cout << "Added to Family\n";
			}
			else
				cout << "already exists";
			break;
		case 2:
			if (nexistFd == true)
			{
				addGrp(1, person);
				nexistFd = false;
				cout << "Added to Friend\n";
			}
			else
				cout << "already exists";
			break;
		case 3:
			if (nexistJ == true)
			{
				addGrp(2, person);
				nexistJ = false;
				cout << "Added to Junk\n";
			}
			else
				cout << "already exists";
			break;
		case 0:
			break;
		default:
			cout << "No such group.\n"; break;
		}
		if (grp == 0)
			break;
	} while (nexistFam || nexistFd || nexistJ);
	fout << '#' << endl;
	if (nexistFam == false)
		fout << "Family.";
	else
		fout << "N.";

	if (nexistFd == false)
		fout << "Friend.";
	else
		fout << "N.";

	if (nexistJ == false)
		fout << "Junk" << endl;
	else
		fout << "N" << endl;

	fout << person.getName() << endl;
	fout << person.getNickName() << endl;
	fout << person.getEmail() << endl;
	fout << person.getPhoneNo() << endl;
	fout << person.getLastCall() << endl;
}
void phoneBk::addGrp(int grp, phoneRec person)
{
	if (ne[grp] < 100)
		group[grp][ne[grp]++] = person;
}
void phoneBk::sortNickName(int grp) //sort phone records based on nicknames
{
	phoneRec temp;
	bool sorted;
	do
	{
		sorted = false;
		for (int i = 1; i < ne[grp]; i++)
			if (strcmp(group[grp][i].getNickName(), group[grp][i - 1].getNickName()) > 0)
			{
				temp = group[grp][i - 1];
				group[grp][i - 1] = group[grp][i];
				group[grp][i] = temp;
				sorted = true;

			}
	} while (sorted);

	cout << "\n¡X Sorted list based on the nickname ¡X\n\n";
	for (int i = 0; i < ne[grp]; i++)
		cout << "Nickname: " << group[grp][i].getNickName() << "  Phone Number: " << group[grp][i].getPhoneNo() << endl;
}
void phoneBk::display(int grp, int i) const
{
	if (i < ne[grp])
	{
		cout << endl;
		cout << "Name: " << group[grp][i].getName() << endl;
		cout << "Nickname: " << group[grp][i].getNickName() << endl;
		cout << "Email Address: " << group[grp][i].getEmail() << endl;
		cout << "Phone Number: " << group[grp][i].getPhoneNo() << endl;
		cout << "Last-call Date-time: " << group[grp][i].getLastCall() << endl;
	}
	else
		cout << "No such entry!\n";
}
void phoneBk::display(int grp) const
{
	for (int i = 0; i < ne[grp]; i++)
		display(grp, i);
}
bool phoneBk::login()
{
	char fusername[25], fpassword[25], ch;
	bool exist = false, existp = false, loggedIn = false;
	int i;
	ifstream file("userinfo");
	cout << "Username: ";
	cin.getline(username, 25);
	while (file)
	{
		i = 0;
		file.get(ch);
		while (ch != '\n')
		{
			fusername[i] = ch;
			file.get(ch);
			i++;
		}
		fusername[i] = '\0';
		if (strcmp(fusername, username) == 0)
		{
			exist = true;
			i = 0;
			file.get(ch);
			while (ch != '\n')
			{
				fpassword[i] = ch;
				file.get(ch);
				i++;
			}
			fpassword[i] = '\0';

			for (int i = 0; i < 3; i++)
			{
				cout << "Password (3 attempts only): ";
				cin.getline(password, 25);
				if (strcmp(fpassword, password) == 0)
				{
					existp = true;
					loggedIn = true;
					break;
				}
				else
					cout << "Incorrect password.\n\n";
			}
		}
		if (existp == true)
			break;
	}
	file.close();
	if (exist == false)
	{
		char npassword[25];
		ofstream fout("userinfo", ios::app);
		fout << username << endl;
		cout << "New password: ";
		cin.getline(npassword, 25);
		fout << npassword << endl;
		fout.close();
		cout << "New user info saved.\nPlease log in again to access the phone book.\n";
		existp = true;
	}
	if (existp == false)
	{
		cout << "Sorry, failed attempt limit reached.";
	}
	return loggedIn;
}
void phoneBk::read()
{
	char fam[10], fd[10], j[10], line[100];
	int phn, dt;
	char sUser[100], ch, c;
	ifstream file("contacts");
	phoneRec user;
	int i;

	while (file)
	{

		file.get(ch);
		if (ch == '#')
		{
			file.get(ch);

			i = 0;
			file.get(ch);
			while (ch != '.')
			{
				fam[i] = ch;
				file.get(ch);
				i++;
			}
			fam[i] = '\0';

			i = 0;
			file.get(ch);
			while (ch != '.')
			{
				fd[i] = ch;
				file.get(ch);
				i++;
			}
			fd[i] = '\0';

			/*getline(file, j);*/
			i = 0;
			file.get(ch);
			while (ch != '\n')
			{
				j[i] = ch;
				file.get(ch);
				i++;
			}
			j[i] = '\0';

			i = 0;
			file.get(ch);
			while (ch != '\n')
			{
				sUser[i] = ch;
				file.get(ch);
				i++;
			}
			sUser[i] = '\0';
			user.setName(sUser);

			i = 0;
			file.get(ch);
			while (ch != '\n')
			{
				sUser[i] = ch;
				file.get(ch);
				i++;
			}
			sUser[i] = '\0';
			user.setNickName(sUser);

			i = 0;
			file.get(ch);
			while (ch != '\n')
			{
				sUser[i] = ch;
				file.get(ch);
				i++;
			}
			sUser[i] = '\0';
			user.setEmail(sUser);

			/*getline(file, line);*/
			i = 0;
			file.get(ch);
			while (ch != '\n')
			{
				line[i] = ch;
				file.get(ch);
				i++;
			}
			line[i] = '\0';
			phn = atoi(line);
			user.setPhoneNo(phn);

			/*getline(file, line);*/
			i = 0;
			file.get(ch);
			while (ch != '\n')
			{
				line[i] = ch;
				file.get(ch);
				i++;
			}
			line[i] = '\0';
			dt = atoi(line);
			user.setLastCall(dt);

			if (strcmp(fam, "Family") == 0)
				addGrp(0, user);
			if (strcmp(fd, "Friend") == 0)
				addGrp(1, user);
			if (strcmp(j, "Junk") == 0)
				addGrp(2, user);
		}
	}
	file.close();
}