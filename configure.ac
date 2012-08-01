# =========================================================================
# $Id: configure.ac 155 2006-09-14 23:41:15Z s0undt3ch $
# =========================================================================
#             $URL: http://ipkungfu.ufsoft.org/svn/tags/ipkungfu-0.6.1/configure.ac $
# $LastChangedDate: 2006-09-14 18:41:15 -0500 (Thu, 14 Sep 2006) $
#             $Rev: 155 $
#   $LastChangedBy: s0undt3ch $
# =========================================================================

AC_PREREQ(2.59)
AC_INIT([IPKungFu], [0.6.1], [http://ipkungfu.ufsoft.org], [ipkungfu])
AM_INIT_AUTOMAKE([gnu dist-bzip2 subdir-objects])
AC_CONFIG_SRCDIR([dummy_server.c])
AC_CONFIG_HEADER([config.h])

# Checks for programs
AC_PROG_CC
AC_PROG_INSTALL

# Compiler
AM_PROG_CC_C_O

# Check our needed program paths wich will replace @VAR@
AC_PATH_PROG([IPTABLES], [iptables],, [$PATH:/sbin:/usr/sbin:/usr/local/sbin])
AC_PATH_PROG([MD5SUM], [md5sum])
AC_PATH_PROG([MODPROBE], [modprobe],, [$PATH:/sbin:/usr/sbin:/usr/local/sbin])
AC_PATH_PROG([RMMOD], [rmmod],, [$PATH:/sbin:/usr/sbin:/usr/local/sbin])
AC_PATH_PROG([DEPMOD], [depmod],, [$PATH:/sbin:/usr/sbin:/usr/local/sbin])
AC_PATH_PROG([LSMOD], [lsmod])
AC_PATH_PROG([CUT], [cut])
AC_PATH_PROG([TR], [tr])
AC_PATH_PROG([GREP], [grep])
AC_PATH_PROG([SED], [sed])
AC_PATH_PROG([AWK], [awk])
# Needed for dummy_server
AC_PATH_PROG([SU], [su])
AC_PATH_PROG([KILLALL], [killall])
AC_PATH_PROG([NETSTAT], [netstat])
AC_PATH_PROG([CHOWN], [chown])

if [[ -z $IPTABLES ]]; then
	AC_MSG_ERROR(Couldn't find 'iptables' in your path. You can find it at http://www.iptables.org)
fi
if [[ -z $MD5SUM ]]; then
	AC_MSG_ERROR(Couldn't find 'md5sum' in your path. You can find it at http://www.gnu.org/software/coreutils)
fi
if [[ -z $MODPROBE ]]; then
	AC_MSG_ERROR(Couldn't find 'modprobe' in your path. You can find it at http://www.kernel.org/pub/linux/kernel/people/rusty/modules)
fi
if [[ -z $RMMOD ]]; then
	AC_MSG_WARN(Couldn't find 'rmmod' in your path. You can find it at http://www.kernel.org/pub/linux/kernel/people/rusty/modules)
fi
if [[ -z $DEPMOD ]]; then
	AC_MSG_WARN(Couldn't find 'depmod' in your path. You can find it at http://www.kernel.org/pub/linux/kernel/people/rusty/modules)
fi
if [[ -z $LSMOD ]]; then
	AC_MSG_WARN(Couldn't find 'lsmod' in your path. You can find it at http://www.kernel.org/pub/linux/kernel/people/rusty/modules)
fi		
if [[ -z $CUT ]]; then
	AC_MSG_ERROR(Couldn't find 'cut' in your path. You can find it at http://www.gnu.org/software/coreutils/)
fi
if [[ -z $GREP ]]; then
	AC_MSG_ERROR(Couldn't find 'grep' in your path. You can find it at http://www.gnu.org/software/grep/grep.html)
fi
if [[ -z $SED ]]; then
	AC_MSG_ERROR(Couldn't find 'sed' in your path. You can find it at http://sed.sourceforge.net/)
fi
if [[ -z $AWK ]]; then
	AC_MSG_ERROR(Couldn't find 'awk' in your path. You can find it at http://www.gnu.org/software/gawk/gawk.html)
fi

# Needed for dummy_server
if [[ -z $SU ]]; then
	AC_MSG_WARN(Couldn't find 'su' in your path. You can find it at http://shadow.pld.org.pl)
fi
if [[ -z $KILLALL ]]; then
	AC_MSG_WARN(Couldn't find 'killall' in your path. You can find it at http://psmisc.sourceforge.net)
fi
if [[ -z $NETSTAT ]]; then
	AC_MSG_WARN(Couldn't find 'netstat' in your path. You can find it at http://sites.inka.de/lina/linux/NetTools)
fi
if [[ -z $CHOWN ]]; then
	AC_MSG_WARN(Couldn't find 'chown' in your path. You can find it at http://www.gnu.org/software/coreutils)
fi

# Checks for header files.
AC_HEADER_STDC
AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([arpa/inet.h netinet/in.h stdlib.h string.h sys/socket.h unistd.h])

# Checks for library functions.
AC_CHECK_FUNCS([memset socket strtol])

# Define our config dir to use in Makefile.am
# And replace all occurrences
#pkgsysconfdir="${sysconfdir}/${PACKAGE}"
# Because of autoconf's imposed restrictions, we can't substitute based on
# the above definition of pkgsysconfig, for example,
# @pkgsysconfdir@, it will expand to ${exec_prefix}/etc/ipkungfu
# which won't do to tweak our ipkungfu script to source from another dir.
# So we hardcode it to where it's always been.
pkgsysconfdir="/etc/ipkungfu"
AC_SUBST(pkgsysconfdir,$pkgsysconfdir)

# Define our share dir to use in Makefile.am
# And replace all ocurrences
pkgdatadir="${datadir}/${PACKAGE}"
AC_SUBST(pkgdatadir,$pkgdatadir)


# Define our docs dir, since it's not working for me.
# Maybe only CVS version of autoconf supports it
docdir="${datadir}/doc/"
# Now we define our own
pkgdocdir="${docdir}/${PACKAGE}-${PACKAGE_VERSION}"
AC_SUBST(pkgdocdir,$pkgdocdir)

AC_CONFIG_FILES([
                 Makefile
                 ipkungfu
                 man/ipkungfu.8])
AC_OUTPUT

echo "----"
echo ""
echo "        Prefix:   $prefix"
echo ""
echo ""
echo "   Binaries Path:"
echo ""
echo "      iptables:   $IPTABLES"
echo "        md5sum:   $MD5SUM"
echo "      modprobe:   $MODPROBE"
echo "         rmmod:   $RMMOD"
echo "         lsmod:   $LSMOD"
echo "        depmod:   $DEPMOD"
echo "            su:   $SU"
echo "       killall:   $KILLALL"
echo "       netstat:   $NETSTAT"
echo "         chown:   $CHOWN"
echo "           sed:   $SED"
echo "          grep:   $GREP"
echo "           cut:   $CUT"
echo ""
echo "----"
# Check for ipkungfu's cache dir, and tells the user to remove it.
#if [[ -d /etc/ipkungfu/cache ]]; then
#	echo "/etc/ipkungfu/cache directory exists. You should remove it before you run this newly installed ipkungfu script"
#   echo "----"
#fi

