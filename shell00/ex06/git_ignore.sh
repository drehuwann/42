#!/bin/bash

GITROOT=`git rev-parse --path-format=relative --show-toplevel`
find $GITROOT -type f -exec git check-ignore {} +

