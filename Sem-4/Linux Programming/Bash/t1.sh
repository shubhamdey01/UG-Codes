#!/bin/bash

echo 'passwd' :
read -s x
if [ $x == "shubham" ]; then
   echo 'correct password'
else
   echo 'incorrect password'
fi

