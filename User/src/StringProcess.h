#pragma once
#include <string>
#include <regex>

#include <sstream>
#include <iomanip>
#include <iostream>
#include <cstring>
#include <fstream>
#include <ctype.h>
#include <codecvt>
#include <algorithm>
#include <vector>
#include <Windows.h>
#include <chrono>

#define RUN_PROJECT "User.exe"
// Class: StringProcess
// Description: [To be used to support for orther function].

class StringProcess
{
public:
	//static std::string cs2String(CString cstr)
	//{
	//	CT2CA pszConvertedAnsiString(cstr);
	//	return std::string(pszConvertedAnsiString);
	//}
	template <class T> 
	static bool compare(const std::shared_ptr<T>& e1, const std::shared_ptr<T>& e2) {
		if (e1->date != e2->date) {
			return compareDates2(e1->date, e2->date);
		}
		else if (e1->category != e2->category)
		{
			return e1->category < e2->category;
		}
		else {
			return e1->subcategory < e2->subcategory;
		}
	}
	template <class T> 
	static void Sort( std::vector<std::shared_ptr<T>>& arr)
	{
		std::sort(arr.begin(), arr.end(), compare<T>);
	}
	static int compareDates2(const std::string& date1, const std::string& date2) {
		std::tm tm1 = {};
		std::tm tm2 = {};

		std::istringstream iss1(date1);
		std::istringstream iss2(date2);

		iss1 >> std::get_time(&tm1, "%Y-%m-%d");
		iss2 >> std::get_time(&tm2, "%Y-%m-%d");

		auto time_point1 = std::chrono::system_clock::from_time_t(std::mktime(&tm1));
		auto time_point2 = std::chrono::system_clock::from_time_t(std::mktime(&tm2));

		if (time_point1 <= time_point2)
			return 1;
		else
			return 0;
	}
	static int compareDates(const std::string& date1, const std::string& date2) {
		std::tm tm1 = {};
		std::tm tm2 = {};

		std::istringstream iss1(date1);
		std::istringstream iss2(date2);

		iss1 >> std::get_time(&tm1, "%Y-%m-%d");
		iss2 >> std::get_time(&tm2, "%Y-%m-%d");

		auto time_point1 = std::chrono::system_clock::from_time_t(std::mktime(&tm1));
		auto time_point2 = std::chrono::system_clock::from_time_t(std::mktime(&tm2));

		if (time_point1 < time_point2)
			return -1;
		else if (time_point1 > time_point2)
			return 1;
		else
			return 0;
	}
	static bool readFileConfig(std::string path, std::string& content)
	{
		std::ifstream f;
		f.open(path, std::ios::in);
		std::string tmp;
		if (f.fail())
		{
			return FALSE;
		}
		while (std::getline(f, tmp)) {
			content += (tmp + '\n');
		}
		f.close();
		return TRUE;
	}
	static std::string getExePath()
	{
		char curPath[FILENAME_MAX];
		GetModuleFileNameA(NULL, curPath, sizeof(curPath));
		std::string szCurDir(curPath);

		size_t found = szCurDir.find(RUN_PROJECT);
		szCurDir.erase(found, szCurDir.length() - 1);
		return szCurDir;
	}

	static std::string ws2string(std::wstring ws)
	{
		std::string s(ws.begin(), ws.end());
		return s;
	}

	static bool ReplaceRegex(std::string& str, const std::string& from, const std::string& to) {
		try
		{
			str = std::regex_replace(str, std::regex(from), to);
			return true;
		}
		catch (const std::exception&)
		{
			return false; 
		}
	}
	static bool ReplaceAll(std::string& str, const std::string& from, const std::string& to) {
		size_t start_pos = str.find(from);
		while (start_pos != std::string::npos)
		{
			str.replace(start_pos, from.length(), to);
			start_pos = str.find(from);
		}
		
		return true;
	}

	static bool Exist(std::string& str, const std::string& key) {
		size_t start_pos = str.find(key);
		if (start_pos == std::string::npos)
			return false;
		return true;
	}

	static bool Replace(std::string& str, const std::string& from, const std::string& to) {
		size_t start_pos = str.find(from);
		if (start_pos == std::string::npos)
			return false;
		//str.erase(start_pos, from.length()); 
		//str.insert(start_pos, to); 
		std::string _to = to; 
		if (_to == "") _to = "";
		str.replace(start_pos, from.length(), _to);
		return true;
	}
	static int ConstCharToInt(const char* value)
	{
		std::stringstream strValue;
		strValue << value;
		int intValue;
		strValue >> intValue;
		return intValue;
	}
	static double cs2double(const char* value)
	{
		return std::atof(value);
	}
	static std::vector<std::string> parseURLToArray(std::string str, const char c)
	{
		std::vector<std::string> result;
		//Find string
		int firstIndex = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == c)
			{
				std::string subStr = str.substr(firstIndex, i - firstIndex);
				result.push_back(subStr);
				firstIndex = i + 1;
			}
			if (i == str.size() - 1)
			{
				std::string subStr = str.substr(firstIndex, i - firstIndex + 1);
				result.push_back(subStr);
			}
		}
		return result;
	}
	static std::vector<int> parseStrToInt(std::string str)
	{
		const char c = ','; 
		std::vector<int> result; 
		std::vector<std::string> strs = parseURLToArray(str, c);
		for (int i = 0; i < strs.size(); ++i)
		{
			result.push_back(std::stoi(strs.at(i))); 
		}
		return result; 
	}
	static std::string getExtensionFile(std::string filename)
	{
		int position = static_cast<int>(filename.find_last_of("."));
		return filename.substr(position + 1);
	}
	static std::string getNameFile(std::string path, char k )
	{
		int position = static_cast<int>(path.find_last_of(k));
		return path.substr(position + 1);
	}
	static std::string getPathExceptNameFile(std::string path)
	{
		int position = static_cast<int>(path.find_last_of('/'));

		std::string filename = path.substr(position);
		path.erase(position, filename.length()); 
		return path; 
	}
	static int existSubStr(std::string str, std::string substr)
	{
		size_t position = str.find(substr);
		if (position != std::string::npos)
			return static_cast<int>(position);
		else
			return -1;
	}
	static std::string to_string_with_precision(double a_value, const int n = 15)
	{
		std::ostringstream out;
		out.precision(n);
		out << std::fixed << a_value;
		return out.str();
	}
private:
	StringProcess();
};
