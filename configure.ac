#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_INIT([libffitest],[0.1],[linneman@gmx.de])
AC_PREREQ([2.61])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([subdir-objects])
AC_CONFIG_SRCDIR([src/ffitest.c])
AC_CONFIG_HEADERS([config.h])

# For libtool versioning info, format is CURRENT:REVISION:AGE
# specify version information for library using the following rules:
# - library source changed -> increment REVISION
# - interfaces added/removed/changed -> increment CURRENT, REVISION = 0
# - interfaces added -> increment AGE
# - interfaces removed -> AGE = 0
LFFI_CURRENT=1
LFFI_REVSION=1
LFFI_AGE=0

libtool_VERSION=$LFFI_CURRENT:$LFFI_REVSION:$LFFI_AGE
AC_SUBST(libtool_VERSION)

# determine version information for pkg-config
# attention: this works exclusviely for GNU/Linux and BSD based systems
pkgconfig_VERSION=$(expr $LFFI_CURRENT - $LFFI_AGE).$LFFI_AGE.$LFFI_REVSION
AC_SUBST(pkgconfig_VERSION)

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([pthread], [pthread_create])

# Checks for header files.
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h string.h ptread.h stdint.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T
AC_HEADER_TIME

# Checks for library functions.
AC_FUNC_CLOSEDIR_VOID
AC_FUNC_MEMCMP
AC_FUNC_SELECT_ARGTYPES
AC_TYPE_SIGNAL
AC_FUNC_STAT
AC_PROG_LIBTOOL
AC_CHECK_FUNCS([memset])

AC_CONFIG_FILES([Makefile src/Makefile include/Makefile include/ffitest/Makefile libffitest.pc])
AC_OUTPUT
