#!/bin/bash
if [ "$#" -ne 1 ];
then
    echo "Usage: $0 <pid>"
else
    PID=$1
    kill -SIGQUIT $PID
fi
