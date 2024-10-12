## Usage

1. ### Create a build system (Optional)
    - Install Docker
        - Ubuntu :
            - Install apt package :
                ```bash
                wget -O - https://raw.githubusercontent.com/hwan001/install/refs/heads/main/install_apt.sh | bash
                ```
            - Ubuntu 22.04 LTS (Jammy) :
                ```bash
                wget -O - https://raw.githubusercontent.com/hwan001/install/refs/heads/main/docker/install_jammy.sh | bash
                ```
            - Ubuntu 24.04 LTS (Noble) :
                ```bash
                wget -O - https://raw.githubusercontent.com/hwan001/install/refs/heads/main/docker/install_noble.sh | bash
                ```
    - Add VSCode extesion
        - Remote explorer : 
            - Connect to container :
                ```bash
                ./build_container/build.sh
                ./build_container/run.sh 
                ```
                
2. ### Create binary file and run
```bash
./build.sh
# https://www.acmicpc.net/problem/1966 여기서 1966만 입력, 기본 함수(./main 시 실행) 지정은 init()에서 가능
./main <baekjoon_number> 
```