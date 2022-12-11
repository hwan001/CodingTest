# �߶� �迭�� �����ϱ�
# https://school.programmers.co.kr/learn/courses/30/lessons/120913
def solution_120913(my_str, n):
    answer = []
    
    while(len(my_str) > n):
        answer.append(my_str[:n])
        my_str = my_str[n:]
        
    answer.append(my_str)
    
    return answer

# ���ڿ��ȿ� ���ڿ�
# https://school.programmers.co.kr/learn/courses/30/lessons/120908
def solution_120908(str1, str2):
    return 2 if len(str1.split(str2)) == 1 else 1


# ���ܿ��� ����
# https://school.programmers.co.kr/learn/courses/30/lessons/136798
def solution_136798(number, limit, power):
    import math
    list_knight_power = []

    for n in range(1, number+1):
        list_tmp = []
        for x in range(1, int(math.sqrt(n))+1):
            if n % x == 0:
                list_tmp.append(x)
                list_tmp.append(n // x)
        list_knight_power.append(len(set(list_tmp)))

    return sum([power if x > limit else x for x in list_knight_power])


# �ܰ��༺�� ����
# https://school.programmers.co.kr/learn/courses/30/lessons/120834
def solution_120834(age):
    dict_age={0:"a", 1:"b", 2:"c", 3:"d", 4:"e", 5:"f", 6:"g", 7:"h", 8:"i", 9:"j"}
    return "".join([dict_age[int(ch)] for ch in str(age)])


# ���� ����� ���� ����
# https://school.programmers.co.kr/learn/courses/30/lessons/142086
def solution_142086(s):
    answer = []
    dict_str={}
    
    for i in range(len(s)):
        ch = s[i]
        try:
            answer.append(i - dict_str[ch])
        except:
            answer.append(-1)
        dict_str[ch] = i
        
    return answer


# �� ����
# https://school.programmers.co.kr/learn/courses/30/lessons/138476
def solution_138476(k, tangerine):
    from collections import Counter
    answer = 0
    
    for x in dict(sorted(Counter(tangerine).items(), key=(lambda x : x[1]), reverse=True)).values():
        k -= x
        answer+=1
        if k <= 0: break
    
    return answer