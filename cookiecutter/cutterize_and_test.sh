#!/bin/bash

#
# Copyright (c) 2020, 219 Design, LLC
# See LICENSE.txt
#
# https://www.219design.com
# Software | Electrical | Mechanical | Product Design
#

set -Eeuxo pipefail # https://vaneyckt.io/posts/safer_bash_scripts_with_set_euxo_pipefail/

git config --global user.name "Workflow Worker"
git config --global user.email "nobody@219design.com"

cd $GITHUB_WORKSPACE
echo "HELLO WORLD" >> README.md
git add .
git checkout -b qt_cookiecutter
git commit -m "cookiecutterized invocation($INVOCATION_ID)"

remote_repo="https://${COOKIECUTTER_PUSH_USER}:${COOKIECUTTER_PUSH_TOKEN}@github.com/${GITHUB_REPOSITORY}.git"

git push "${remote_repo}" HEAD:test --force 
