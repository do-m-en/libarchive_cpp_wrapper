/*
BSD 2-Clause license

Copyright (c) 2014, Domen Vrankar
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef ARCHIVE_READER_ENTRY_HPP_INCLUDED
#define ARCHIVE_READER_ENTRY_HPP_INCLUDED

#include <string>
#include <istream>
#include "archive_entry.h"
#include "archive_reader_entry_buffer.hpp"

namespace ns_archive {
namespace ns_reader {

class entry
{
public:
  enum class string_value
  {
    HARDLINK,
    PATHNAME,
    SOURCEPATH,
    SYMLINK
  };
public:
  entry(archive* archive, archive_entry* entry);

  template<string_value ENUM>
  std::string get_header_value() const;

  std::istream& get_entry_content_stream();
private:
  archive *_archive;
  archive_entry *_entry;
  entry_buffer _entry_buffer;
  std::istream _entry_stream;
  bool _already_requested_content_stream = false;
};

}
}

#endif // ARCHIVE_READER_ENTRY_HPP_INCLUDED
