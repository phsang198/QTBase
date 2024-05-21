#pragma once
#include "Model.h"

// Class: Controller
// Description: [Controlling getting and setting data from Model to View and View to Model].

class Controller
{
public:
	Controller() {};
	~Controller() {};

public:
	static CModel model;
public:
	static void getListExpense(); 
	static void search(std::string, std::string, std::string); 
	static void getUser(std::string , std::string, std::string& );
	static void add(std::shared_ptr<object>, std::string& );
	static void update(std::shared_ptr<object>, std::string&);
	static void del(std::shared_ptr<object>);
};
