GENERATES = guess *.o *~ Makefile Makefile.in .deps .libs

bin_PROGRAMS = guess
AM_CFLAGS = -D'LOCALE_PATH="$(localedir)"'


.PHONY: clean

clean:
	rm -rf $(GENERATES)
