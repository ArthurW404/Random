import sys

input = sys.stdin
output = sys.stdout

words = input.read().split()
input.close()

for word in words:
    print 
    if not isinstance(word, int):
        
        exit(1)
    else:
        if (word % 2 == 1):
            exit(1)
output.write("Wow")
output.close()
exit(0)