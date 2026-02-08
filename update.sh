#!/usr/bin/env bash
set -euo pipefail

REPO_DIR="/media/ihtgoot/toshiba_ext/DataStructureAndAlgorithm/DSA"
cd "$REPO_DIR" || {
    echo "Failed to cd into $REPO_DIR"
    exit 1
}

NOW=$(date '+%F %H:%M:%S')

STATUS=$(git status)

echo "$NOW"
echo "$STATUS"
git add .

git diff --cached --quiet && {
    echo "Nothing to commit"
    exit 0
} 

message="update | $NOW"
body="$STATUS"

git commit -m "$message" -m "$body"

git push origin main