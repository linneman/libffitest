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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#include <ffitest/ffitest.h>


char* g_default_outer_string = "outer string";
char* g_default_inner_string = "inner string";


void kill_ffitest( ffitest_t* p )
{
  if( p ) {
    if( p->internal )
      free( p->internal );
    free( p );
  }
}


ffitest_t* init_ffitest( void )
{
  ffitest_t *p = malloc(sizeof(ffitest_t));
  if( p ) {
    memset( p, 0, sizeof(ffitest_t) );
    p->internal = malloc( sizeof(ffitest_int_t) );
    if( p->internal == NULL ) {
      free( p );
      p = NULL;
    } else {
      p->s = g_default_outer_string;
      p->internal->s = g_default_inner_string;
    }
  }

  return p;
}


void print_ffi( const ffitest_t* p )
{
  printf("i:%d\n", p->i );
  printf("l:%ld\n", p->l );
  printf("f:%f\n", p->f );
  printf("lf:%le\n", p->lf );
  printf("s:%s\n", p->s );
  if( p->internal )
    printf("internal->s:%s\n", p->internal->s );
}


void set_ffi_params( ffitest_t* p, ffitest_params_t* par )
{
  printf("addresses: p: %lx, par: %lx\n", (unsigned long)p, (unsigned long)par );
  p->i = par->i;
  p->l = par->l;
  p->f = par->f;
  p->lf = par->lf;
  p->s = par->s;
  p->internal->s = par->internal->s;
}

void set_ffi_callback( ffitest_t* p, ffi_cb_t callback )
{
  p->ffi_cb = callback;
}

int invoke_cb( ffitest_t* p, int x )
{
  return p->ffi_cb( p, x );
}
