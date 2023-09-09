// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <iostream>



Array::Array (void)
{
	//default array constructor, no parameters or instantialization specified
	//intentionally left blank
}

Array::Array (size_t length)
{
	//allocate and initialize an array, and define length
	cur_size_ = length;
	array = new char[length];
}

Array::Array (size_t length, char fill)
{
	//for every index in the array, fill each element with the provided fill characters 
	//initialize cur_size_ to equal size_t length
	cur_size_ = length;
	array = new char[length];

	for (size_t i=0; i<length; i++) {
		array[i] = fill;
	}
	
}


Array::Array (const Array & array)
{
	//create a new array of the same size as the current array
	array = new char[array.cur_size_];

	//for every element in the current array, copy it to the  new array
	for (size_t i = 0; i < array.cur_size_; i++) {
		this-> - array[i] = array.array[i];
	}
	//update the current size
	this->cur_size_ = array.cur_size_;
}

Array::~Array (void)
{
	// standard array destructor from class
	// 
	//one delete[] for each new[] called
	delete[] array;

	//set to null to ensure no dangling pointers
	array = nullptr;

}

const Array & Array::operator = (const Array & rhs)
{
	//self assignment check
	if (this == &rhs) {
		return *this;
	}
	array = new char[rhs.cur_size_];

	for (size_t i = 0; i < rhs.cur_size_; i++) {
		array[i] = rhs.array[i];
	}
	//update cur size again
	cur_size_ = rhs.cur_size_;

	//return self reference
	return *this;
}


//....
//....done
char & Array::operator [] (size_t index)
{
	try
	{
		//if the index is valid, get the character at the current index
		if (index >= 0 && index < cur_size_ - 1) {
			char characterAtIndex = Array[index];
			return characterAtIndex;
		}
		else {
			//if the index is not valid, throw exception
			throw std::out_of_range("index/element out of range");
		}
	}
	catch (const std::out_of_range& ex)
	{
		static char defChar = '\0';
		cout << "Defined index is out of range, index has been set as the max size of the array" << endl;
		return defChar;
	}

}


//....
//....done
const char & Array::operator [] (size_t index) const

{
	try
	{
		if (index >= 0 && index < cur_size_) {
			return Array[index];
		}
		else {
			throw std::out_of_range("element out of range");
		}
	}
	catch (const std::out_of_range& ex)
	{
		cout << "Defined index is out of range, index has been set as the max size of the array" << endl;
		return '\0';
	}
}
//....
//....done
char Array::get (size_t index) const

{
	try
	{
		if (index >= 0 && index < cur_size_ ) {

			return Array[index];
		}
		else {
			throw std::out_of_range("invalid index/element out of range");
		}
	}
	catch (const std::out_of_range& ex)
	{
		cout << "Defined index is out of range, index has been set as the max size of the array" << endl;
		return '\0';
	}
}
//
//....done
void Array::set (size_t index, char value)
{
	try
	{
		if (index >= 0 && index < cur_size_ - 1) {
			Array[index] = value;
		}
		else {
			throw std::out_of_range("element out of range");
		}
	}
	catch (const std::out_of_range& ex)
	{
		cout << "Defined index is out of range, index has been set as the max size of the array" <<endl;
	}
}
//
//....done
void Array::resize (size_t new_size)
{
	//if new size is less than current size, copy excess elements into a new array
	//and set the current size of the original array to the new size
	if (new_size < cur_size_ ) {
		char* new_array = new char[new_size];

		for (size_t i = 0; i < new_size; i++) {
			new_array[i] = array[i];
		}
		delete[] array

		array = new_array;
		//current size is updated to new size
		cur_size_ = new_size;

	}
	//if new size is larger than current size, extend the size of the current array
	//the original contents are copied into a new array, and then the original array is set to the new size
	else if(new_size > cur_size_ ){
		char* new_array = new char[new_size];

		for (size_t i = 0; i < cur_size_; i++) {
			new_array[i] = array[i];
		}
		delete[] array;

		array = new_array;
		//current size is updated to new size
		cur_size_ = new_size;
	}
}
//
//....done
int Array::find (char ch) const
{
		for (int i = 0; i < cur_size_; i++) {
			char characterAtIndex = array[i];

			if (characterAtIndex == ch) {
				return i;
			}
		
		}
		return -1;
}
//
//....done
int Array::find (char ch, size_t start) const
{
	try {
		if (start >= cur_size_) {
			throw std::out_of_range("Start index is not in array");
		}

		for (int i = 0; i < start; i++) {
			char characterAtIndex = array[i];

			if (characterAtIndex == ch) {
				return i;
			}
		}
		return -1;
	}
	catch(const std::out_of_range& ex){

		cout << (" Requested Start Index is not in array.") << endl;
		return -1;

	}
}
//
//....done
bool Array::operator == (const Array & rhs) const
{
	if (cur_size_ != rhs.cur_size_) {
		return false;
	}
	for (size_t i = 0; i < cur_size_; i++) {
		if (array[i] != rhs.array[i]) {
			return false;
		}
	}
	return true;
}
//
//....done
bool Array::operator != (const Array & rhs) const
{
	if (cur_size_ != rhs.cur_size_) {
		return true;
	}
	for (size_t i = 0; i < cur_size_; i++) {
		if (array[i] != rhs.array[i]) {
			return true;
		}
	}
	return false;
}
//
//...done
void Array::fill (char ch)
{
	for (size_t i = 0; i < cur_size_; i++) {
		array[i] = ch;
	}
}
//
//....done
void Array::shrink (void)
{
	if (cur_size_ == max_size_) {
		return;
	}
	char* new_array = new char[cur_size_];

	for (size_t i = 0; i < cur_size_; i++) {
		new_array[i] = array[i];
	}
	delete[] array;
	array = new_array;
	max_size_ = cur_size_;
}
//
//....done
void Array::reverse (void)
{
	size_t middle = cur_size_ / 2;

	for (size_t i = 0; i < middle; i++) {
		char temp = array[i];
		array[i] = array[cur_size_ - 1 - i];
		array[cur_size_ - 1 - i] = temp;
	}
}
//
//....done
Array Array::slice (size_t begin) const
{
	if (begin >= cur_size_) {
		return Array();
	}
	size_t new_size = cur_size_ - begin;
	char* new_array = new char[new_size];

	for (size_t i = begin; i < new_size; i++) {
		new_array[i- begin] = array[i];
	}
	cur_size_ = new_size;
	return Array(new_array, new_size);
	
}
//
//....done
Array Array::slice (size_t begin, size_t end) const
{
	if (begin >=cur_size_ || end > cur_size_|| end < begin) {
		return Array();
	}
	
	size_t new_size = ((end - begin)+1);
	char* new_array = new char[new_size];

	for (size_t i = begin; i < new_size; i++) {
		new_array[i - begin] = array[i];
	}
	return Array(new_array, new_size);
}
