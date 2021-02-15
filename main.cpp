#include "csv/csv.h"

#include <iostream>

using namespace std;

int main()
{

	io::CSVReader<1> in("Quest_Node_Info.csv");
	in.read_header(io::ignore_extra_column, "Q_ID");
	int QN_ID; 
	//float* vecNodeList; 
	while (in.read_row(QN_ID))
	{ 
		cout << QN_ID << ","  << "\n";
		// do stuff with the data 
	} 

	system("pause");

	return 0;
}