GENERATES = Show
TRASH = *.o *~ o.*

IMAGE_NAME = 01-terminal-project
CON_NAME = 01-terminal-project
IMAGE_TAG = 1.0


Show: Show.c
	$(CC) $< $(CFLAGS) -o $@ -lncurses

clean:
	rm -f $(TRASH)

distclean: clean
	rm -rf $(GENERATES)


build:
	docker build -t $(IMAGE_NAME):$(IMAGE_TAG) .

run: build
	docker run -it --rm \
		--name $(CON_NAME) \
		$(IMAGE_NAME):$(IMAGE_TAG)
