#!/bin/bash

GITROOT=`git rev-parse --show-toplevel`
find $GITROOT -type f -exec git check-ignore {} +

