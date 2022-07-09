#!/bin/bash
filename=$1

count=0
countforhash=0
while read p; do
  count=$(($count + 1))
done < $filename

something=$(awk '{print $1}' $filename | sort | uniq | wc -l)

something2=$(awk '{print $3}' $filename | sort | uniq | wc -l )

echo $count $something $something2
