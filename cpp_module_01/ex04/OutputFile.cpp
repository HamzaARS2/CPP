#include "OutputFile.hpp"



OutputFile::OutputFile(String filename): filename(filename) {
    this->stream.open(this->filename);
}

OutputFile::~OutputFile() {
    this->stream.close();
}

void    OutputFile::writeLine(String data) {
    this->stream << data << std::endl;
}