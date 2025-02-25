# �ܾ� ��ȯ
# https://school.programmers.co.kr/learn/courses/30/lessons/43163
def bfs_43163(begin, target, words, visited):
    str_end = target
    str_start = begin
    int_depth = 0
    arr_stack = [str_start]
    
    while arr_stack:
        str_top = arr_stack.pop()
        print(str_top)
        
        if str_top == target:
            return int_depth
        
        for i in range(len(words)):
            if visited[i] or words[i] == str_top:
                continue
                
            #if sum([(lambda x : words[i].count(str_top[x]))(j) for j in range(len(words[i]))]) == (len(words[i]) -1):
            
            for _ in range(len(words[i])):
                count_tmp = 0
                for j in range(len(words[i])):
                    if [ch for ch in words[i]][j] == [ch for ch in str_top][j]:
                        count_tmp+=1 
                
                if (len(words[i])-1) == count_tmp:
                    visited[i] = True
                    
                    if words[i] != str_end:
                        arr_stack.append(words[i])
                    else:
                        return int_depth+1
                    break
                    
        int_depth += 1
            
            
def solution_43163(begin, target, words):
    if target not in words:
        return 0
    
    visited = [False] * (len(words))
    print(words)
    return bfs_43163(begin, target, words, visited)




