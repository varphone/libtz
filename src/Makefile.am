ACLOCAL_AMFLAGS = -I m4
AM_CFLAGS =

noinst_PROGRAMS = tz_test
lib_LTLIBRARIES = libtz.la

tz_test_SOURCES = tz_test.c
tz_test_CFLAGS = -include $(top_builddir)/config.h
tz_test_LDADD = libtz.la
tz_test_DEPENDENCIES = libtz.la

# includes
tzincdir = $(includedir)/tz
tzinc_HEADERS = tz.h

libtz_la_SOURCES = tz.c $(vectorinc_HEADERS)
libtz_la_CFLAGS = -include $(top_builddir)/config.h
libtz_la_LIBADD =
if HAVE_UNIX
libtz_la_LDFLAGS = -version-info $(LIBTZ_VERSION_INFO)
endif
if HAVE_WIN32
libtz_la_LDFLAGS = -avoid-version -no-undefined
endif
if HAVE_WIN64
libtz_la_LDFLAGS = -avoid-version -no-undefined
endif
libtz_la_DEPENDENCIES =

EXTRA_DIST =

test:
	./tz_test

