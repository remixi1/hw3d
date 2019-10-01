#include "HwException.h"
#include<sstream>


HwException::HwException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{
}


const char* HwException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* HwException::GetType() const noexcept
{
	return "Hardware Exeption";
}
int HwException::GetLine() const noexcept
{
	return line;
}
const std::string& HwException::GetFile() const noexcept
{
	return file;
}
std::string HwException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[file]" << file << std::endl
		<< "[line]" << line;
	return oss.str();

}