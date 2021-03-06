#pragma once

//#include <iostream> 
#include <list> 
#include <iterator> 
#include "item.h"
#include "Doc.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define NUM 10

class listOfProduct
{
public:

	listOfProduct();
	~listOfProduct();
	void resst();
	void removeItem(int _id);
	void add(int _id);
	bool saveMyList();
	int* loadMyList();

private:
	int itemArr[NUM];
};



