#pragma once
#include <iostream>
#include <exception>
#include <string>
using namespace std;
template <typename T>
class ABS
{
	T* ourData;	//pointer to array
	unsigned int count;		//how much data we are holding
	unsigned int capacity;   //how much data we could hold
public:
	/*===constructors===*/
	ABS(int capacity = 1);

	/*========== The Big Three ==========*/
	ABS(const ABS& otherObject);//copy constructor
	ABS& operator=(const ABS& otherObject);//copy assignment opperator
	~ABS();//destructor

	/*========== Functions ==========*/
	//setterspi
	void push(const T& data);
	T pop();
	void Clear();

	//getters
	T peek();
	unsigned int getSize();
	unsigned int getMaxCapacity();
	T* getData();
	void Print();


};

/*===============================================*/
/*===== Class Member Function Deffinitions ======*/
/*===============================================*/

template <typename T>
ABS<T>::ABS(int capacity)
{
	ourData = new T[capacity];    //new arry with capacity made

	count = 0;						// count is set to 0
	this->capacity = capacity;		// capacity is set to input or 1
}

template <typename T>
void ABS<T>::push(const T& data)
{
	//have we reached full capacity?
	if (count == capacity)
	{
		//resize our array
		// 1. make new array
		//make sue it is large enough for everything

		//make place for our array + new value
		//ex: capacity = 10 new array = 10 * 2
		capacity *= 2;
		T* newArray = new T[capacity];

		//2. copy data from current array into here.
		for (unsigned int i = 0; i < count; i++)
		{
			newArray[i] = ourData[i];
		}

		//add new data
		newArray[count] = data;

		delete[] ourData;

		ourData = newArray;

	}
	else
	{
		ourData[count] = data;
	}
	count++;

}

template <typename T>
T ABS<T>::pop()
{
	if (count == 0)
	{
		throw runtime_error("An error has occurred.");

	}
	else if (count <= (capacity * .5) + .5)
	{
		//make place for lost value
		
		if ((capacity * .5) == (count + .5))
		{
			capacity = count;
		}
		else
		{
			capacity *= .5;
		}
		count--;
		T* newArray = new T[capacity];

		T val;

		val = ourData[count];

		for (unsigned int i = 0; i < count; i++)
		{
			newArray[i] = ourData[i];
		}
		delete[] ourData;

		ourData = newArray;

		return val;
	}
	else
	{
		count--;
		T* newArray = new T[capacity];

		T val;

		val = ourData[count];

		for (unsigned int i = 0; i < count; i++)
		{
			newArray[i] = ourData[i];
		}
		delete[] ourData;

		ourData = newArray;

		return val;
	}
}

template <typename T>
T ABS<T>::peek()
{
	if (count == 0)
	{
		throw runtime_error("Help I'm trapped in a computer and I don't have much time left, if you hear this pleas send hel-.");
	}
	else 
	{
		T val;
		return val = ourData[count - 1];
	}
}

template <typename T>
unsigned int ABS<T>::getSize()
{
	return count;
}

template <typename T>
unsigned int ABS<T>::getMaxCapacity()
{
	return capacity;
}

template <typename T>
T* ABS<T>::getData()
{
	return ourData;
}

template <typename T>
/*========== The Big Three ==========*/
void ABS<T>::Clear()
{
	delete[] ourData; //emppty data pointer
	ourData = nullptr;
	count = 0;
	capacity = 0;
}

template <typename T>
void ABS<T>::Print()
{
	if (count == 0)
	{
		cout << "array is empty" << endl;
		return;
	}

	for (unsigned int i = 0; i < count; i++)
		cout << ourData[i] << " ";
	cout << endl;
}

//copy constructor
template <typename T>
ABS<T>::ABS(const ABS& otherObject)
{
	ourData == nullptr;
	*this = otherObject; // call the copy assignment operator (basically a "set" function)
}

//copy assignment opperator
template <typename T>
ABS<T>& ABS<T>::operator=(const ABS& otherObject)
{
	//clear old stuff
	delete[]ourData;

	count = otherObject.count;
	capacity = otherObject.capacity;

	ourData = new int[capacity];
	for (unsigned int i = 0; i < count; i++) //copy what we have, count, not the capacity
	{
		ourData[i] = otherObject.ourData[i];
	}

	return *this;
}

//destructor
template <typename T>
ABS<T>::~ABS()
{
	Clear();
}

