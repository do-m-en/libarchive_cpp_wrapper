#include "archive_exception.hpp"

namespace ns_archive {

archive_exception::archive_exception(const std::string& what) :
  _what(what)
{
  //
}

const char* archive_exception::what()
{
  return _what.c_str();
}

}
