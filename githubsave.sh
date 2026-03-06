#!/bin/bash

if [ -z "$1" ]; then
    echo "Error: No commit message supplied."
    echo "Usage: ./push.sh \"Your commit message\""
    exit 1
fi

git init
git add .
git commit -m "$1"
git branch -M main

git remote remove origin 2>/dev/null
git remote add origin git@github.com:thatguywhodidnot/Nolancode.git

git push -u origin main --force