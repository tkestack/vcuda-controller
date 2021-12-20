#!/usr/bin/env bash

set -o errexit
set -o nounset
set -o pipefail

CUDA_LIBRARY=$1
ML_LIBRARY=$2

echo "find new library"

while read item; do
  grep -q ${item} include/cuda-helper.h || echo "$item,"
done < <(nm -D ${CUDA_LIBRARY} | grep " T " | awk '{print "CUDA_ENTRY_ENUM("$3")"}')

echo ""

while read item; do
  grep -q ${item} include/nvml-helper.h || echo "$item,"
done < <(nm -D ${ML_LIBRARY} | grep " T " | awk '{print "NVML_ENTRY_ENUM("$3")"}')
