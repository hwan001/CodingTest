


# 1480. Running Sum of 1d Array
class Solution_1480:
    def runningSum(self, nums: List[int]) -> List[int]:
        sum = 0
        list_res = []
        for i in nums:
            sum += i
            list_res.append(sum)
            
        return list_res



# 392. Is Subsequence
class Solution_392:
    def isSubsequence(self, s: str, t: str) -> bool:
        res = False
        cnt = 0
        len_s = len(s)
        
        if s == "":
            return True
        
        for tmp in t:
            if cnt >= len_s:
                break
                
            if s[cnt] == tmp:
                cnt += 1 
                
        if cnt == len_s:
            res = True
        
        return res



# 205. Isomorphic Strings
class Solution_205:
    def isIsomorphic(self, a: str, b: str) -> bool:
        dict_a = {}
        dict_b = {}
        len_a = len(a)
        len_b = len(b)
        
        if len_a != len_b:
            return False
        
        for i in range(len_a):
            try:
                dict_a[a[i]].add(b[i])
            except:
                dict_a[a[i]] = {b[i]}
                
            try:
                dict_b[b[i]].add(a[i])
            except:
                dict_b[b[i]] = {a[i]}
                
        #print(dict_a, dict_b)
        
        if len(list(dict_a.keys())) != len(list(dict_b.keys())):
            return False
        
        for x in dict_a.values():
            if len(x) > 1:
                return False
            
        return True



# 13. Roman to Integer
class Solution_13:
    def romanToInt(self, s: str) -> int:
        dictStr={"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
        sum = 0
        
        for i in range(len(s)-1):
            if dictStr[s[i]] < dictStr[s[i+1]]:
                sum -= dictStr[s[i]]
            else:
                sum += dictStr[s[i]]
            
        sum += dictStr[s[-1]]
        
        return sum



