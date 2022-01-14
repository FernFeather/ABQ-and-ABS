#pragma once
#pragma once
#include <iostream>
#include <exception>
#include <string>
using namespace std;
template <typename T>
class ABQ
{
	T* ourData;	//pointer to array
	unsigned int count;		//how much data we are holding
	unsigned int capacity;   //how much data we could hold
public:
	/*===constructors===*/
	ABQ(int capacity = 1);

	/*========== The Big Three ==========*/
	ABQ(const ABQ& otherObject);//copy constructor
	ABQ& operator=(const ABQ& otherObject);//copy assignment opperator
	~ABQ();//destructor

	/*========== Functions ==========*/
	//setterspi
	void enqueue(const T& data);
	T dequeue();
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
ABQ<T>::ABQ(int capacity)
{
	ourData = new T[capacity];    //new arry with capacity made

	count = 0;						// count is set to 0
	this->capacity = capacity;		// capacity is set to input or 1
}

template <typename T>
void ABQ<T>::enqueue(const T& data)
{
	//have we reached full capacity?
	if (count == capacity)
	{
		//resize our array
		// 1. make new array
		//make sure it is large enough for everything

		capacity *= 2;
		T* newArray = new T[capacity];

		//2. copy new data into here.
		newArray[0] = data;

		//3. copy data from current array into here.
		for (unsigned int i = 0; i < count; i++)
		{
			newArray[i + 1] = ourData[i];
		}

		delete[] ourData;

		ourData = newArray;

	}
	else
	{
		//move our array
		// 1. shift new array

		T* newArray = new T[capacity];

		//2. copy data from current array into here.
		newArray[0] = data;
		for (unsigned int i = 0; i < count; i++)
		{
			newArray[i + 1] = ourData[i];
		}

		delete[] ourData;

		ourData = newArray;
	}
	count++;

}

template <typename T>
T ABQ<T>::dequeue()
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
		
		T* newArray = new T[capacity];

		count--;

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
T ABQ<T>::peek()
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
unsigned int ABQ<T>::getSize()
{
	return count;
}

template <typename T>
unsigned int ABQ<T>::getMaxCapacity()
{
	return capacity;
}

template <typename T>
T* ABQ<T>::getData()
{
	return ourData;
}

template <typename T>
/*========== The Big Three ==========*/
void ABQ<T>::Clear()
{
	delete[] ourData; //emppty data pointer
	ourData = nullptr;
	count = 0;
	capacity = 0;
}

template <typename T>
void ABQ<T>::Print()
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
ABQ<T>::ABQ(const ABQ& otherObject)
{
	ourData == nullptr;
	*this = otherObject; // call the copy assignment operator (basically a "set" function)
}

//copy assignment opperator
template <typename T>
ABQ<T>& ABQ<T>::operator=(const ABQ& otherObject)
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
ABQ<T>::~ABQ()
{
	Clear();
}

