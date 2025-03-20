#ifndef FILE_MANAGER_HPP
# define FILE_MANAGER_HPP

#include "InputFile.hpp"
#include "OutputFile.hpp"

typedef std::string String;

class IOFileManager {
	private:
		InputFile&   inFile;

		String		replaceLine(String original, String toReplace, String toAdd);
	public:
        IOFileManager(InputFile& inFile);
		~IOFileManager();
		
        OutputFile*  replaceFileData(String s1, String s2);
};


#endif
