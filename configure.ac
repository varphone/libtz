#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([libtz], [1.0.0], [varphone@qq.com])
AM_INIT_AUTOMAKE([-Wall foreign])
AM_SILENT_RULES([yes])
LT_INIT([dlopen win32-dll shared static])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/tz.c])
AC_CONFIG_HEADERS([config.h])

# libtz version
LIBTZ_VERSION="1.0.0"
LIBTZ_LT_MAJOR=1
LIBTZ_LT_MINOR=0
LIBTZ_LT_MICRO=0
LIBTZ_VERSION_INFO=`expr $LIBTZ_LT_MAJOR + $LIBTZ_LT_MINOR`:$LIBTZ_LT_MICRO:$LIBTZ_LT_MINOR
AC_SUBST([LIBTZ_VERSION])
AC_SUBST([LIBTZ_VERSION_INFO])


# Checks for programs.
AC_PROG_CC_C99
AC_PROG_LIBTOOL

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h string.h sys/time.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

case ${host} in
	*linux*)
		SYS=linux
	;;
	*i686-*mingw32*)
		SYS=mingw32
		ARCH=i686
	;;
	*x86_64-*mingw32*)
		ARCH=x86_64
		SYS=mingw32
	;;
esac
AM_CONDITIONAL([HAVE_UNIX], test "x$SYS" = xlinux)
AM_CONDITIONAL([HAVE_WIN32], test "x$SYS" = xmingw32 -a "x$ARCH" = xi686)
AM_CONDITIONAL([HAVE_WIN64], test "x$SYS" = xmingw32 -a "x$ARCH" = xx86_64)

AC_CONFIG_FILES([
Makefile
tz.pc
src/Makefile
])
AC_OUTPUT
