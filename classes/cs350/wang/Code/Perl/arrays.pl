#!/usr/bin/perl

# demonstrate some basic array operations of Perl, including slices
# cmpsc 350

# create an array 
@animals = ('zebra', 'cat', 'snake', 'dog','elephant','frog','bear');   
print "\n\n\noriginal array:\t\t @animals\n";                  

# subscript to access a scalar
print "element0:\t\t $animals[0]\n";                  

# slice even elements 
print "slice evens:\t\t @animals[0,2,4,6]\n";          

# slice the middle 3 elements 
print "slice middle:\t\t @animals[2..4]\n";          

# shift off the first element
$an_animal = shift(@animals);
print "shift one:\t\t$an_animal   new array: @animals\n";

# sort and print the array 
print "Sort:\t\t\t", join(' ', sort @animals),"\n";          

# reverse and print the array 
print "Reverse:\t\t",  join(' ', reverse @animals),"\n";          
 

