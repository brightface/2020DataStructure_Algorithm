#include <iostream>
using namespace std;

struct Data
{
	int value1 = 0;
	int value2 = 0;
};

void Function(Data* data)
{
	data = new Data();
	data->value1 = 10;
	data->value2 = 20;
}

int main()
{
	Data* data = nullptr;
	Function(data);
	cout << data->value1 << endl;

	return 0;
}