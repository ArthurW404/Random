# generating numbers based on stdin
# argument 1 is whether there is repetition or not in the generated sequence of numbers

import sys
import random
import datetime

def no_rep_random(input):
    nums = [i for i in range(input)]
    random.shuffle(nums)
    return nums

def rep_random(input):
    nums = []
    k = input % 32 + 1
    for i in range(input):
        nums.append(random.getrandbits(k))
    return nums

def main():
    if len(sys.argv) != 3:
        print("argument 1: no_rep | rep")
        print("argument 2: a number")
        return 
    is_rep = sys.argv[1]
    input = int(sys.argv[2])
    nums = []
    if is_rep == "rep":
        nums = rep_random(input)
    elif is_rep == "no_rep":
        nums = no_rep_random(input)
    else:
        print("argument 1: no_rep | rep")
        print("argument 2: a number")
    for num in nums:
        print(num)

if __name__ == "__main__":
    main()
