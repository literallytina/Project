class phoneRec
{
public:
	void setName(const char* nm); //set name
	const char* getName() const; // get name
	void setNickName(const char* nn); //set nickname
	const char* getNickName() const; //get nickname
	void setEmail(const char* em); //set email
	const char* getEmail() const; //get email
	void setPhoneNo(int phn); //set phone number
	int getPhoneNo() const; //get phone number
	void setLastCall(int dt); //set last call datetime
	int getLastCall() const; //get last call datetime

private:
	char name[80], nickName[25], emailAddr[30]; // store the contact info
	int phoneNo, lastCall;
};

class phoneBk
{
public:
	phoneBk(); // constructor of phoneBk
	void input(); // ask for user input and store the info into phoneRec and the file
	void addGrp(int grp, phoneRec person); // add one phoneRec object under a group
	void display(int grp, int i) const; //display one object under one specific group
	void display(int grp) const; //display objects under one specific group
	void sortNickName(int grp);//sorted list of phone records based on the nicknames
	bool login(); //verify user login
	void read(); //read content from the file and store them into the array of a group
private:
	phoneRec group[3][100];	//group[0] == Family, group[1] == Friend, group[2] == Junk, max 100 records
	int ne[3];				//numbers of valid elements
	char username[25], password[25]; //store input of username and password
};