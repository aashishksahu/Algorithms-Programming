def Palindrome(min, max):
    palin = []

    # loop through the max 3 digit number to min 3 digit number
    for i in range(max, min-1, -1):
        # if reversing the number == the number 
        if (str(i) == ''.join(reversed(str(i)))):
            # it is a palindrome, append to the list
            palin.append(i)

    return palin


def findMaxFactor(pal_list):
    factor1 = 0
    factor2 = 0

    # iterate through the list of palindromes
    for num in pal_list:
        for i in range(999, 99, -1):
            # check if each palindrome is dividible by the largest 3 digit number 
            if num%i==0:
                # check if after dividing the quotient is 3-digit or not
                if (len(str(int(num/i))) == 3):
                    # if quotient is 3 digit than return quotient and divison 
                    factor1 = int(i)
                    factor2 = int(num/i)
                    return factor1, factor2
        


# maximum number that has 2 3-digit factors
max_num = 999*999

# minimum number that has 2 3-digit factors
min_num = 10*10

# find palindromes in this range
pal = Palindrome(min_num, max_num)
        
###### Find the largest palindrome made from the product of two 3-digit numbers ######
factors = findMaxFactor(pal)
