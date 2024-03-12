#!/bin/bash

# docs.sh: bash script gets documentation from top of C file (where
# i put my references) by searching for the first occurance of a 
# given keyword which is passed as the first argument to this program
# and prints it to the stdout using sed.
# the hardcoded path /avl.c requires this script to be in algo/avl.c .
# this will probably only work if you forked /algo and are using unix 
# filesystem.

# Usage: bash docs.sh <query>
# example: bash docs.sh avl_insert

function lineNumber() {
  return $(cat ./avl.c | grep "${1}" -m 1 -n | cut -d: -f1)
}
if [[ -z $1 ]]; then
  echo "Usage: bash docs <query>"
else
  lineNumber $1 # get line number
  sed -n "${?},/-/p" ../avl/avl.c # get the docs
fi
