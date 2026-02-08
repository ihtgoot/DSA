#!/usr/bin/env bash
set -euo pipefail

NOW=$(date '+%F %H:%M:%S')

STATUS=$(git status)

echo "$NOW"
echo "$STATUS"
git add .

git diff --cached --quiet && {
    echo "Nothing to commit"
    exit 0
} 

message="update | $NOW | $STATUS"

git commit -m "$message"

git push origin main