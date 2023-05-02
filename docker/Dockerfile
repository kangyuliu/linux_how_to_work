FROM ubuntu:20.04
RUN apt-get update
RUN apt-get -y install build-essential
RUN apt-get -y install manpages-dev
RUN apt-get -y install vim
RUN apt-get -y install git
RUN apt-get -y install wget
RUN wget https://cmake.org/files/v3.12/cmake-3.12.2-Linux-x86_64.tar.gz \
    && tar -zxvf cmake-3.12.2-Linux-x86_64.tar.gz \
    && mv cmake-3.12.2-Linux-x86_64 cmake-3.12.2 \
    && ln -sf /cmake-3.12.2/bin/* /usr/bin
RUN apt-get -y install python3-pip
RUN apt-get -y install build-essential libssl-dev libffi-dev python-dev
RUN apt-get -y install sysstat
RUN apt-get -y install strace
RUN apt-get -y install sudo 