AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS = gcry

gcry_CPPFLAGS = -I$(top_srcdir) -I../prefix/include
gcry_SOURCES = gcry.cc
gcry_LDADD = -L../prefix/lib -lgcrypt
