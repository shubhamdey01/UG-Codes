#!/bin/bash
cut -f 1-2 -d ' ' cut_join_ex_data_file.txt | tee f12.txt
echo "1st and 2nd colums cut"
sleep 1
cut -f 1,3-4 -d ' ' cut_join_ex_data_file.txt | tee f134.txt
echo "1st and 3-4 columns cut"
sleep 1
sort f12.txt > f12s.txt
sort f134.txt > f134s.txt
join f12s.txt f134s.txt > joined.txt
cat joined.txt
