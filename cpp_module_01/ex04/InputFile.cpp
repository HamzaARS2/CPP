#include "InputFile.hpp"

InputFile::InputFile(String filename): filename(filename) {
    this->stream.open(filename);
    if (!this->stream.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        std::exit(1);
    }
}

InputFile::~InputFile() {
    if (this->stream.is_open())
        this->stream.close();
}

bool  InputFile::readline() {
    if (!this->stream.is_open())
        return false;
    if (!std::getline(this->stream, this->line))
        return false;
    return true;
}

String  InputFile::getLine() {
    return this->line;
}

String  InputFile::getFilename() {
    return this->filename;
}