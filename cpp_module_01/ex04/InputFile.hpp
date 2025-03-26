#ifndef INPUT_FILE_HPP
# define INPUT_FILE_HPP

#include <iostream>
#include <fstream>

typedef std::string String;
typedef std::ifstream InputStream;

class InputFile {
	private:
		InputStream	stream;
		String		filename;
		String		line;

	public:
        InputFile(String filename);
		~InputFile();
		bool readline();
		String	getLine();
		String	getFilename();
};


#endif
