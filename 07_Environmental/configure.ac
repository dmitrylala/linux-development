#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([rhasher], [1.0], [])
AC_CONFIG_SRCDIR([rhasher.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([foreign subdir-objects])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.
AC_CHECK_LIB([rhash],[rhash_library_init],[],[AC_MSG_ERROR([rhash is needed])])
AC_CHECK_LIB([readline], [readline])

# Checks for header files.
AC_CHECK_HEADERS([stdlib.h])
AC_CHECK_HEADERS([rhash.h])
AC_CHECK_HEADERS([readline/readline.h])

# Optional clues
AC_ARG_ENABLE([readline],
    AS_HELP_STRING([--enable-readline], [Enable readline]),
    AC_DEFINE(READLINE,[],[Readline enabled])
  )

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
