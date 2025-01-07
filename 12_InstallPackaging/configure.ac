AC_PREREQ([2.69])
AC_INIT([Guessing palindrome], [1.0], [dim.nesterov2017@gmail.com], [guess])
AM_INIT_AUTOMAKE([foreign])
LT_INIT([disable-static])
DX_INIT_DOXYGEN([guess])

AM_GNU_GETTEXT([external])
AM_GNU_GETTEXT_REQUIRE_VERSION(0.21)

AC_CONFIG_SRCDIR([src/guess.c])
AC_CONFIG_HEADERS([config.h])
AC_SUBST(GETTEXT_PACKAGE, "$PACKAGE")
ALL_LINGUAS="ru"

# Checks for programs.
AC_PROG_CC
IT_PROG_INTLTOOL
AC_PROG_LIBTOOL

# Checks for libraries.
PKG_CHECK_MODULES([CHECK], [check])

# Checks for header files.
AC_CHECK_HEADERS([libintl.h locale.h stdlib.h ctype.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([setlocale])

AC_CONFIG_FILES([
    Makefile
    src/Makefile
    lib/Makefile
    po/Makefile.in
    tests/Makefile
    Doxyfile
])
AC_OUTPUT
