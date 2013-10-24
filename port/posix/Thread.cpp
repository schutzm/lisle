/* -*- mode:C++ -*-
///////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2003-2012, Markus Schütz
//
// This library is free software. You can redistribute  and/or  modify it under
// the terms of the GNU Lesser General Public License  as published by the Free
// Software Foundation.  Either version 2.1 of the License, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,  but WITHOUT
// ANY  WARRANTY.  Without  even  the  implied  warranty  of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
// for more details.
//
// You should have received  a  copy  of  the GNU Lesser General Public License
// along with this library. If not, write to the Free Software Foundation, Inc,
// 59  Temple Place,  Suite 330,  Boston,  MA  02111-1307  USA,  or consult URL
// http://www.gnu.org/licenses/lgpl.html.
//
///////////////////////////////////////////////////////////////////////////////
*/
#include <lisle/sys/Thread>

namespace lisle {
namespace sys {

Thread::Thread ()
: signal(0)
, handle(pthread_self())
{}

uint32_t Thread::id () const
{
	return static_cast<uint32_t>(handle);
}

bool Thread::equal (const Thread& that) const
{
	return pthread_equal(this->handle, that.handle);
}

bool Thread::equal (const Thread* that) const
{
	return pthread_equal(this->handle, that->handle);
}
	
}
}