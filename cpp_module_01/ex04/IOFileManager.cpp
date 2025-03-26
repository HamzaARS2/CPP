#include "IOFileManager.hpp"


IOFileManager::IOFileManager(InputFile& inFile)
    : inFile(inFile) {}

String  IOFileManager::replaceLine(String original, String toReplace, String toAdd) {
    String newStr;
    std::size_t pos = original.find(toReplace);

    while (pos != String::npos) {
        std::size_t lastPos = pos + toReplace.size();
        newStr.append(original.substr(0, pos));
        newStr.append(toAdd);
        original = original.substr(lastPos);
        pos = original.find(toReplace);
    }
    newStr.append(original);
    return newStr;
}

OutputFile*  IOFileManager::replaceFileData(String s1, String s2) {
    String outputName = this->inFile.getFilename().append(".replace");
    OutputFile* outFile = new OutputFile(outputName);
    while(this->inFile.readline()) {
        String line = this->inFile.getLine();
        String newLine = this->replaceLine(line, s1, s2);
        outFile->writeLine(newLine);
    }
    return outFile;
}