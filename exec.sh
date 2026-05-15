#!/usr/bin/env bash

set -euo pipefail

readonly BIN_DIR="./build"
readonly TARGET="main"
readonly CC="clang"

readonly FLAGS=(
    -Wall
    -Wextra
    -Werror
    -Wpedantic
    -O2
)

SRCS=( ./src/*.c )

if [[ ! -e "${SRCS[0]}" ]]; then
    echo "No source files found"
    exit 1
fi

mkdir -p "${BIN_DIR}"

"${CC}" \
    "${FLAGS[@]}" \
    "${SRCS[@]}" \
    -o "${BIN_DIR}/${TARGET}"

exec "./${BIN_DIR}/${TARGET}"
