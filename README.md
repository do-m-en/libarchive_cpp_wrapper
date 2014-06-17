libarchive cpp wrapper library
============================
This is a C++ wrapper arround libarchive library.

Dependencies
============================
- libarchive (https://github.com/libarchive/libarchive)
- CMake (http://cmake.org/)

Current version was tested with gcc 4.9 on 64 bit Linux - Ubuntu 14.04

Example usage
============================

```C++
#include "archive_reader.hpp"

namespace ar = ns_archive::ns_reader;
std::fstream fs( "some_tar_file.tar" );
ns_archive::reader reader = ns_archive::reader::make_reader<ar::format::_ALL, ar::filter::_ALL>(fs, 1024);

for(auto entry : reader)
{
  // get file name
  std::cout << entry->get_header_value<ns_archive::ns_reader::entry::string_value::PATHNAME>() << std::endl;
  // get file content
  std::cout << entry->get_entry_content_stream().rdbuf() << std::endl << std::endl;
}
```

License
============================
BSD 2-Clause license (http://opensource.org/licenses/bsd-license.php)
