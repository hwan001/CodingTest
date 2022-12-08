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
    list_knight_power = []

    for n in range(1, number+1):
        list_tmp = []
        for x in range(1, int(math.sqrt(n))+1):
            if n % x == 0:
                list_tmp.append(x)
                list_tmp.append(n // x)
        list_knight_power.append(len(set(list_tmp)))

    return sum([power if x > limit else x for x in list_knight_power])