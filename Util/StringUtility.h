#pragma once

#include <vector>
#include <string>

namespace Util
{
	/** divide string with delimeter and save into int vector **/
	std::vector<int> DivideStringToVectorInt(std::string, char delimeter);

	std::vector<float> DivideStringToVectorFloat(std::string strList, char delimeter);
};