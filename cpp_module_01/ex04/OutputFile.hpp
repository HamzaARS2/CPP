#ifndef OUTPUT_FILE_HPP
# define OUTPUT_FILE_HPP

#include <iostream>
#include <fstream>

typedef std::string String;
typedef std::ofstream OutputStream;

class OutputFile {
	private:
		OutputStream	stream;
		String          filename;

	public:
        OutputFile(String filename);
		~OutputFile();
		void    writeLine(String data);
};


#endif
