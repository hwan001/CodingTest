# ======== 1️⃣ Build Stage ========
FROM gcc:latest AS build

WORKDIR /app
COPY cpp /app

# C++ 소스 코드 컴파일
RUN g++ -static -o /app/main /app/*.cpp

# ======== 2️⃣ Runtime Stage ========
FROM debian:latest

# 실행에 필요한 최소 패키지만 설치 # --no-install-recommends
RUN apt-get update && apt-get install -y openssh-server sudo libstdc++6 

RUN rm -rf /var/lib/apt/lists/*
RUN mkdir /var/run/sshd

# 🔹 root 계정 비밀번호 설정
RUN echo 'root:1234' | chpasswd

# 🔹 SSH 설정 변경: 비밀번호 로그인 허용
RUN sed -i 's/#PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config
RUN sed -i 's/#PasswordAuthentication no/PasswordAuthentication yes/' /etc/ssh/sshd_config

# 빌드된 실행 파일만 복사 (g++ 같은 불필요한 빌드 도구는 포함 안 함)
COPY --from=build /app/main /app/main

# SSH 포트 노출
EXPOSE 22

# 실행 명령
CMD ["/usr/sbin/sshd", "-D"]