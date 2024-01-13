#include <filesystem>
#include <iostream>
#include <fstream>
#include <string>

class inputHandler
{
private:
    /* data */
    const std::string m_inputPath;
    std::string m_total_inputFilePath;

public:
    inputHandler() = default;
    inputHandler(const std::string &path) : m_inputPath(path)
    {

        m_total_inputFilePath = std::string(SOURCE_DIR) + m_inputPath;
        std::ifstream fileHandle(m_total_inputFilePath);
        if (!fileHandle.is_open())
        {
            std::cerr << "Failed to open file: " << m_total_inputFilePath << std::endl;
        }
    };

    ~inputHandler() = default;
    void readFile()
    {
        std::ifstream fileHandle(m_total_inputFilePath);
        std::string line;
        while (std::getline(fileHandle, line))
        {
            // Process each line here
            std::cout << line << std::endl;
        }
        fileHandle.close();
    }
};
