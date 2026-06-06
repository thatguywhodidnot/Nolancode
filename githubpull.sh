#!/bin/bash

REPO="git@github.com:thatguywhodidnot/Nolancode.git"

if [ ! -d ".git" ]; then
    git init
fi

git remote remove origin 2>/dev/null
git remote add origin "$REPO"

git branch -M main

git fetch origin
git pull origin main
