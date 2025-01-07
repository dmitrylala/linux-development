TESTS = tests
check_PROGRAMS = tests

AM_CFLAGS = -I$(top_builddir)/lib @CHECK_CFLAGS@
LDADD = $(top_builddir)/lib/libpalindrome.la @CHECK_LIBS@

GENERATES = *.c *.o .deps .libs Makefile Makefile.in \
	tests *.log *.trs


.PHONY: clean

.ts.c:
	checkmk $< > $@

clean:
	rm -rf $(GENERATES)