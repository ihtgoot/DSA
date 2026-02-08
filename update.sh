#!/usr/bin/env bash
set -euo pipefail

LOG_FILE="/media/ihtgoot/toshiba_ext/DataStructureAndAlgorithm/DSA/log.DSA"
REPO_DIR="/media/ihtgoot/toshiba_ext/DataStructureAndAlgorithm/DSA"
ERROR_LOG="/tmp/dsa-error.log"

if [ ! -d "$REPO_DIR" ]; then
    echo "$(date '+%F %H:%M:%S') - Repository directory not found. External drive may not be mounted." >> "$ERROR_LOG"
    exit 1
fi

cd "$REPO_DIR" || { 
    echo "$(date '+%F %H:%M:%S') - Failed to cd into $REPO_DIR" >> "$ERROR_LOG"
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

# Stash any uncommitted changes before pulling
git stash --include-untracked || true

git pull --rebase origin main

# Reapply stashed changes if any
git stash pop || true

git push origin main