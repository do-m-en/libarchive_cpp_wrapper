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

#include "archive_writer_entry.hpp"

namespace ns_archive {
namespace ns_writer {

entry::entry(std::istream& stream, size_t stream_size) :
  _entry( archive_entry_new() ),
  _stream( &stream )
{
  archive_entry_set_mode( _entry, S_IFREG );
  archive_entry_set_size( _entry, stream_size );
}

void entry::clear_entry(std::istream& stream, size_t stream_size)
{
  archive_entry_clear( _entry );
  _stream = &stream;
  archive_entry_set_mode( _entry, S_IFREG );
  archive_entry_set_size( _entry, stream_size );
}

//----------------------------------------------------//
void entry::set_header_value_gid(int64_t value)
{
  archive_entry_set_gid(_entry, value);
}

void entry::set_header_value_ino(int64_t value)
{
  archive_entry_set_ino(_entry, value);
}

void entry::set_header_value_ino64(int64_t value)
{
  archive_entry_set_ino64(_entry, value);
}

void entry::set_header_value_size(int64_t value)
{
  archive_entry_set_size(_entry, value);
}

void entry::set_header_value_uid(int64_t value)
{
  archive_entry_set_uid(_entry, value);
}

void entry::set_header_value_mode(mode_t value)
{
  archive_entry_set_mode(_entry, value);
}

void entry::set_header_value_perm(mode_t value)
{
  archive_entry_set_perm(_entry, value);
}

void entry::set_header_value_rdev(dev_t value)
{
  archive_entry_set_rdev(_entry, value);
}

void entry::set_header_value_rdevmajor(dev_t value)
{
  archive_entry_set_rdevmajor(_entry, value);
}

void entry::set_header_value_rdevminor(dev_t value)
{
  archive_entry_set_rdevminor(_entry, value);
}

void entry::set_header_value_gname(const std::string& value)
{
  archive_entry_set_gname(_entry, value.c_str());
}

void entry::set_header_value_hardlink(const std::string& value)
{
  archive_entry_set_hardlink(_entry, value.c_str());
}

void entry::set_header_value_link(const std::string& value)
{
  archive_entry_set_link(_entry, value.c_str());
}

void entry::set_header_value_pathname(const std::string& value)
{
  archive_entry_set_pathname(_entry, value.c_str());
}

void entry::set_header_value_symlink(const std::string& value)
{
  archive_entry_set_symlink(_entry, value.c_str());
}

void entry::set_header_value_uname(const std::string& value)
{
  archive_entry_set_uname(_entry, value.c_str());
}

void entry::set_header_value_nlink(unsigned int value)
{
  archive_entry_set_nlink(_entry, value);
}

void entry::set_header_value_mtime(time_t time, long value)
{
  archive_entry_set_mtime(_entry, time, value);
}

archive_entry* entry::get_entry() const
{
  return _entry;
}

std::istream& entry::get_stream() const
{
  return *_stream;
}

}
}
