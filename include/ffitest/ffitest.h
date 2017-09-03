/*
    libffitest - utility library for testing foreign function interfaces
    Copyright 2017 Otto Linnemann

    This program is free software: you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public License
    as published by the Free Software Foundation, either version 2.1
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General
    Public License along with this program. If not, see
    <http://www.gnu.org/licenses/>.
*/

#ifndef FFITEST_H
#define FFITEST_H

#include <ffitest/ffitest.h>

#ifdef __cplusplus
extern "C" {
#endif

/*! \file ffitest.h
    \brief utility library for testing foreign function interfaces
    @{
 */

typedef struct {
  char* s;
} ffitest_int_t;


typedef struct {
  int  i;
  long l;
  float f;
  double lf;
  char* s;
  ffitest_int_t* internal;
} ffitest_params_t;

struct ffitest_s;
typedef int (*ffi_cb_t)( struct ffitest_s *p, int x );

typedef struct ffitest_s {
  int  i;
  long l;
  float f;
  double lf;
  char* s;
  ffitest_int_t* internal;
  ffi_cb_t ffi_cb;
} ffitest_t;


void kill_ffitest( ffitest_t* p );
ffitest_t* init_ffitest( void );
void print_ffi( const ffitest_t* p );
void set_ffi_params( ffitest_t* p, ffitest_params_t* par );
void set_ffi_callback( ffitest_t* p, ffi_cb_t callback );
int invoke_cb( ffitest_t* p, int x );

/*! @} */

#ifdef __cplusplus
}
#endif

#endif /* #ifndef REFSTRING_H */
