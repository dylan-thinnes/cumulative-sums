#!/usr/bin/env -S awk -f
{ x += $0; print $1 " " x }
