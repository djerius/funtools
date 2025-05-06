#! /bin/env perl

use v5.10;
use B 'cstring';

use strict;
use warnings;

my $name = shift @ARGV;

my $add_comma = 0;
my $buf;

my @bufs;
while ( read( STDIN, $buf, 1024 ) ) {
    push @bufs, cstring($buf);
}
my $nbufs = @bufs;

say <<EOS

#include "chunked.h"

ChunkedString $name = {
  $nbufs,
  { @{[ join ",\n", @bufs ]} }
};
EOS

