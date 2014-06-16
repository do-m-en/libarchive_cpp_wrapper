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

#include "archive_reader_entry.hpp"

#include "archive_exception.hpp"

namespace ns_archive {
namespace ns_reader {

entry::entry(archive* archive, archive_entry* entry) :
  _archive(archive),
  _entry(entry),
  _entry_buffer(_archive),
  _entry_stream(&_entry_buffer)
{
  //
}

// -------------------------------- //
template<>
std::string entry::get_header_value<entry::string_value::HARDLINK>() const
{
  return archive_entry_hardlink(_entry);
}

template<>
std::string entry::get_header_value<entry::string_value::PATHNAME>() const
{
  return archive_entry_pathname(_entry);
}

template<>
std::string entry::get_header_value<entry::string_value::SOURCEPATH>() const
{
  return archive_entry_sourcepath(_entry);
}

template<>
std::string entry::get_header_value<entry::string_value::SYMLINK>() const
{
  return archive_entry_symlink(_entry);
}

// -------------------------------- //
std::istream& entry::get_entry_content_stream()
{
  if(_already_requested_content_stream)
  {
    throw archive_exception( "get_entry_content_stream requested more than once for the same entry" );
  }

  _already_requested_content_stream = true;

  return _entry_stream;
}

}
}
