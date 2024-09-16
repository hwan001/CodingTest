FROM ubuntu:22.04

RUN apt-get update && apt-get upgrade -y
RUN apt-get install -y build-essential g++ openssh-server sudo git curl ca-certificates --no-install-recommends
RUN rm -rf /var/lib/apt/lists/*
RUN mkdir /var/run/sshd

RUN git clone https://github.com/hwan001/CodingTest.git /root/CodingTest

EXPOSE 22

CMD ["/usr/sbin/sshd", "-D"]
