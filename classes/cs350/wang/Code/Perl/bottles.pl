#!/usr/bin/perl
# Jim Menard     jimm@{bbn,io}.com     (617) 873-4326   http://www.io.com/~jimm/
# www.99-bottles-of-beer.net
$nBottles = $ARGV[0];
$nBottles = 100 if $nBottles eq '' || $nBottles < 0;

foreach (reverse(1 .. $nBottles)) {
    $s = ($_ == 1) ? "" : "s";
    $oneLessS = ($_ == 2) ? "" : "s";
    print "\n$_ bottle$s of beer on the wall,\n";
    print "$_ bottle$s of beer,\n";
    print "Take one down, pass it around,\n";
    print $_ - 1, " bottle$oneLessS of beer on the wall\n";
}
print "\n*burp*\n";
