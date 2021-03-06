#include "pch.h"
#include "listOfProduct.h"

using namespace std;

listOfProduct::listOfProduct()
{
	//load?
}

listOfProduct::~listOfProduct()
{
	resst();//see if need..
}


void listOfProduct::resst()
{
	for (int i = 0; i < NUM; i++)
	{
		itemArr[i] = 0;
	}
}

void listOfProduct::removeItem(int _id)
{
	itemArr[_id - 1] = 0;//??rem all**
}

void listOfProduct::add(int _id)
{

	itemArr[_id - 1] ++;

}

bool listOfProduct::saveMyList()
{
	ofstream myfile("myList.txt");
	if (myfile.is_open())
	{
		for (int i = 0; i < NUM; i++)
		{
			myfile << itemArr[i] << " ";
		}

		myfile.close();
	}
	else return false;
		return true;
}

int* listOfProduct::loadMyList()
{
	resst();
	int tempint;
	ifstream myfile("myList.txt");

	if (myfile.is_open())
	{
		for (int i = 0; i < NUM; i++)
		{
			myfile >> itemArr[i];
			
		}
		myfile.close();
		
	}else {
	//no open
	}
	return itemArr;
}
