datas = {
    "person_1":{
        "name": {"first":"David", "middle":"", "last":"Smith"},
        "age":12,
        "address":"-",
        "education":{"highschool":"N/A","college":"-"},
        "hobbies":["running", "swimming", "-"],
    },
    "person_2":{
        "name": {"first":"Mason", "middle":"henry", "last":"Thomas"},
        "age":21,
        "address":"-",
        "education":{"highschool":"N/A", "college":"", "Universitry":"Stanford"},
        "hobbies":["coding", "-", ""],
    }
}

def my_decorator(func):
    def wrapped_func(*args):
        import time
        start_r = time.perf_counter()
        start_p = time.process_time()

        ret = func(*args)

        end_r = time.perf_counter()
        end_p = time.process_time()
        
        elapsed_r = end_r - start_r
        elapsed_p = end_p - start_p
        print(f'{func.__name__} : {elapsed_r:.6f}sec (Perf_Counter) / {elapsed_p:.6f}sec (Process Time)')
        
        return ret
    return wrapped_func

@my_decorator
def create_random_data(num:int) -> dict:
    import random

    data={}
    random_string = lambda x: "".join([chr(random.randint(97, 122)) for tmp in range(x)])

    for i in range(num):
        key = f"person_{i+1}"
        data[key] = {
            "name":{"first":random_string(random.randint(0, 8)), "middle":random_string(random.randint(0, 8)), "last":random_string(random.randint(0, 8))}, 
            "age":random.randint(10, 50),
            "address":"-",
            "education":{"highschool":random_string(random.randint(0, 8)), "college":"", "Universitry":random_string(random.randint(0, 8))},
            "hobbies":["coding", "-", "", random_string(random.randint(0, 8))],
        }

    return data

def clean(data):
    remove_keyword = ["N/A", "", "-"]

    for key in list(data):
        value = data[key]

        if type(value) == dict: 
            clean(value)
            if value == {}:
                data.pop(key)

        if type(value) == list:
            for x in [keyword for keyword in remove_keyword if keyword in value]:
                for _ in range(value.count(x)):
                    value.remove(x)

        if type(value) == str:
          if value in remove_keyword:
            data.pop(key)


datas = create_random_data(1000000)
print(len(datas), datas, "\n")

import time
start_r = time.perf_counter()
start_p = time.process_time()

clean(datas.copy())

end_r = time.perf_counter()
end_p = time.process_time()
        
elapsed_r = end_r - start_r
elapsed_p = end_p - start_p
print(f'{"clean"} : {elapsed_r:.6f}sec (Perf_Counter) / {elapsed_p:.6f}sec (Process Time)')
print(len(datas), datas)

