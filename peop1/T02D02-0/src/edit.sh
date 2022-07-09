#!/bin/bash
filename=$1
search=$2
replace=$3

#ATTENTION filename means full route directionary.

if [[ $filename != "" && $search != "" && replace != "" ]]; then
sed "s/$search/$replace/" $filename
echo "$filename - $(wc -c $filename | awk '{print  $1}' ) - $(date -r $filename "+%Y-%m-%d %H:%M") - $(shasum -a 256 $filename | awk '{print $1}') - sha256" >> files.log
fi

