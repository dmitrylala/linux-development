.PHONY: clean

IMAGE_NAME = 08-i18n
CON_NAME = 08-i18n
IMAGE_TAG = 1.0

build:
	docker build -t $(IMAGE_NAME):$(IMAGE_TAG) .

run: build
	docker run -it --rm \
		--name $(IMAGE_TAG) \
		$(IMAGE_NAME):$(IMAGE_TAG)
