# =========================================================================
# $Id: Makefile.am 136 2005-12-21 03:44:02Z s0undt3ch $
# =========================================================================
#             $URL: http://ipkungfu.ufsoft.org/svn/tags/ipkungfu-0.6.1/Makefile.am $
# $LastChangedDate: 2005-12-20 21:44:02 -0600 (Tue, 20 Dec 2005) $
#             $Rev: 136 $
#   $LastChangedBy: s0undt3ch $
# =========================================================================

# Define the IPKungFu script to install
sbin_SCRIPTS = ipkungfu
#ipkungfu_SOURCES = ipkungfu.in

# Define the dummy_server bin to install
sbin_PROGRAMS = dummy_server
dummy_server_SOURCES = dummy_server.c

# Define our configs to install
# We leave it empty so the dir /etc/ipkungfu will be blank but created
pkgsysconf_DATA =

# Define data going to share
pkgdata_DATA = files/conf/accept_hosts.conf \
		  files/conf/advanced.conf \
		  files/conf/custom.conf \
		  files/conf/forward.conf \
		  files/conf/ipkungfu.conf \
		  files/conf/log.conf \
		  files/conf/post.conf \
		  files/conf/pre.conf \
		  files/conf/redirect.conf \
		  files/conf/services.conf \
		  files/conf/vhosts.conf \
		  files/rc.ipkungfu

# Define the manual to install
man_MANS = man/ipkungfu.8

# Define the data dir(share)
pkgdoc_DATA = FAQ README AUTHORS COPYING ChangeLog

#pkgdata_DATA = FAQ README AUTHORS COPYING ChangeLog

# list sources here instead of using the ipkungfu_SOURCES macro
EXTRA_DIST=GPL.txt man/ipkungfu.8 files/rc.ipkungfu \
	   FAQ NEWS AUTHORS ChangeLog COPYING INSTALL README \
	   files/conf/accept_hosts.conf \
	   files/conf/advanced.conf \
	   files/conf/custom.conf \
	   files/conf/deny_hosts.conf \
	   files/conf/forward.conf \
	   files/conf/ipkungfu.conf \
	   files/conf/log.conf \
	   files/conf/post.conf \
	   files/conf/pre.conf \
	   files/conf/redirect.conf \
	   files/conf/services.conf \
	   files/conf/vhosts.conf

install-config: 
	$(INSTALL_DATA) ${srcdir}/files/conf/accept_hosts.conf $(DESTDIR)$(pkgsysconfdir)/accept_hosts.conf
	$(INSTALL_DATA) ${srcdir}/files/conf/advanced.conf $(DESTDIR)$(pkgsysconfdir)/advanced.conf
	$(INSTALL_DATA) ${srcdir}/files/conf/custom.conf $(DESTDIR)$(pkgsysconfdir)/custom.conf
	$(INSTALL_DATA) ${srcdir}/files/conf/deny_hosts.conf $(DESTDIR)$(pkgsysconfdir)/deny_hosts.conf
	$(INSTALL_DATA) ${srcdir}/files/conf/forward.conf $(DESTDIR)$(pkgsysconfdir)/forward.conf
	$(INSTALL_DATA) ${srcdir}/files/conf/ipkungfu.conf $(DESTDIR)$(pkgsysconfdir)/ipkungfu.conf
	$(INSTALL_DATA) ${srcdir}/files/conf/log.conf $(DESTDIR)$(pkgsysconfdir)/log.conf
	$(INSTALL_DATA) ${srcdir}/files/conf/post.conf $(DESTDIR)$(pkgsysconfdir)/post.conf
	$(INSTALL_DATA) ${srcdir}/files/conf/pre.conf $(DESTDIR)$(pkgsysconfdir)/pre.conf
	$(INSTALL_DATA) ${srcdir}/files/conf/redirect.conf $(DESTDIR)$(pkgsysconfdir)/redirect.conf
	$(INSTALL_DATA) ${srcdir}/files/conf/services.conf $(DESTDIR)$(pkgsysconfdir)/services.conf
	$(INSTALL_DATA) ${srcdir}/files/conf/vhosts.conf $(DESTDIR)$(pkgsysconfdir)/vhosts.conf
	
install-exec-hook:
		@echo Removing ipkungfu cache dir if exists
		-rm -rf $(DESTDIR)$(pkgsysconfdir)/cache
