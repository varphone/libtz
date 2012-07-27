#!/bin/bash

case "$1" in
	--clean)
		[ -f Makefile ] && make distclean
		rm -f aclocal.m4 compile config.h.in config.guess config.sub config.status configure depcomp install-sh libtool ltmain.sh missing stamp-h1 Makefile.in man/Makefile.in src/Makefile.in 
		rm -rf autom4te.cache m4
	;;
	--package)
		pkginfo=$(grep "^AC_INIT" configure.ac | sed -e 's/^AC_INIT\(([^\)]*)\)/\1/' | tr -d '([ ])')
		package=$(echo ${pkginfo} | awk -F, '{print $1}')
		version=$(echo ${pkginfo} | awk -F, '{print $2}')
		bug_report_address=$(echo ${pkginfo} | awk -F, '{print $3}')
		prefix="${package}-${version}"
		tarball="${prefix}.tar.bz2"
		[ -d .git ] && {
			git archive --prefix="${prefix}/" master | bzip2 > "${tarball}"
			md5sum -b "${tarball}" > "${tarball}.md5"
			sha1sum -b "${tarball}" > "${tarball}.sha1"
		}
		[ -d .svn ] && {
			mkdir -p __autogen_sh_tmp/${prefix} &&
			svn export -r HEAD . __autogen_sh_tmp/${prefix} &&
			cd __autogen_sh_tmp/ &&
			tar jcf ../${tarball} ${prefix} &&
			cd .. && {
				md5sum -b ${tarball} > "${tarball}.md5"
				sha1sum -b ${tarball} > "${tarball}.sha1"
			}
		}
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

