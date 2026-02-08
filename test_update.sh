#!/usr/bin/env bash

echo "=========================================="
echo "DSA Auto-Commit Script Test Suite"
echo "=========================================="
echo ""

SCRIPT_PATH="/media/ihtgoot/toshiba_ext/DataStructureAndAlgorithm/DSA/update.sh"
REPO_DIR="/media/ihtgoot/toshiba_ext/DataStructureAndAlgorithm/DSA"
LOG_FILE="/media/ihtgoot/toshiba_ext/DataStructureAndAlgorithm/DSA/log.DSA"
ERROR_LOG="/tmp/dsa-error.log"
TEST_FILE="$REPO_DIR/test_auto_commit.txt"

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

print_success() {
    echo -e "${GREEN}✓ $1${NC}"
}

print_error() {
    echo -e "${RED}✗ $1${NC}"
}

print_info() {
    echo -e "${YELLOW}ℹ $1${NC}"
}

# Test 1: Check if script exists and is executable
echo "Test 1: Script exists and is executable"
if [ -x "$SCRIPT_PATH" ]; then
    print_success "Script is executable"
else
    print_error "Script is not executable"
    echo "Run: chmod +x $SCRIPT_PATH"
    exit 1
fi
echo ""

# Test 2: Check if repository directory exists
echo "Test 2: Repository directory exists"
if [ -d "$REPO_DIR" ]; then
    print_success "Repository directory found"
else
    print_error "Repository directory not found (external drive may not be mounted)"
    exit 1
fi
echo ""

# Test 3: Check if it's a git repository
echo "Test 3: Valid git repository"
cd "$REPO_DIR" || exit 1
if git rev-parse --git-dir > /dev/null 2>&1; then
    print_success "Valid git repository"
else
    print_error "Not a valid git repository"
    exit 1
fi
echo ""

# Test 4: Check git remote
echo "Test 4: Git remote configured"
if git remote -v | grep -q origin; then
    print_success "Git remote 'origin' configured"
    git remote -v | head -2
else
    print_error "No git remote configured"
    exit 1
fi
echo ""

# Test 5: Test "nothing to commit" scenario
echo "Test 5: Testing 'nothing to commit' scenario"
print_info "Running script with no changes..."
$SCRIPT_PATH
if tail -5 "$LOG_FILE" | grep -q "Nothing to commit"; then
    print_success "Script correctly detected no changes"
else
    print_error "Script didn't log 'Nothing to commit'"
fi
echo ""

# Test 6: Test with actual changes
echo "Test 6: Testing with actual file changes"
print_info "Creating test file..."
echo "Test run at $(date)" >> "$TEST_FILE"
sleep 2

print_info "Running script with changes..."
$SCRIPT_PATH

if [ $? -eq 0 ]; then
    print_success "Script executed successfully"
else
    print_error "Script failed with exit code $?"
    exit 1
fi
echo ""

# Test 7: Verify commit was made
echo "Test 7: Verify commit was made"
if git log -1 --pretty=format:"%s" | grep -q "update |"; then
    print_success "Commit found in git log"
    print_info "Last commit: $(git log -1 --pretty=format:'%s')"
else
    print_error "No commit found"
fi
echo ""

# Test 8: Verify push was successful
echo "Test 8: Verify push was successful"
LOCAL_COMMIT=$(git rev-parse main)
REMOTE_COMMIT=$(git rev-parse origin/main)

if [ "$LOCAL_COMMIT" = "$REMOTE_COMMIT" ]; then
    print_success "Local and remote are in sync"
else
    print_error "Local and remote are out of sync"
    print_info "Local: $LOCAL_COMMIT"
    print_info "Remote: $REMOTE_COMMIT"
fi
echo ""

# Test 9: Check log file
echo "Test 9: Check log file entries"
if [ -f "$LOG_FILE" ]; then
    print_success "Log file exists"
    print_info "Last 10 lines of log file:"
    echo "---"
    tail -10 "$LOG_FILE"
    echo "---"
else
    print_error "Log file not found"
fi
echo ""

# Test 10: Check error log
echo "Test 10: Check error log"
if [ -f "$ERROR_LOG" ]; then
    if [ -s "$ERROR_LOG" ]; then
        print_error "Error log has content (check for issues)"
        cat "$ERROR_LOG"
    else
        print_success "Error log exists but is empty (good)"
    fi
else
    print_success "No error log (no errors occurred)"
fi
echo ""

# Test 11: Simulate cron environment
echo "Test 11: Simulate cron environment"
print_info "Running script in minimal environment (like cron)..."
env -i HOME=$HOME PATH=/usr/bin:/bin $SCRIPT_PATH > /tmp/cron-test.log 2>&1

if [ $? -eq 0 ]; then
    print_success "Script works in cron-like environment"
else
    print_error "Script failed in cron environment"
    cat /tmp/cron-test.log
fi
echo ""

# Test 12: Clean up test file
echo "Test 12: Cleanup"
print_info "Removing test file..."
rm -f "$TEST_FILE"
git add .
git commit -m "cleanup: remove test file" > /dev/null 2>&1
git push origin main > /dev/null 2>&1
print_success "Cleanup complete"
echo ""

# Summary
echo "=========================================="
echo "Test Suite Complete!"
echo "=========================================="
echo ""
echo "Next steps:"
echo "1. Review the test results above"
echo "2. Check your crontab: crontab -l"
echo "3. Monitor the logs: tail -f $LOG_FILE"
echo "4. For cron testing, temporarily set it to run every minute:"
echo "   * * * * * $SCRIPT_PATH >> /tmp/dsa-cron.log 2>&1"
echo ""