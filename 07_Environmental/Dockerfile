FROM ubuntu:latest
RUN apt-get update && apt-get install -y \
    vim bash gdb make gcc autoconf automake libtool gettext \
    pkg-config check librsync-dev libz-dev libssl-dev uthash-dev libyajl-dev \
    librhash-dev libreadline-dev

WORKDIR /task
COPY ./Makefile.am ./configure.ac ./rhasher.c ./run.sh /task/

ENTRYPOINT [ "bash", "run.sh" ]
