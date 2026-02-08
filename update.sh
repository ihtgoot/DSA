#!/usr/bin/env bash
set -euo pipefail

REPO_DIR="/media/ihtgoot/toshiba_ext/DataStructureAndAlgorithm/DSA"
cd "$REPO_DIR" || {
    echo "Failed to cd into $REPO_DIR"
    exit 1
}

NOW=$(date '+%F %H:%M:%S')

STATUS1=$(git status)
STATUS2=$(git add .)

echo "$NOW"
echo "----------------------------------------------"
echo "$STATUS1"
echo
echo "$STATUS2"
echo 
echo

git diff --cached --quiet && {
    echo "Nothing to commit"
    exit 0
} 

message="update | $NOW"
body="$STATUS1"+"$STATUS2"

git commit -m "$message" -m "$body"

git push origin main