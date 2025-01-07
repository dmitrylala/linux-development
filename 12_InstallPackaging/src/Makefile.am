bin_PROGRAMS = guess
AM_CFLAGS = -D'LOCALE_PATH="$(localedir)"'

guess_SOURCES = guess.c
guess_LDADD = $(top_builddir)/lib/libpalindrome.la

GENERATES = guess *.o *.lo *.la *~ Makefile Makefile.in .deps .libs


.PHONY: clean

clean:
	rm -rf $(GENERATES)
