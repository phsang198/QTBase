#pragma once
#include <string>



enum OBJECT_TYPE
{
	USER,
	EXPENSE
};
// Class: object
// Description: [Define project objects].

class object
{
public:
	object() {};
	object(OBJECT_TYPE, int);
	~object() {};
	virtual void dummy() {};
	template<class T>
	T* as()
	{
		return dynamic_cast<T*>(this); 
	}
public:
	OBJECT_TYPE type;
	std::string id;
private:

};
// Class: user
// Description: [Define user].
class user : public object
{
public:
	user() {};
	user(std::string, std::string, std::string, std::string, int = 0);
	~user() {};
public:
	std::string username;
	std::string password;
	std::string fullname;
	std::string position;
	int id;

private:

};
// Class: expense
// Description: [Define expense].
class expense : public object
{
public:
	expense() {};
	expense(int,std::string, std::string, std::string, double, double, int = 0);
	~expense() {};
public:
	std::string date;						// format 'YYYY-MM-DD'
	std::string category;
	std::string subcategory;
	double amount;
	double balance;
	int id; 
	int userID;
private:

};
