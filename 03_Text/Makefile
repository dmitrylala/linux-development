IMAGE_NAME = 03-text-ubuntu
CON_NAME = 03-text-con
IMAGE_TAG = 1.0

build:
	docker build -t $(IMAGE_NAME):$(IMAGE_TAG) .

run: build
	docker run -it --rm \
		--name $(IMAGE_TAG) \
		$(IMAGE_NAME):$(IMAGE_TAG)
