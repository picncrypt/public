FROM debian:bullseye

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y \
	build-essential \
	git \
	cmake \
	gcc-arm-none-eabi \
	libnewlib-arm-none-eabi \
	libstdc++-arm-none-eabi-newlib \
	python3 \
	python3-pip

ARG VERSION_PICO_SDK 2.0.0

RUN echo '%sudo ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers
RUN useradd -c "Builder" -m -d /home/build -G sudo -s /bin/bash build

USER build
ENV HOME=/home/build
WORKDIR /home/build/

ARG VERSION_PICO_SDK 2.0.0
ENV PICO_SDK_PATH=$HOME/pico-tools/pico-sdk

RUN mkdir -p $HOME/pico-tools
RUN cd $HOME/pico-tools \
	&& git clone https://github.com/raspberrypi/pico-sdk.git \
        && cd pico-sdk \
        && git checkout $VERSION_PICO_SDK \
        && git submodule update --init --recursive

ENV FREERTOS_KERNEL_PATH=$HOME/pico-tools/FreeRTOS-Kernel

RUN cd $HOME/pico-tools \
	&& git clone -b smp https://github.com/FreeRTOS/FreeRTOS-Kernel --recurse-submodules


RUN pip install cryptography

