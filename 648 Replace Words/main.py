from typing import List


class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        # Convert dictionary to a set for faster lookup
        root_set = set(dictionary)

        # Split the sentence into words
        words = sentence.split()

        # Process each word in the sentence
        for i in range(len(words)):
            word = words[i]
            for j in range(1, len(word) + 1):
                if word[:j] in root_set:
                    words[i] = word[:j]
                    break

        # Join the words back into a sentence
        return " ".join(words)
