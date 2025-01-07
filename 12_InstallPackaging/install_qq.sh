#!/bin/bash
set -e

autoreconf -fisv && ./configure --prefix /tmp/qq && make all install
