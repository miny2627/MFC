#include "StdAfx.h"
#include "Calculator.h"


Calculator::Calculator(void)
{
}


Calculator::~Calculator(void)
{
}


int Calculator::Add(int a, int b)
{
	return a+b;
}


int Calculator::Subtract(int a, int b)
{
	return a-b;
}


int Calculator::Multiply(int a, int b)
{
	return a*b;
}


double Calculator::Divide(int a, int b)
{
	return (double)a/(double)b;
}
