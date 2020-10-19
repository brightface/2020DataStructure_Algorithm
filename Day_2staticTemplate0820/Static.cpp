#include "Static.h"

extern int global;
int Static::value4 = 0;
Static::Static()
{
	global = 10;
	value4++;
}

Static::~Static()
{
	value4--;
}

void Static::Function()
{
	/*static int a;

	value2 = 10;
	Function2();*/
}

void Static::Function2()
{
	//value4 = 10;
	//Function();
}
