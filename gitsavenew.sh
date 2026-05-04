#!/bin/bash

if [ -z "$1" ]; then
    echo "Error: No commit message supplied."
    echo "Usage: ./push.sh \"Your commit message\""
    exit 1
fi

REPO_SSH="git@github.com:thatguywhodidnot/Nolancode.git"
REPO_HTTPS="https://github.com/thatguywhodidnot/Nolancode.git"

git init
git add .

if git diff --cached --quiet; then
    echo "No changes to commit."
else
    git commit -m "$1"
fi

git branch -M main

git remote remove origin 2>/dev/null
git remote add origin "$REPO_SSH"

echo "Trying to push using SSH..."
if git push origin main; then
    echo "Push successful using SSH."
    exit 0
fi

echo "SSH push failed. Switching to HTTPS..."
git remote set-url origin "$REPO_HTTPS"

echo "Trying to push using HTTPS..."
if git push origin main; then
    echo "Push successful using HTTPS."
else
    echo "Error: HTTPS push also failed."
    exit 1
fi
