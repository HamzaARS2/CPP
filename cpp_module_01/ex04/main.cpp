





// int	main(int ac, char *av[]) {
// 	if (ac < 4)
// 		return 1;
	
// }

#include <iostream>
#include <fstream>
typedef std::string String;
typedef std::ifstream InputStream;
typedef std::ofstream OutputStream;
typedef std::fstream FileStream;

void replace() {
	String str = "hello world hi ";
	String toReplace = "world";
	String word = "klock";

	size_t pos = str.find(toReplace);
	size_t lastPos   = pos + toReplace.size();
	String newStr = str.substr(0, pos);
	newStr.append(word).append(str.substr(lastPos));
	std::cout << "<" << newStr << ">"<< std::endl;
	
}

int	main() {
	replace();
	std::ios::in;
	// FileStream inFile;
	// inFile.open(filename, std::ios::in);
	// if (inFile.is_open()) {
	// 	String line;
	// 	while (std::getline(inFile, line)) {
	// 		std::cout << line << std::endl;
	// 	}
	// 	inFile.close();
	// }

}