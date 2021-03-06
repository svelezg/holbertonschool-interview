# Shortest Palindrome
Given a string `s`, convert it to the shortest palindrome possible by adding characters to the beginning of the string.

Examples:
- "aacecaaa" -> "aaacecaaa"
- "abcd" -> "dcbabcd"

What you don’t tell the candidate, but answer her/him when she/he asks for clarification:
- "" is considered a palindrome
- "a" is considered a palindrome
- You can assume the string only contains lowercase letters

##Instructions:

###Brute force
According to the question, we are allowed to insert the characters only at the beginning of the string. 
Hence, we can find the largest segment from the beginning that is a palindrome, and we can then easily reverse the remaining segment and append to the beginning. This must be the required answer as no shorter palindrome could be found than this by just appending at the beginning.
For example: 
Take the string "abcbabcab". 
Here, the largest palindrome segment from the beginning is "abcba", and the remaining segment is "bcab". 
Therefore, the required string is the reverse of "bcab"( = "bacb") + the original string( = "abcbabcab"). 
This gives "bacbabcbabcab".
Code implementation in Python:
```
def shortestPalindrome(s):

    n = len(s)
    if n < 2:
        return s
    rev = s[::-1]
    for i in range(n):
        if s[:n-i] == rev[i:]:
            return rev[:i] + s
    return ""
```
Follow-up questions:
- What is the time complexity of this algorithm? `O(n^2)` (We iterate over the entire length of string. In each iteration, we compare the substrings which is linear in size of substrings to be compared.)
- What is the space complexity of this algorithm? `O(n)`
- Can you find a faster solution?
Score: If this is the best solution the candidate can find: max 40%

##Two pointers and recursion
In the brute force approach, we found the largest palindrome substring using substring matching which is O(n) in length 
of the substring. We could make the process more efficient if we could reduce the size of string to search for the 
substring without checking the complete substring each time.
Lets take a string "abcbabcaba". Let us consider 2 pointers i and j. Initialize i = 0. Iterate over j from n-1 to 0, 
incrementing i each time `s[i]==s[j]`. Now, we just need to search in `range [:i-1]`. This way, we have reduced the size of 
string to search for the largest palindrome substring from the beginning. The `range [:i-1]` must always contain the largest 
palindrome substring.
Code implementation in Python:
```
def shortestPalindrome(s):

    n = len(s)
    if n < 2:
        return s
    i = 0
    for j in range(n - 1, -1, -1):
        if s[i] == s[j]:
            i += 1
    if i == n:
        return s 
    rev = s[n-1:i-1:-1]
    return rev + shortestPalindrome(s[:i]) + s[i:]
```
Follow-up questions:
- What is the time complexity of this algorithm? `O(n^2)`
- What is the space complexity of this algorithm? `O(n)`
- Can you find a faster solution?
Score: If this is the best solution the candidate can find: max 60%


##Failure Lookup Table (KPM)
KMP is a string matching algorithm that runs in O(n+m) time, where n and m are sizes of the text and string to be 
searched respectively. The key component of KMP is the failure function lookup table, say f(s). The purpose of the 
lookup table is to store the length of the proper prefix of the string s that is also a suffix ofsx. This table is 
important because if we are trying to match a text string n and we have matched the first s positions but fail, then 
the value of lookup table for s is the longest prefix of n that could possibly match the text string upto the point 
we are at. Thus, we don't need to start all over again, and can resume searching from the matching prefix.
In Brute force, we reserved the original string s and stored it as rev. We iterate over i from 0 to n−1 and check 
for s[0:n-i] == rev[i:]. Pondering over this statement, had the rev been concatenated to s, this statement is just 
finding the longest prefix that is equal to the suffix.
Code implementation in Python:
```
def shortestPalindrome(s):

    n = len(s)
    rev = s[::-1]
    s_new = "{}#{}".format(s, rev)
    n_new = len(s_new)
    f = [0] * n_new
    for i in range(1, n_new):
        t = f[i - 1]
        while t > 0 and s_new[i] != s_new[t]:
            t = f[t - 1]
        if s_new[i] == s_new[t]:
            t += 1
        f[i] = t
    return rev[0:(n - f[n_new - 1])] + s
```        
Follow-up questions:
- What is the time complexity of this algorithm? O(n)`
- What is the space complexity of this algorithm? `O(n)`
Score: If this is the best solution the candidate can find: max 100%
