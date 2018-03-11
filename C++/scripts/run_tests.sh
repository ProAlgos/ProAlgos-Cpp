#!/bin/bash

exit_code=0

for test in $(ls bin)
do
    printf '\n%s:\n' ${test}
    time bin/${test}
    if [ $? != 0 ]      # test failed
    then
        exit_code=1
    fi
done

exit ${exit_code}
