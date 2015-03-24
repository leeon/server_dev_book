#!/bin/bash

#author @atleeon
#2014.08.13
#Simple guide for bash learner

###########################
#
# 0.Hello
#
##########################

# each command start with a new line or  ;
echo "This is your first step in Shell :-)"

###########################
#
# 1.Variables
#
##########################

#write a var
#Notice:no space allowed between name and `=`, or shell will take it as a command
name="leeon"
duration=10

#read a var by ${var}
echo "My name is ${name}, and I will learn Shell with you."
echo "It may take you ${duration} minutes."

#use 'readonly' to make a var const
readonly name

#use 'unset' to delete a var
unset duration

#there are some special vars that you can use directly
echo "Here are some special vars in Shell"
echo $$ #current pid
echo $0 #current file name
echo $1 #first parameter
echo $# #number of parameters
echo $* #all parameters
echo $? #exit code of last thread

# Strings can be wrapped by " or '
# ' will transfer everything to a normal string
# " will keep $ and \ the special meaning
str="string is important."
#and you can concat strings like this
echo "Of course, "$str
echo "We can get length of a string "${#str}
echo "We can also get subString of str, the 1~10 char is ' ${str:1:10} ' "

#Items in Arrays are seperated by space
#and there is no limit of array size
arr=("Mon" "Tue" "Wed" "Thu" "Fri" "Sat" "Sun")
echo "The first day of a week is ${arr[0]}"
echo "${#arr[*]} days are ( ${arr[*]})"




##################
#
# 2. Control
#
##################


# if [ ]