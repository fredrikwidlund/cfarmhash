LIB_CFLAGS = -O3 -flto -std=c11

if HAVE_FAT_LTO_OBJECTS
LIB_CFLAGS += -ffat-lto-objects
endif

LIB_TEST_CFLAGS = -O0 -g -ftest-coverage -fprofile-arcs -std=c11 -I/opt/local/include
LDADD_TEST_FLAGS = -L. -lcfarmhash_test -lcmocka

AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS} -I m4

SOURCE_FILES = src/cfarmhash.c
HEADER_FILES = src/cfarmhash.h

lib_LTLIBRARIES= libcfarmhash.la
libcfarmhash_la_CFLAGS = $(LIB_CFLAGS)
libcfarmhash_la_LDFLAGS = -static
libcfarmhash_la_SOURCES = $(SOURCE_FILES) $(HEADER_FILES)

check_LIBRARIES = libcfarmhash_test.a
libcfarmhash_test_a_CFLAGS = $(LIB_TEST_CFLAGS)
libcfarmhash_test_a_SOURCES = $(SOURCE_FILES) $(HEADER_FILES)

BUILD_TESTS = test/test_cfarmhash

TESTS = $(BUILD_TESTS) test/test_coverage.sh

check_PROGRAMS = $(BUILD_TESTS)
check_SCRIPTS = test

test_test_cfarmhash_CFLAGS = $(LIB_TEST_CFLAGS)
test_test_cfarmhash_LDADD = $(LDADD_TEST_FLAGS)
test_test_cfarmhash_SOURCES = test/test_cfarmhash.c

mainheaderdir = $(includedir)
mainheader_HEADERS = src/cfarmhash.h

dist_man3_MANS = man/cfarmhash.3

dist_noinst_SCRIPTS = autogen.sh test/test_coverage.sh

CLEANFILES = {./,src,test}/*.{gcno,gcda,gcov}
MAINTAINERCLEANFILES = aclocal.m4 config.h.in configure Makefile.in libcfarmhash-*.tar.gz INSTALL

maintainer-clean-local:
	rm -rf autotools m4 libcfarmhash-0.1.0
