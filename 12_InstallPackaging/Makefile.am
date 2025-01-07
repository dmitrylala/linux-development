SUBDIRS = po lib src tests

man1_MANS = doxygen-doc/man/man1/guess.1

GENERATES = *~ Makefile Makefile.in aclocal.m4 autom4te.cache m4 compile \
	config.* configure depcomp install-sh missing stamp-h1 ABOUT-NLS \
	po/*~ po/*.header po/Makefile po/Makefile.in* po/guess.pot po/ru \
	po/*quot* po/*.sin po/*.template po/POTFILES po/*.gmo po/stamp-it \
	test-driver libtool ltmain.sh Doxyfile Doxyfile.in.bak doxygen-doc


.PHONY: clean

@DX_RULES@

all-local: doxygen-doc

doxygen-doc/man/man1/guess.1: doxygen-doc

checklog: check
	cat tests/*.log

install-data-local: doxygen-doc
	mkdir -p $(DESTDIR)/$(docdir)
	cp -a doxygen-doc/html $(DESTDIR)/$(docdir)

http: doxygen-doc
	python3 -m http.server --directory $</html

install:
	sudo ./sh/install.sh

uninstall:
	sudo ./sh/uninstall.sh

clean:
	make -C src/ clean
	make -C lib/ clean
	make -C tests/ clean
	rm -rf $(GENERATES)
