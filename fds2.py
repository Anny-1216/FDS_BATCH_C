print("Assignment-2 (String Operations)") 
sentence = input("Enter sentence: ")

# Find the longest word
longest_word = max(sentence.split(), key=len)
print("Longest word is:", longest_word)
print("And its length is:", len(longest_word))

# Count the frequency of each character
char_frequency = {}
for char in sentence:
    char_frequency[char] = char_frequency.get(char, 0) + 1

print("Count of all characters in the sentence:\n" + str(char_frequency))

#charcter frequency
char_freq = []
for i in sentence:
    char_freq.append(i)

# Check if a given text is a palindrome
text = input("Enter text to check for palindrome: ")
if text == text[::-1]:
    print("It's a palindrome")
else:
    print("It's not a palindrome")

# Find the index of a substring
substring = input("Enter substring to find its index: ")
substring_index = sentence.find(substring)
if substring_index == -1:
    print("Substring not found")
else:
    print("Index of the substring is:", substring_index)
chara=sentence.split(",")
print(chara)
for i in substring:
    chara.append(i)
if i in chara:
        print("Substring found at index :-",i)
else:
    print("Substring not found !")

# Count the frequency of each word in the sentence
def word_frequency(sentence):
    words = sentence.split()
    unique_words = set(words)
    for word in unique_words:
        print(f"Count of frequency '{word}' is:", words.count(word))

print("Following are the counts of frequency of each word in the given sentence:")
word_frequency(sentence)
