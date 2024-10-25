#!/bin/bash

TIMEOUT_VAL=300

timeout ${TIMEOUT_VAL} ./run_tests.sh &> result

if [ ! $? -eq 0 ]
then
    echo "TIMEOUT. Tests exceeded maximum allowed time of $TIMEOUT_VAL" >> result
fi

# Run linters
echo -e "\nRun cpplint\n" >> result
cpplint --filter=-legal/copyright,-readability/casting *.c &>> result

echo -e "\nRun clang-tidy-12\n" >> result
clang-tidy-12 -header-filter='.*'  -checks='-*,cppcoreguidelines*' *.c -- &>> result

# Display run summary
awk -f parse.awk result

# Display detailed report
echo -e "\n==================="
echo -e "= Detailed report ="
echo -e "===================\n"
cat result
