#!/bin/bash

sudo apt-get update
sudo apt-get install -y clang-12 clang-tidy-12 python3
sudo python3 -m pip install -U pip
sudo python3 -m pip install cpplint
