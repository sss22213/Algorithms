#!/bin/bash
time1=$(date +%N)/1000
./$1
time2=$(date +%N)/1000
echo $(($time2-$time1))

