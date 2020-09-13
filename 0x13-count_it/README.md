# 0x13\. Count it!

## Authors
* **Solution:** Santiago Vélez G. [svelez.velezgarcia@gmail.com](svelez.velezgarcia@gmail.com) [@svelezg](https://github.com/svelezg)
* **Problem statement:** Alexa Orrico [Holberton School](https://www.holbertonschool.com/)


## Requirements

### General

*   Allowed editors: `vi`, `vim`, `emacs`
*   All your files will be interpreted/compiled on Ubuntu 14.04 LTS using `python3` (version 3.4.3)
*   All your files should end with a new line
*   The first line of all your files should be exactly `#!/usr/bin/python3`
*   Libraries imported in your Python files must be organized in alphabetical order
*   A `README.md` file, at the root of the folder of the project, is mandatory
*   Your code should use the `PEP 8` style
*   All your files must be executable
*   The length of your files will be tested using `wc`
*   All your modules should have a documentation (`python3 -c 'print(__import__("my_module").__doc__)'`)
*   You must use the Requests module for sending HTTP requests to the Reddit API



* * *

## Tasks



#### 0\. Count it! 

Write a _recursive function_ that queries the [Reddit API](/rltoken/PV_GanilbTliu3BSqFKPKA "Reddit API"), parses the title of all hot articles, and prints a sorted count of given keywords (case-insensitive, delimited by spaces. Javascript should count as javascript, but java should not).

Requirements:

*   Prototype: `def count_words(subreddit, word_list)`
*   Note: You may change the prototype, but it must be able to be called with just a subreddit supplied and a list of keywords. AKA you can add a counter or anything else, but the function must work without supplying a starting value in the main.
*   Results should be printed in descending order, by the count, not the title. Words with no matches should be skipped and not printed.
*   Results are based on the number of times a keyword appears, not titles it appears in. ‘java java java’ counts as 3 separate occurences of java.
*   To make life easier, ‘java.’ or ‘java!’ or ‘java_’ should not count as ‘java’
*   If no posts match or the subreddit is invalid, print a newline.
*   NOTE: Invalid subreddits may return a redirect to search results. Ensure that you are NOT following redirects.

Your code will NOT pass if you are using a loop and not recursively calling the function! This _can_ be done with a loop but the point is to use a recursive function. :)

    alexa@ubuntu:~/0x13-count_it $ cat 0-main.py 
    
    alexa@ubuntu:~/0x13-count_it $ ./0-main.py programming 'python java javascript scala no_results_for_this_one'
    java: 27
    javascript: 20
    python: 17
    scala: 4
    alexa@ubuntu:~/0x13-count_it $ ./0-main.py not_a_valid_subreddit 'python java javascript scala no_results_for_this_one'
    alexa@ubuntu:~/0x13-count_it $ ./0-main.py not_a_valid_subreddit 'python java'
    alexa@ubuntu:~/0x13-count_it $ 

**Repo:**

*   GitHub repository: `holbertonschool-interview`
*   Directory: `0x13-count_it`
*   File: `0-count.py`
