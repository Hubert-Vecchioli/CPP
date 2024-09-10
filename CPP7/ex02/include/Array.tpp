/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:09:44 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/10 15:12:35 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ARRAY_TPP
# define ARRAY_TPP


# include "Array.hpp"

template<typename T>
Array<T>::Array(void):array_(NULL), size_(0)
{
}

template<typename T>
Array<T>::Array(unsigned int n):array_(new T[n]), size_(n)
{
}

template<typename T>
Array<T>::Array(Array const &rhs)
{
	*this = rhs;
}

template<typename T>
Array<T>::~Array(void)
{
	delete[] array_;
}

template<typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
	if (this != &rhs)
	{
		T *newarray_ = new T[rhs.size_];
		for (unsigned int i = 0; i < rhs.size_; i++)
			newarray_[i] = rhs.array_[i];
		delete[] this->array_;
		this->array_ = newarray_;
		this->size_ = rhs.size_;
	}
	return (*this);
}

template<typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= size_)
		throw Array<T>::OutOfBoundsException();
	return (array_[i]);
}

template<typename T>
unsigned int Array<T>::size(void) const 
{
	return (this->size_);
}

template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return ("Error: Index is out of bounds");
}

#endif