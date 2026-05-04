$REPO = "git@github.com:thatguywhodidnot/Nolancode.git"

# initialize repo if not already
if (!(Test-Path ".git")) {
    git init
}

# ensure correct remote
git remote remove origin 2>$null
git remote add origin $REPO

# ensure branch
git branch -M main

# fetch and pull latest changes
git fetch origin
git pull origin main

