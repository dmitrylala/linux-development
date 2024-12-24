.PHONY: clean

IMAGE_NAME = 10-lib-testing
CON_NAME = 10-lib-testing
IMAGE_TAG = 1.0

build:
	docker build -t $(IMAGE_NAME):$(IMAGE_TAG) .

run: build
	docker run -it --rm \
		--name $(CON_NAME) \
		$(IMAGE_NAME):$(IMAGE_TAG)
