#include <sstream>

#include "StringUtility.h"



using namespace std;

namespace Util
{
	// divide string with delimeter and save into int vector
	vector<int> DivideStringToVectorInt(std::string strList, char delimeter)
	{
		vector<int> vecVal;

		stringstream in(strList);
		string temp;

		while(std::getline(in, temp, delimeter))
		{
			int nVal = atoi(temp.c_str());
			vecVal.push_back(nVal);
		}

		return vecVal;
	}

	// divide string with delimeter and save into float vector
	vector<float> DivideStringToVectorFloat(std::string strList, char delimeter)
	{
		vector<float> vecVal;

		stringstream in(strList);
		string temp;

		while (std::getline(in, temp, delimeter))
		{
			float fVal = atof(temp.c_str());
			vecVal.push_back(fVal);
		}

		return vecVal;
	}
};