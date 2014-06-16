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

#ifndef ARCHIVE_READER_HPP_INCLUDED
#define ARCHIVE_READER_HPP_INCLUDED

#include <istream>
#include <memory>
#include <archive.h>

#include "archive_reader_format.hpp"
#include "archive_reader_filter.hpp"
#include "archive_reader_entry.hpp"
#include "archive_reader_iterator.hpp"

namespace ns_archive {

class reader
{
public:
  reader(reader&&) = default;

  reader(const reader&) = delete;
  reader& operator=(const reader&) = delete;

  template<ns_reader::format FORMAT, ns_reader::filter FILTER, typename DATA_CONTAINER>
  static reader make_reader(DATA_CONTAINER&& container);

  template<ns_reader::format FORMAT, typename DATA_CONTAINER>
  static reader make_reader(DATA_CONTAINER&& container);

  ns_reader::entry* get_next_entry();
  bool has_next_entry();

  ns_reader::iterator begin();
  ns_reader::iterator end();

private:
  reader();

  template<ns_reader::format FORMAT>
  void init_format();

  template<ns_reader::filter FILTER>
  void init_filter();

  template<typename DATA_CONTAINER>
  void init_data(DATA_CONTAINER&& container);

  std::shared_ptr<archive> _archive;
  ns_reader::entry *_next_entry = nullptr;
};

}

#include "archive_reader.tpp"

#endif // ARCHIVE_READER_HPP_INCLUDED
