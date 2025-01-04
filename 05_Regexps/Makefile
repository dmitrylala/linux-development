GENERATES = *.o *.txt esub esub.dSYM
CFLAGS = -Wall -O3 -g


.PHONY: all clean test

all: esub test

esub: esub.c
	$(CC) $(CFLAGS) $< -o $@

# compare:
# ./esub regexp substitution string
# echo 'string' | sed -E 's/regexp/substitution/'
test: esub
	./esub 'abc' 'cba' 'abcabc' > 01_esub.txt
	echo "abcabc" | sed -E 's/abc/cba/' > 01_sed.txt
	cmp 01_esub.txt 01_sed.txt

	./esub 'ab(c)' 'AB\1' 'some abc' > 02_esub.txt
	echo "some abc" | sed -E 's/ab(c)/AB\1/' > 02_sed.txt
	cmp 02_esub.txt 02_sed.txt

	./esub '[0-9]' 'A' 'sub done: 1' > 03_esub.txt
	echo "sub done: 1" | sed -E 's/[0-9]/A/' > 03_sed.txt
	cmp 03_esub.txt 03_sed.txt

	./esub '(a)b(c)d(e)f' 'reversed: \3\2\1' 'abcdef' > 04_esub.txt
	echo "abcdef" | sed -E 's/(a)b(c)d(e)f/reversed: \3\2\1/' > 04_sed.txt
	cmp 04_esub.txt 04_sed.txt


clean:
	rm -rf $(GENERATES)
