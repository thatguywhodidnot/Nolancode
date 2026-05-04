#!/bin/bash

<<<<<<< HEAD

git pull origin main
=======
REPO="git@github.com:thatguywhodidnot/Nolancode.git"

# initialize repo if not already
if [ ! -d ".git" ]; then
    git init
fi

# ensure correct remote
git remote remove origin 2>/dev/null
git remote add origin $REPO

# ensure branch
git branch -M main

# fetch and pull latest changes
git fetch origin
git pull origin main
>>>>>>> 992cc8f70e55463e38447557478bf8af311e425f
