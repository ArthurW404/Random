#!/bin/sh
link="https://www.cse.unsw.edu.au/~cs1521/19T2/lectures/"
i=0
while test $i -lt 10
do
    curl "${link}week0$i/notes.html"
    curl "${link}week0$i/index.html"
    i=$(expr $i + 1)
done

curl "${link}week10/notes.html"
curl "${link}week10/index.html"
