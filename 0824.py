class Solution:
    def toGoatLatin(self, S: str) -> str:
        words = S.split(' ')
        vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        for i in range(len(words)):
            w = words[i]
            if w[0] in vowels:
                w += "ma"
            else:
                w = w[1:] + w[0] + "ma"
            w += (i + 1) * 'a'
            words[i] = w
        return ' '.join(words)