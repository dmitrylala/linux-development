.PHONY: clean

IMAGE_NAME = 04-debugging-ubuntu
CON_NAME = 04-debugging-con
IMAGE_TAG = 1.0

GENERATES = range res_*
TRASH = *.o *~ o.* *.out
CFLAGS = -Wall -O0 -g

all: range test

range: range.o
	$(CC) $(CFLAGS) -o range $^

test:
	gdb --args range 1 12 < scenario_01.gdb 2>&1 | grep "@@@" > res_01.txt
	gdb --args range -100 100 3 < scenario_02.gdb 2>&1 | grep "@@@" > res_02.txt
	cmp gt_01.txt res_01.txt && cmp gt_02.txt res_02.txt

clean:
	rm -f $(TRASH)

distclean: clean
	rm -rf $(GENERATES)

build:
	docker build -t $(IMAGE_NAME):$(IMAGE_TAG) .

run: build
	docker run -it --rm \
		--name $(IMAGE_TAG) \
		$(IMAGE_NAME):$(IMAGE_TAG)
