#include "objectManager.h"
#include "StringProcess.h"
#include <json.hpp>

using json = nlohmann::json;

std::map<std::string, std::vector<std::string>> ObjectManager::lst_category;
std::vector<std::shared_ptr<expense>> ObjectManager::lst_expense;
user ObjectManager::_user;

void ObjectManager::init()
{
	std::string content = "";
	std::string path = StringProcess::getExePath() + "Res/config/category.conf";
	if (!StringProcess::readFileConfig(path, content))
	{
		return ;
	}
	json json = json::parse(content); 
	if (json.empty()) return; 

	for (auto x : json)
	{
		std::vector<std::string> tmp;
		if (x.find("subcategory") != x.end())
		{
			for (auto y : x["subcategory"])
			{
				tmp.push_back(y); 
			}
		}
		lst_category[x["category"]] = tmp;

	}
}