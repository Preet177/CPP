#include "FileReplacer.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2)
    : filename(filename), s1(s1), s2(s2) 
{
}

std::string FileReplacer::readFile() 
{
    std::ifstream ifs(filename);
    if (!ifs) 
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << ifs.rdbuf();
    return buffer.str();
}

std::string FileReplacer::replaceAll(const std::string& content, const std::string& s1, const std::string& s2) 
{
    std::string result = content;
    size_t pos = 0;
    while ((pos = result.find(s1, pos)) != std::string::npos) 
    {
        result.replace(pos, s1.length(), s2);
        pos += s2.length();
    }
    return result;
}

bool FileReplacer::writeFile(const std::string& content) 
{
    std::ofstream ofs(filename + ".replace");
    if (!ofs) 
    {
        std::cerr << "Error creating file: " << filename + ".replace" << std::endl;
        return false;
    }
    ofs << content;
    return true;
}

bool FileReplacer::replace() 
{
    std::string content = readFile();
    if (content.empty()) 
    {
        return false;
    }
    std::string newContent = replaceAll(content, s1, s2);
    return writeFile(newContent);
}
