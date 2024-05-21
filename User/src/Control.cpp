#include "Control.h"
#include "objectManager.h"
#include "StringProcess.h"

CModel Controller::model;

void Controller::getListExpense()
{
	ObjectManager::lst_expense.clear(); 
	model.getlistExpense(ObjectManager::lst_expense,ObjectManager::_user);
	StringProcess::Sort(ObjectManager::lst_expense);
}

void Controller::search(std::string dateFr, std::string dateTo, std::string key)
{
	std::vector<std::shared_ptr<expense>> tmp; 
	for (auto& x : ObjectManager::lst_expense)
	{
		if (StringProcess::existSubStr(x->category, key) != -1 || StringProcess::existSubStr(x->subcategory, key) != -1)
		{
			if (StringProcess::compareDates(dateFr, x->date) == -1 && StringProcess::compareDates(dateTo, x->date) == 1)
				tmp.push_back(std::move(x)); 
		}
	}
	ObjectManager::lst_expense.clear(); 
	ObjectManager::lst_expense = tmp; 
}

void Controller::getUser(std::string username, std::string password, std::string& msg)
{
	ObjectManager::_user.password = password;
	ObjectManager::_user.username = username;
	user tmp = ObjectManager::_user;
	if (!model.getUser("username", tmp))
	{
		msg = "User not exist!"; 
		return; 
	}
	if (!model.getUser("password", ObjectManager::_user))
	{
		msg = "Invalid password!";
		return;
	}
}

void Controller::add(std::shared_ptr<object> obj, std::string& msg)
{
	bool res = model.add(obj,msg);
	if (obj->type == EXPENSE && res)
		getListExpense(); 
	else
	{
		std::string msg = "";
		//Controller::getUser(username, password, msg);
	}
}

void Controller::update(std::shared_ptr<object> obj, std::string& msg)
{
	if (obj->type == USER) 
	{ 
		user _user = *obj->as<user>();
		if (!model.getUser("username", _user))
		{
			msg = "User not exist!";
			return;
		}
	}
	bool res = model.update(obj, msg);
	if (obj->type == EXPENSE && res)
		getListExpense();
}

void Controller::del(std::shared_ptr<object> obj)
{
	bool res = model.del(*obj);
	if (obj->type == EXPENSE && res)
		getListExpense();
}
