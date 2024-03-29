// Map-Test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <map>
#include <string>
#include <iostream>

int main()
{
	using namespace std;
	std::map<int, std::string> color_map;
	color_map.insert(std::pair<int, std::string>(0, "R"));
	color_map.insert(std::pair<int, std::string>(1, "G"));
	color_map.insert(std::pair<int, std::string>(2, "B"));
	color_map.insert(std::pair<int, std::string>(3, "W"));
	std::string color_param = "TGBW";
	color_map[0] = color_param[0];
	color_map[1] = color_param[1];
	color_map[2] = color_param[2];
	color_map[3] = color_param[3];
	cout << color_map[0] << endl;

    return 0;
}

