#pragma once
#include <vector>
#include <map>
#include <memory>
#include "object.h"

// Class: ObjectManager
// Description: [this is class to cache data].
class ObjectManager
{
public:
	ObjectManager() {};
	~ObjectManager() {};

public:
	static std::map<std::string, std::vector<std::string>> lst_category; 
	static std::vector<std::shared_ptr<expense>> lst_expense; 
	static user _user; 

	static void init();

};