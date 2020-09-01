#!/usr/bin/perl -w

$davidGay = "DavidGay";
@davidGay = qw/David Gay/;
%davidGay = ("david" => "gay", 0 => "david Gay nuts");
print $davidGay, " ", $davidGay[0], " ", $davidGay{"david"}, " ", $davidGay{0},;