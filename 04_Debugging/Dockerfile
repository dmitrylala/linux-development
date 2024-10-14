FROM ubuntu:latest
RUN apt-get update && apt-get install -y vim bash gdb make gcc

COPY ./Makefile ./range.c ./gt_* ./scenario_* ./

ENTRYPOINT ["bash"]
