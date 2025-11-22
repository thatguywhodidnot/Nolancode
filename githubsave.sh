

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
git remote add origin https://github.com/thatguywhodidnot/Nolancode.git
git push -u origin main --force

