FROM ubuntu:latest
RUN apt-get update && apt-get install -y \
    vim bash gdb make gcc autoconf automake libtool gettext \
    pkg-config check librsync-dev libz-dev libssl-dev uthash-dev \
    libyajl-dev libncurses-dev

WORKDIR /task
COPY ./Makefile ./Show.c /task/

RUN make

ENTRYPOINT [ "bash" ]
