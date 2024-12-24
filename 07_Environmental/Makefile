.PHONY: clean

IMAGE_NAME = 07-environmental
CON_NAME = 07-environmental
IMAGE_TAG = 1.0

build:
	docker build -t $(IMAGE_NAME):$(IMAGE_TAG) .

run: build
	docker run -it --rm \
		--name $(CON_NAME) \
		$(IMAGE_NAME):$(IMAGE_TAG)
