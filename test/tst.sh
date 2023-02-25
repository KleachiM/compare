#!/bin/sh
echo
echo "Testing: no specified files ... \c"
if ./compare > /dev/null
  then
    echo not ok # program work with not specified files
    ./compare
    exit 1
  else
    echo ok
fi

echo "Testing: not exist file 1 ... \c"
file1="nonExistFile1.txt"
file2="../test/OneEmptyFile/notEmptyFile.txt"
if ./compare > /dev/null $file1 $file2
  then
    echo not ok # program work with not existing file 1
    ./compare $file1 $file2
    exit 1
  else
    echo ok
fi

echo "Testing: not exist file 2 ... \c"
file1="../test/SameFiles/sameFile1.txt"
file2="nonExistFile2.txt"
if ./compare > /dev/null $file1 $file2
  then
    echo not ok # program work with not existing file 2
    ./compare $file1 $file2
    exit 1
  else
    echo ok
fi

echo "Testing: two empty files are equal ... \c"
file1="../test/EmptyFiles/emtpyFile1.txt"
file2="../test/EmptyFiles/emtpyFile2.txt"
if ./compare > /dev/null $file1 $file2
  then
    echo ok
  else
    echo not ok # Empty files not equal
    ./compare $file1 $file2
    exit 1
fi

echo "Testing: empty file not equal not empty file ... \c"
file1="../test/OneEmptyFile/emtpyFile.txt"
file2="../test/OneEmptyFile/notEmptyFile.txt"
if ./compare > /dev/null $file1 $file2
  then
    echo not ok # different file are equal
    ./compare $file1 $file2
    exit 1
  else
    echo ok
fi

echo "Testing: same singleline files are equal ... \c"
file1="../test/SameFiles/SingleLine/sameSingleLineFile1.txt"
file2="../test/SameFiles/SingleLine/sameSingleLineFile2.txt"
if ./compare > /dev/null $file1 $file2
  then
    echo ok
  else
    echo not ok # same singleline files aren't equal
    ./compare $file1 $file2
    exit 1
fi

echo "Testing: different singleline files aren't equal ... \c"
file1="../test/DifferentFiles/SingleLine/differentSingleLineFile1.txt"
file2="../test/DifferentFiles/SingleLine/differentSingleLineFile2.txt"
if ./compare > /dev/null $file1 $file2
  then
    echo not ok # different singleline files are equal
    ./compare $file1 $file2
    exit 1
  else
    echo ok
fi

echo "Testing: same multiline files are equal ... \c"
sameMultiLineFile1="../test/SameFiles/MultiLine/sameMultiLineFile1.txt"
sameMultiLineFile2="../test/SameFiles/MultiLine/sameMultiLineFile2.txt"
if ./compare > /dev/null $sameMultiLineFile1 $sameMultiLineFile2
  then
    echo ok
  else
    echo not ok # same multiline files aren't equal
    ./compare $sameMultiLineFile1 $sameMultiLineFile2
    exit 1
fi

echo "Testing: different multiline files aren't equal (first line) ... \c"
file1="../test/DifferentFiles/MultiLine/differentFirstLineFile1.txt"
file2="../test/DifferentFiles/MultiLine/differentFirstLineFile2.txt"
if ./compare > /dev/null $file1 $file2
  then
    echo not ok # different multiline files are equal
    ./compare $file1 $file2
    exit 1
  else
    echo ok
fi

echo "Testing: different multiline files aren't equal (last line) ... \c"
file1="../test/DifferentFiles/MultiLine/differentLastLineFile1.txt"
file2="../test/DifferentFiles/MultiLine/differentLastLineFile2.txt"
if ./compare > /dev/null $file1 $file2
  then
    echo not ok # different multiline files are equal
    ./compare $file1 $file2
    exit 1
  else
    echo ok
fi

echo
echo Result with files not equal on last line:
./compare $file1 $file2
echo
echo Result with same multiline files:
./compare $sameMultiLineFile1 $sameMultiLineFile2
echo
