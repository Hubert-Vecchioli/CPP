/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:21:30 by hvecchio          #+#    #+#             */
/*   Updated: 2024/09/10 17:03:27 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : n_(0) {}

Span::Span(unsigned int n) : n_(n) {}

Span::Span(Span const &src) : n_(src.n_), v_(src.v_) {}

Span::~Span(void) {}

Span &Span::operator=(Span const &src)
{
	if (this != &src)
	{
		this->n_ = src.n_;
		this->v_ = src.v_;
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (this->v_.size() >= this->n_)
		throw Span::ReachedMaxSizeException();
	this->v_.push_back(n);
}

void Span::addRange(std::vector<int>vector_to_add)
{
	std::vector<int>::iterator v_begin = vector_to_add.begin();
	std::vector<int>::iterator v_end = vector_to_add.end();

	if (this->v_.size() + std::distance(v_begin, v_end) > this->n_)
		throw Span::ReachedMaxSizeException();
	this->v_.insert(this->v_.end(), v_begin, v_end);
}

int	Span::shortestSpan(void)
{
	int					span;
	std::vector<int>	tmp;

	if (this->v_.size() < 2)
	{
		throw Span::MissingSpanException();
		return (0);
	}
	tmp = this->v_;
	std::sort(tmp.begin(), tmp.end());
	span = tmp[1] - tmp[0];
	for (size_t i = 1; i < tmp.size(); i++)
	{
		if (tmp[i] - tmp[i - 1] < span)
			span = tmp[i] - tmp[i - 1];
	}
	return (span);
}

int	Span::longestSpan(void)
{
	if (this->v_.size() < 2)
	{
		throw Span::MissingSpanException();
		return (0);
	}
	return (*std::max_element(this->v_.begin(), this->v_.end()) - *std::min_element(this->v_.begin(), this->v_.end()));
}

// Exceptions
const char* Span::MissingSpanException::what() const throw()
{
	return ("Error: Span is empty or has only a single element.");
}

const char* Span::ReachedMaxSizeException::what() const throw()
{
	return ("Error: We reached the already reached the max size.");
}