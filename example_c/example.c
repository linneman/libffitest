#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ffitest/ffitest.h>

int callback( ffitest_t *p, int x )
{
  printf("*** callback invoked with p=%lx, x=:%d ***\n", (unsigned long)p, x );
  printf("state object:\n");
  print_ffi( p );
  return x+1;
}

int main()
{
  ffitest_t* p;
  ffitest_int_t par_int = { .s = "int hello" };
  ffitest_params_t par = { .i = 42,
                           .l = 44,
                           .f = 45.45,
                           .lf = 99.99e99,
                           .s = "ext hello",
                           .internal = &par_int
  };
  int y;

  printf("sample invocation of ffi test library\n\n");

  p = init_ffitest();
  if( p == NULL ) {
    fprintf( stderr, "initialization error, exit now!\n");
    return -1;
  }

  printf("default ffi library state:\n");
  print_ffi( p );
  printf("\n");

  printf("parameterized ffi library state:\n");
  set_ffi_params( p, &par );
  print_ffi( p );
  printf("\n");

  set_ffi_callback( p, &callback );
  y = invoke_cb( p, 41 );
  printf("callback returned: %d\n", y );

  kill_ffitest( p );

  return 0;
}
