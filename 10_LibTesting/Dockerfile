FROM ubuntu:latest
RUN apt-get update && apt-get install -y \
    vim bash gdb make gcc autoconf automake libtool gettext \
    pkg-config check librsync-dev libz-dev libssl-dev uthash-dev libyajl-dev

WORKDIR /task
COPY ./Makefile.am ./configure.ac /task/
COPY ./src /task/src
COPY ./tests /task/tests

RUN autoreconf -fisv && ./configure && make

ENTRYPOINT [ "bash" ]
