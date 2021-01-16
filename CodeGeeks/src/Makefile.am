## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = projet2

projet2_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	fonction.c fonction.h \
	functions.c functions.h \
	Troupeaux.c Troupeaux.h \
	plant.c plant.h \
	auth.c auth.h \
	client.c client.h

projet2_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

