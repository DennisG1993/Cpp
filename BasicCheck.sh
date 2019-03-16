#!/bin/bash
#this script sends stdout and stderr to /dev/null. im doing it since the requested output didnt include those.
dirpath=$1
progname=$2
shift 2 #it means that $3 is $1 now and so on, this way i dont need to cut arguments later on.
currpath=`pwd`
cd $dirpath

make 2>/dev/null 1>/dev/null
makesucc=$?

if [ $makesucc -ne 0 ]
then
  echo "Compilation  Memory leaks  Thread race"
  echo "   FAIL          FAIL          FAIL   "
  cd "$currpath" 1>/dev/null
  exit 7 #since make failed it means that val and hel also failed hence the number 111 in binary hence 7 in decimal.
else
  #i can use those both valgrinds with ./$progname and it will work because of cd $dirpath command beforehand but better safe than sorry hence the $dirpath/$progname
  valgrind --error-exitcode=2 --leak-check=full --show-leak-kinds=all  ./$progname $@ 2>/dev/null 1>/dev/null  #im using full leak check and show all kinds so that i wouldn't miss any leak.
  valsucc=$?

  valgrind --tool=helgrind --error-exitcode=1  ./$progname $@ 2>/dev/null 1>/dev/null
  helsucc=$?

  exitcode=$((helsucc+valsucc)) #i specifically set error exit code on val and hel to 2 and 1 so that me exit codes will be the same as the exercises demands.


case "$exitcode" in
  "0")
    echo "Compilation  Memory leaks  Thread race"
    echo "   PASS          PASS          PASS   "
    cd "$currpath" 1>/dev/null
    exit $exitcode
    ;;
  "1")
    echo "Compilation  Memory leaks  Thread race"
    echo "   PASS          PASS          FAIL   "
    cd "$currpath" 1>/dev/null
    exit $exitcode
    ;;
  "2")
    echo "Compilation  Memory leaks  Thread race"
    echo "   PASS          FAIL          PASS   "
    cd "$currpath" 1>/dev/null
    exit $exitcode
    ;;
  "3")
    echo "Compilation  Memory leaks  Thread race"
    echo "   PASS          FAIL          FAIL   "
    cd "$currpath" 1>/dev/null
    exit $exitcode
    ;;
  esac
fi
