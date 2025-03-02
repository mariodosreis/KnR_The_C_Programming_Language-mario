# Exercise 1-11. How would you test the word count program? What kinds of
# input are most likely to uncover bugs if there are any?

cc -std=c89 wc.c

echo "Mary had so many lambs
that she did NOT	KNOW
what to do with them!" | ./a.out
