CFLAGS=-g -Wall

bin_PROGRAMS=rhasher
rhasher_SOURCES=rhasher.c

TESTS=test

test:
	echo "SHA1 \"checksum" | ./rhasher > output
	echo -n "checksum" | sha1sum | awk '{print $$1 }' > gt_result
	cmp gt_result output

	echo "MD5 \"checksum" | ./rhasher > output
	echo -n "checksum" | md5sum | awk '{print $$1 }' > gt_result
	cmp gt_result output
