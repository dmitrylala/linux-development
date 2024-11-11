FROM ubuntu:latest
RUN apt-get update && apt-get install -y \
    vim bash gdb make gcc autoconf gettext

WORKDIR /task
COPY ./Makefile.am ./configure.ac /task/
COPY ./src /task/src
COPY ./po /task/po

RUN autoreconf -fisv && ./configure && make

ENTRYPOINT [ "./src/guess" ]
