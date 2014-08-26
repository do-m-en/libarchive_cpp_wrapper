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
