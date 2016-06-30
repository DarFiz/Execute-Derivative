#! /usr/bin/perl
use warnings;


$/=undef;

$ww=<stdin>;

open miniwz ,"PochKowZc++Template.frm";

$mini=<miniwz>;



$mini=~s/dzialanie/$ww/gs;

#drukowanie do pliku
print "$mini";

