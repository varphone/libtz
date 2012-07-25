#!/bin/bash

case "$1" in
	--clean)
		[ -f Makefile ] && make distclean
		rm -f aclocal.m4 compile config.h.in config.guess config.sub config.status configure depcomp install-sh libtool ltmain.sh missing stamp-h1 Makefile.in man/Makefile.in src/Makefile.in 
		rm -rf autom4te.cache m4
	;;
	--help)
		echo "./autogen [--clean|help]"
	;;
	*)
		aclocal
		libtoolize --automake
		autoheader
		automake --foreign --add-missing
		autoconf
	;;
esac

