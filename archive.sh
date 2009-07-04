#!/bin/sh

if [ x"$1" = x ] ; then
  echo "Usage : archive.sh version"
  exit 1
fi

echo "aclocal -I m4"
aclocal -I m4

echo automake
automake

echo "autoheader"
autoheader

echo "autoconf"
autoconf

echo "removing *~"
find . -name '*~' -exec rm -f {} \;

echo "tar"
cd ..
tar cfz ebview-$1.tar.gz ebview-$1

echo "done"
