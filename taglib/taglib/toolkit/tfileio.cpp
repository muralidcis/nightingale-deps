/***************************************************************************
    copyright            : (C) 2002, 2003 by Scott Wheeler
    email                : wheeler@kde.org
 ***************************************************************************/

/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it  under the terms of the GNU Lesser General Public License version  *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  *
 *   USA                                                                   *
 ***************************************************************************/

#include "tfileio.h"

#if WIN32
#include <windows.h>
#endif

using namespace TagLib;

#if WIN32

FileName::FileName(const char* name) : m_name(name) {
  wchar_t *buffer = new wchar_t[m_name.length() + 1];
  int chars = ::MultiByteToWideChar(CP_OEMCP,
                                    0,
                                    name,
                                    m_name.length(),
                                    buffer,
                                    m_name.length() + 1);
  m_wname.assign(buffer, chars);
  delete[] buffer;
}

#endif