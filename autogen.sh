#
# Copyright (C) 2012 Varphone Wong <varphone@qq.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as
# published by the Free Software Foundation.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public Licens
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-
#

#!/bin/bash

untracked_files="aclocal.m4 compile config.h.in config.guess config.sub config.status configure depcomp install-sh libtool ltmain.sh missing stamp-h1 Makefile.in man/Makefile.in src/Makefile.in"
untracked_dirs="autom4te.cache m4"

case "$1" in
	--clean)
		[ -f Makefile ] && make distclean
		rm -f ${untracked_files}
		rm -rf ${untracked_dirs}
	;;
	--package)
		pkginfo=$(grep "^AC_INIT" configure.ac | sed -e 's/^AC_INIT\(([^\)]*)\)/\1/' | tr -d '([ ])')
		package=$(echo ${pkginfo} | awk -F, '{print $1}')
		version=$(echo ${pkginfo} | awk -F, '{print $2}')
		bug_report_address=$(echo ${pkginfo} | awk -F, '{print $3}')
		prefix="${package}-${version}"
		tarball="${prefix}.tar.bz2"
		[ -d .git ] && {
            echo -n "Make tarball: ${tarball} ... "
			git archive --prefix="${prefix}/" master | bzip2 > "${tarball}" && {
    			md5sum -b "${tarball}" > "${tarball}.md5"
	    		sha1sum -b "${tarball}" > "${tarball}.sha1"
            } && echo "done" || echo "failure"
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
            [ -d __autogen_sh_tmp ] && rm -rf __autogen_sh_tmp
		}
	;;
	--help|-?)
		echo "./autogen.sh --[clean|package|help]"
        echo "Options:"
        echo "  --clean         Clean all untracked files"
        echo "  --package       Create tarball archive"
        echo "  --help          Show help message"
        exit 0
	;;
	*)
		aclocal
		libtoolize --automake
		autoheader
		automake --foreign --add-missing
		autoconf
	;;
esac

