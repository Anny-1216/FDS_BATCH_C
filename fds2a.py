sentence  = input("Enter a sentence : ")

longword  = max(sentence.split(),key=len)
print("The longest word is ",longword," and its length is ",len(longword))

char_freq = {}
for char in sentence:
    char_freq[char] = char_freq.get(char,0) + 1

word_freq = {}
words     = sentence.split() 
for word in words:
    word_freq[char] = word_freq.get(char,0) + 1
print(word_freq)

palindrome = input("Enter the word to check palindrome : ")
if palindrome == palindrome[::-1]:
    print("The word is a palindrome.")
else:
    print("Its not a palindrome.")

substr    = input("Enter a substring to find :")
a         = sentence.find(substr)
if a != -1:
    print("Substring found at position ",a)

else:
    print("Element not found!")
