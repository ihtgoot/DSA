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

# Add all changes first (excluding log file for now)
git add .

# Check if there are any staged changes (excluding log.DSA)
if git diff --cached --quiet -- . ':!log.DSA'; then
    # No changes except possibly log.DSA
    {
        echo "$NOW"
        echo "----------------------------------------------"
        echo "Nothing to commit"
        echo "----------------------------------------------"
    } >> "$LOG_FILE"
    exit 0
fi

# Get status for logging
STATUS1=$(git status)
STATUS2=$(git diff --cached --stat)

# Write to log file BEFORE committing so it gets included in the commit
{
    echo "$NOW"
    echo "----------------------------------------------"
    echo "$STATUS1"
    echo
    echo "$STATUS2"
    echo
    echo "----------------------------------------------"
} >> "$LOG_FILE"

# Add the log file to this commit
git add "$LOG_FILE"

message="update | $NOW"
body="$STATUS1"$'\n\n'"$STATUS2"

# Commit everything including the log
if ! git commit -m "$message" -m "$body"; then
    echo "$(date '+%F %H:%M:%S') - Git commit failed" >> "$ERROR_LOG"
    exit 1
fi

# Pull with rebase
if ! git pull --rebase origin main 2>&1 | grep -q "up to date"; then
    # Only log if it's NOT "already up to date"
    if [ ${PIPESTATUS[0]} -ne 0 ]; then
        echo "$(date '+%F %H:%M:%S') - Git pull failed" >> "$ERROR_LOG"
    fi
fi

# Push changes
if ! git push origin main; then
    echo "$(date '+%F %H:%M:%S') - Git push failed" >> "$ERROR_LOG"
    exit 1
fi