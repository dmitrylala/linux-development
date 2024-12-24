autoreconf --install && \
    ./configure --disable-dependency-tracking &&
    make && make test
