#!/bin/bash
set -e

autoreconf -fisv && ./configure && make AM_CFLAGS=-D'LOCALE_PATH=\"po\"' all
make -C po/ update-po
install -Dm644 po/ru.gmo po/ru/LC_MESSAGES/guess.mo
