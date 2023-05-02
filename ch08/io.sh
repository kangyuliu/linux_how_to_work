#!/bin/bash
fori in 4 8 16 32 64 128 256 512 1024 2048 4096; do
    time ./io /dev/vda1 off r seq $i;
done