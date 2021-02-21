#pragma once

#include <vector>
#include <string>

#include <stdio.h>

#define __FILENAME__	(strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define FILE_LOG(fmt, ...)	{printf("[%s:%d / %s] "fmt"\n", __FILENAME__, __LINE__, __FUNCTION__, ##__VA_ARGS__);} 

#define FUNC_LOG(fmt, ...)	{printf("[%s] "fmt"\n", __FUNCTION__, ##__VA_ARGS__);} 

namespace Util
{
	/** divide string with delimeter and save into int vector **/
	std::vector<int> DivideStringToVectorInt(std::string, char delimeter);

	std::vector<float> DivideStringToVectorFloat(std::string strList, char delimeter);
};
