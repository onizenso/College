#!/usr/bin/env ruby
# Yet another anagram checker by Matthew Elder <sseses@gmail.com>

# extend string to sort the way I want
class String
  def sort
    # unpack ascii ints into array
    unpack('C*').sort.to_s

    # split into single character strings
    # more intuitive, but slower
    # split('').sort.to_s
  end
end

def anagram?(word1, word2)
  word1.downcase.sort == word2.downcase.sort
end

puts "Anagram check (enter two words separated by a space):"
puts "anagram?(): #{anagram? *gets.split(' ')}"

