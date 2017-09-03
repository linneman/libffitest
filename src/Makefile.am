AM_CPPFLAGS = -Wall -std=c99 -I$(top_srcdir)/include

# meta library name used by libtool
lib_LTLIBRARIES=libffitest.la
libffitest_la_LDFLAGS = -version-info $(libtool_VERSION)
libffitest_la_LIBADD = -ldl

# the rest of the sources goes into distribution (make dist)
libffitest_la_SOURCES = \
	ffitest.c
