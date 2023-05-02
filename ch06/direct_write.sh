#!/bin/bash
rm -f testfile
time dd if=/dev/zero of=testfile oflag=direct bs=1M count=1K
rm -f testfile