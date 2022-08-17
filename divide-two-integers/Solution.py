// https://leetcode.com/problems/divide-two-integers

class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        
        MAX_INT = 2147483647        # 2**31 - 1
        MIN_INT = -2147483648       # -2**31
        HALF_MIN_INT = -1073741824
        
        if divisor == 1:
            return dividend
        
        if dividend == MIN_INT and divisor == -1:
            return MAX_INT
        
        if divisor == -1:
            return -dividend
        
        negatives=0
        if dividend < 0:
            negatives+=1
        else:
            dividend = -dividend
        
        if divisor < 0:
            negatives+=1
        else:
            divisor = -divisor
        
        highest_power=divisor
        highest_exp=1
        
        while True:
            if highest_power < HALF_MIN_INT:
                break
            
            if highest_power + highest_power < dividend:
                break
                
            highest_power += highest_power
            highest_exp += highest_exp
        
        quotient = 0
        
        while divisor >= dividend:
            if highest_power >= dividend:
                dividend -= highest_power
                quotient += highest_exp
            highest_power >>= 1
            highest_exp >>= 1
        
        if negatives == 1:
            return -quotient
        
        return quotient
        