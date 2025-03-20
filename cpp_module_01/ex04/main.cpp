#include "IOFileManager.hpp"

int	main(int ac, char *av[]) {
	if (ac < 4) return 1;

	InputFile inputFile = InputFile(av[1]);
	IOFileManager fileManager = IOFileManager(inputFile);

	OutputFile* outFile = fileManager.replaceFileData(av[2], av[3]);
	delete outFile;
}