#include <iostream>
#include <string>
#include <functional>

#ifndef SORTINFO_H
#define SORTINFO_H

template <typename T>
class SortInfo{
public:
	/*
	/@pre none.
	/@post Makes a sortinfo object and initializes it.
	/@return none.
	*/
	SortInfo(std::function<void(T[], T)> sort, std::string name);

	/*
	/@pre Sortinfo object.
	/@post none.
	/@returns the function of the sort.
	*/
	std::function<void(T[], int)> getSort() const;

	/*
	/@pre sortinfo object.
	/@post none.
	/@returns the Name of the sort.
	*/
	std::string getName() const;

	/*
	/@pre sortinfo object.
	/@post none.
	/@returns the time that the last sort took to complete.
	*/
	double getTime() const;

	/*
	/@pre sortinfo object
	/@post stores a double in m_time
	/@return none
	*/
	void setTime(double t);

	/*
	/@pre sortinfo object
	/@post none.
	/@return the number of items sorted in the last run.
	*/
	int getCount() const;

	/*
	/@pre sortinfo object
	/@post stores the size of the array sorted last as m_count.
	/@return none.
	*/
	void setCount(int count);

private:
	std::function<void(T[], T)> m_sort;
	std::string m_name;
	double m_time;
	int m_count;

};


#include "SortInfo.hpp"

#endif
