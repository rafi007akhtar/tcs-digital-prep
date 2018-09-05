## Program to determine if a number is even / odd without any mathematical operators
n = input("Enter number: ")
if n[-1] in "02468":
	print(n, "is even")
else: print(n, "is odd")
