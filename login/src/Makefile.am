## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = login

login_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	reclamation.c reclamation.h \
	reservation.c reservation.h \
        ajouter.c ajouter.h \
        afficher.c afficher.h \
        clientfid.c clientfid.h \
        fonction.c fonction.h \
        voiture.c voiture.h \
        msg.c msg.h \
	addclient.c addclient.h \
	addvol.c addvol.h \
	Reservations.c reservations.h \
	Reservationh.c reservationh.h \
        twilio.c twilio.h

login_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

