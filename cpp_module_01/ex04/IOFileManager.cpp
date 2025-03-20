#include "IOFileManager.hpp"


IOFileManager::IOFileManager(InputFile& inFile)
    : inFile(inFile) {}

IOFileManager::~IOFileManager() {
    
}

String  IOFileManager::replaceLine(String original, String toReplace, String toAdd) {
    std::size_t pos = original.find(toReplace);
    std::size_t lastPos = pos + toReplace.size();

    String newStr = original.substr(0, pos);
    newStr.append(toAdd).append(original.substr(lastPos));

    return newStr;
}

OutputFile*  IOFileManager::replaceFileData(String s1, String s2) {
    OutputFile* outFile = new OutputFile("output.txt");
    while(this->inFile.readline()) {
        String line = this->inFile.getLine();
        String newLine = this->replaceLine(line, s1, s2);
        outFile->writeLine(newLine);
    }
    return outFile;
}