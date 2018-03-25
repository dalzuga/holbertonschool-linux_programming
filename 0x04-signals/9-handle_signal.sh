#!/bin/bash
trap "echo -e Nope" SIGABRT SIGIO SIGTERM
