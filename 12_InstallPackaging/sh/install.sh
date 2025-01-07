#!/bin/bash
set -e

TARGET_DIR="/usr/local"

# binary
cp ./src/guess $TARGET_DIR/bin/guess
mkdir -p $TARGET_DIR/bin/.libs && \
    cp ./src/.libs/guess $TARGET_DIR/bin/.libs/

# localization
cp -r ./po/ru $TARGET_DIR/bin/po

# docs
mkdir -p $TARGET_DIR/share/man/man1
cp ./doxygen-doc/man/man1/guess.c.1 $TARGET_DIR/share/man/man1/guess.1
