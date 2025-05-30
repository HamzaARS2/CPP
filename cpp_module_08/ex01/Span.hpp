#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <cmath>
#include <limits.h>
typedef std::string String;

class Span {
	private:
		size_t N;
		std::vector<int> vect;

	public:
		class SpanFullException: public std::exception {
			public:
				const char*	what() const throw();
		};
		class NoSpanFoundException: public std::exception {
			public:
				const char*	what() const throw();
		};

		Span();
		Span(size_t N);
		Span(const Span& copy);

		Span&	operator=(const Span& other);

		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();

		template <typename I>
		void	addRange(I begin, I end) {
			size_t spaceLeft = N - vect.size();
			size_t elemToAdd = std::distance(begin, end);
	
			if (elemToAdd > spaceLeft)
				end = begin + spaceLeft;
			vect.insert(vect.end(), begin, end);
		}
		void	printAll() const;

		~Span();
};


#endif