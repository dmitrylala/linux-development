#!/bin/bash
set -e

TARGET_DIR="/usr/local"

# binary
rm $TARGET_DIR/bin/guess $TARGET_DIR/bin/.libs/guess

# localization
rm -rf $TARGET_DIR/bin/po

# docs
rm $TARGET_DIR/share/man/man1/guess.1
