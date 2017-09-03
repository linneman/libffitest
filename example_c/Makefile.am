ACLOCAL_AMFLAGS = -I m4
AM_CPPFLAGS = -Wall -std=c99

# sample program
bin_PROGRAMS = ffitestexample
ffitestexample_SOURCES = example.c
ffitestexample_CPPFLAGS = $(libffitest_CFLAGS) $(AM_CFLAGS)
ffitestexample_LDFLAGS = $(libffitest_LIBS) $(AM_LDFLAGS)
