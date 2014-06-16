#ifndef ARCHIVE_EXCEPTION_HPP_INCLUDED
#define ARCHIVE_EXCEPTION_HPP_INCLUDED

#include <exception>
#include <string>

namespace ns_archive {

class archive_exception : public std::exception
{
public:
  archive_exception(const std::string& what);

  const char* what();

private:
  std::string _what;
};

}

#endif // ARCHIVE_EXCEPTION_HPP_INCLUDED
