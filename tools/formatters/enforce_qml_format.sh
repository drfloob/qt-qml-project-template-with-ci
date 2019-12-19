#!/bin/bash

#
# Copyright (c) 2020, 219 Design, LLC
# See LICENSE.txt
#
# https://www.219design.com
# Software | Electrical | Mechanical | Product Design
#

set -Eeuxo pipefail # https://vaneyckt.io/posts/safer_bash_scripts_with_set_euxo_pipefail/

THISDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
CUR_GIT_ROOT=$(git rev-parse --show-toplevel)

only_report=0
if [[ -n ${1-} ]]; # the presence of ANY arg makes this 'C.I.' mode (no editing files)
then
    only_report=1
fi

qml_formatter="${CUR_GIT_ROOT}/build_qt_binaries/qmlfmt_install/qmlfmt"

check_format() {
  if [ $only_report != 0 ]; then
      while read filenames; do
        for fl in "$filenames"; do
          result=$("$qml_formatter" -l "$fl")
          if [[ ! -z "$result" ]]; then
              echo "You need to qmlfmt this file:"
              echo "$fl"
              return -1
          fi
        done
      done

      return 0
  fi

  while read filenames; do
    for fl in "$filenames"; do
      echo $fl
      "$qml_formatter" -w "$fl"
    done
  done
}

cd $CUR_GIT_ROOT
top_level_dirs=(*/)

for dir in "${top_level_dirs[@]}"; do
  if [ -f "${dir}/.git" ]; then
      echo "Refusing to format ${dir} - it appears to be a submodule."
  elif [ -f "${dir}/.do_not_format" ]; then
      echo "Refusing to format ${dir} - you marked it .do_not_format"
  else
    # leaving the '-o' construct for future expansion guidance:
    find ${dir} \
         \( -name '*.qml' \
         -o -name '*.qml' \) \
         | check_format
  fi
done

echo 'We assume this was run with '\''set -x'\'' (look at upper lines of this script).'
echo 'Assuming so, then getting here means:'
echo 'SUCCESS'
