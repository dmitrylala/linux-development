SUBDIRS = src tests


GENERATES=Makefile Makefile.in aclocal.m4 autom4te.cache compile config.guess config.h config.h.in config.h.in~ config.log config.status config.sub configure configure~ depcomp install-sh libtool ltmain.sh missing stamp-h1 test-driver 
GENERATES_SRC=src/*.o src/*.gcov src/Makefile src/Makefile.in src/*.la src/*.lo src/.deps src/.libs
GENERATES_TEST=tests/*.o tests/*.log tests/*.gcov tests/Makefile tests/Makefile.in tests/*.la tests/*.lo tests/*.trs tests/test-suite.log tests/.deps tests/.libs tests/zero tests/push tests/pop tests/init tests/grow


.PHONY: clean

checklog:	check
	cat tests/*.log

gcov:	check
	$(MAKE) $(MAKEFLAGS) -C src gcov

clean:
	rm -rf $(GENERATES) $(GENERATES_SRC) $(GENERATES_TEST)
