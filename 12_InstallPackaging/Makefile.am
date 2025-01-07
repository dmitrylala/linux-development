SUBDIRS = src po
GENERATES = *~ Makefile Makefile.in aclocal.m4 autom4te.cache m4 compile \
	config.* configure depcomp install-sh missing stamp-h1 ABOUT-NLS \
	po/*~ po/*.header po/Makefile po/Makefile.in* po/guess.pot po/ru \
	po/*quot* po/*.sin po/*.template po/POTFILES po/*.gmo po/stamp-it


.PHONY: clean

clean:
	make -C src/ clean
	rm -rf $(GENERATES)
