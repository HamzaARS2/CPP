#ifndef FILE_HPP
# define FILE_HPP

#include <iostream>
#include <fstream>

typedef std::string String;
typedef std::fstream FileStream;

class File {
	private:
		FileStream	stream;
		String		filename;

	public:
		File(String filename, int openMode);
		~File();
		


};


#endif
