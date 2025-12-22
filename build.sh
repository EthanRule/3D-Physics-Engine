#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
mkdir -p "$SCRIPT_DIR/Engine/build"
cd "$SCRIPT_DIR/Engine/build" && cmake .. && make && ./3DPhysicsEngine
