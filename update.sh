#!/usr/bin/env bash
set -euo pipefail

LOG_FILE="/media/ihtgoot/toshiba_ext/DataStructureAndAlgorithm/DSA/log.DSA"
REPO_DIR="/media/ihtgoot/toshiba_ext/DataStructureAndAlgorithm/DSA"
cd "$REPO_DIR" || {
    echo "Failed to cd into $REPO_DIR"
    exit 1
}

NOW=$(date '+%F %H:%M:%S')

STATUS1=$(git status)
git add .

if git diff --cached --quiet; then
    {
        echo "$NOW"
        echo "----------------------------------------------"
        echo "Nothing to commit"
        echo "----------------------------------------------"
    } >> "$LOG_FILE"
    exit 0
fi

STATUS2=$(git diff --cached --stat)

{
    echo "$NOW"
    echo "----------------------------------------------"
    echo "$STATUS1"
    echo
    echo "$STATUS2"
    echo
    echo "----------------------------------------------"
} >> "$LOG_FILE"


message="update | $NOW"
body="$STATUS1"$'\n\n'"$STATUS2"

git commit -m "$message" -m "$body"
git pull --rebase origin main
git push origin main