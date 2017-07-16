

#include "dynamic_array_list.h"

#include <algorithm>
#include <stdexcept>

#include <iostream>
#include <ostream>
//using namespace std;

//Defult constructor
template <typename T>
DynamicArrayList<T>::DynamicArrayList() :stackTop(0), maxStackSize(100)
{
	alist = new T[maxStackSize];
}

//Copy Consructor
template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& x)
{
	alist = nullptr; //set list to null
	copy(x); //calls the function
}

template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
	delete[] alist; //Deletes the list
}

//Copy assignment
template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(DynamicArrayList<T> x)
{
	if (this != &x)
	{
		copy(x);
	}
	return *this;
}

//checks to see if the dynamic array is empty
template <typename T>
bool DynamicArrayList<T>::isEmpty()
{
	bool check = false; //default variable
	if (stackTop < 1) //Indicates a stack is empty //Change from == to 0
	{
		check = true;
	}
	return check;
}

template <typename T>
std::size_t DynamicArrayList<T>::getLength()
{
	//cout << stackTop;
	return stackTop; //returns the current length
}

template <typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{
	stackTop++;
	if (stackTop == maxStackSize) //determines whether to double the size or not
	{
		T* curr = alist; //creates an array list
		alist = new T[maxStackSize * 2]; //doubles the size of the temporary array list
		for (int i = 0; i < maxStackSize; i++)
		{
			alist[i] = curr[i]; //iterates through the list and add the items to the temporary list
		}
		delete[] curr; //deletes the temporary list
		maxStackSize = maxStackSize * 2; //dpubles the size
	}
	if (position >= 0 && position <= stackTop)
	{
		for (int index = stackTop; index > position; index--)
		{
			alist[index] = alist[index - 1]; //shifts the position of the remaining items in the list
		}
		alist[position] = item;
	}

}

//Removes an item from he list
template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
	//In order to prevent wholes in the list, I am shifiting the position of the entries following towards the beginning
	if (position >= 0 && position <= stackTop)
	{
		for (int p = position; p < stackTop; p++)
		{
			alist[p] = alist[p + 1];
		}
		stackTop--; //decrements the size of the array
	}
	else
	{
		throw std::range_error("Hold Up Wait A Minute, your out of range homie! Try Again.");
	}
}

//Clears the list
template <typename T>
void DynamicArrayList<T>::clear()
{
	stackTop = 0;
}

//gets an entry at a specific location
template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position)
{
	if (position > stackTop)
	{
		throw std::range_error("Hold Up Wait A Minute, your out of range homie! Try Again.");
	}
	else
	{
		return alist[position];
	}
}

//sets the entry
template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
	if (position > stackTop)
	{
		throw std::range_error("Hold Up Wait A Minute, your out of range homie! Try Again.");
	}
	else
	{
		alist[position] = newValue;
	}
}

//creates a copy of the stack and uses the stack that is being copied as a parameter
template<typename T>
void DynamicArrayList<T>::copy(const DynamicArrayList<T>& other)
{
	//delete[] alist; //free memory
	maxStackSize = other.maxStackSize; //sets the variables
	stackTop = other.stackTop;//creates a new list
	alist = new T[maxStackSize]; //copies the list
	for (int j = 0; j < stackTop; j++) //adds the items to the list
	{
		alist[j] = other.alist[j];
	}
}


