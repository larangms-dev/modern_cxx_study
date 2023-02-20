#pragma once
#include <algorithm>

#include "using_types.h"

template<typename T>
class Array2D
{
public:
	class Iterator
	{
	public:
		explicit Iterator(T* p)
			:p{ p }
		{
		}

		Iterator& operator++()
		{
			++p; return *this;
		}
		Iterator operator++(int)
		{
			Iterator temp = *this;
			++p;
			return temp;
		}
		T& operator*()
		{
			return *p;
		}
		bool operator==(const Iterator& other) const
		{
			return p == other.p;
		}
		bool operator!=(const Iterator& other) const
		{
			return p != other.p;
		}
	private:
		T* p;
	};
public:
	Array2D(UINT32 x, UINT32 y);
	Array2D(Array2D&& other);
	~Array2D();
public:
	Array2D& operator=(Array2D&& other);
public:
	T& at(UINT32 x, UINT32 y) const;
	T* const data();
	void fill(const T& data);
	void swap(Array2D& other);
public:
	UINT32 column();
	UINT32 row();
public:
	Iterator begin()
	{
		return Iterator(arr);
	}
	Iterator end()
	{
		return Iterator(arr + columns * rows);
	}
private:
	UINT32 columns;
	UINT32 rows;
	T* arr;
};

template<typename T>
inline Array2D<T>::Array2D(UINT32 column, UINT32 row)
	: columns{ column }, rows{ row }, arr{ nullptr }
{
	arr = new T[columns * rows];
}

template<typename T>
inline Array2D<T>::Array2D(Array2D&& other)
{
	arr = other.arr;
	columns = other.columns;
	rows = other.rows;
}

template<typename T>
inline Array2D<T>::~Array2D()
{
	delete[] arr;
	arr = nullptr;
}

template<typename T>
inline Array2D<T>& Array2D<T>::operator=(Array2D<T>&& other)
{
	arr = other.arr;
	columns = other.columns;
	rows = other.rows;
	return *this;
}

template<typename T>
inline T& Array2D<T>::at(UINT32 column, UINT32 row) const
{
	return arr[row * columns + column];
}

template<typename T>
inline T* const Array2D<T>::data()
{
	return arr;
}

template<typename T>
inline void Array2D<T>::fill(const T& data)
{
	std::fill(&arr[0], &arr[rows * columns], data);
}

template<typename T>
inline void Array2D<T>::swap(Array2D& other)
{
	T* temp_arr = other.arr;
	UINT32 temp_columns = other.columns;
	UINT32 temp_rows = other.rows;
	other.arr = arr;
	other.columns = columns;
	other.rows = rows;
	arr = temp_arr;
	columns = temp_columns;
	rows = temp_rows;
}

template<typename T>
inline UINT32 Array2D<T>::column()
{
	return columns;
}

template<typename T>
inline UINT32 Array2D<T>::row()
{
	return rows;
}