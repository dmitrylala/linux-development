GENERATES = prog prog-a prog-so liboutput_static.a liboutput.so *param README
TRASH = *.o *~ o.*
CFLAGS = -Wall

all:    README prog prog-a prog-so

.SECONDARY:	fun.o const.o
.INTERMEDIATE:	liboutput_static.a(fun.o const.o)

liboutput_static.a:	liboutput_static.a(fun.o const.o)

liboutput.so:	fun.o const.o
	$(CC) -shared -o $@ $^

prog:	prog.o fun.o const.o

prog-a:	prog.o liboutput_static.a
	$(CC) -L. $< -loutput_static -o $@

prog-so: prog.o liboutput.so
	$(CC) -L. $< -loutput -o $@

test: prog prog-a prog-so
	# no params
	./prog > prog_no_param 2>&1
	./prog-a > prog_a_no_param 2>&1
	# на моей машине работает без LD_LIBRARY_PATH=`pwd`
	./prog-so > prog_so_no_param 2>&1
	cmp prog_no_param prog_a_no_param
	cmp prog_no_param prog_so_no_param

	# one param
	./prog 1 > prog_one_param 2>&1
	./prog-a 1 > prog_a_one_param 2>&1
	./prog-so 1 > prog_so_one_param 2>&1
	cmp prog_one_param prog_a_one_param
	cmp prog_one_param prog_so_one_param

	# three params
	./prog 1 2 3 > prog_3_param 2>&1
	./prog-a 1 2 3 > prog_a_3_param 2>&1
	./prog-so 1 2 3 > prog_so_3_param 2>&1
	cmp prog_3_param prog_a_3_param
	cmp prog_3_param prog_so_3_param


README: prog
	./$< 2> $@

fun.o prog.o:  outlib.h

clean:
	rm -f $(TRASH)

distclean:      clean
	rm -rf $(GENERATES)
