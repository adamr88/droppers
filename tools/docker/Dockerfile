FROM ubuntu@sha256:2b7412e6465c3c7fc5bb21d3e6f1917c167358449fecac8176c6e496e5c1f05f as base
# essential tools
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -yqq \
	ca-certificates file gnupg wget

# reverse engineering sources
RUN wget -q -O - https://archive.kali.org/archive-key.asc  | apt-key add -
RUN echo "deb http://http.kali.org/kali kali-rolling main contrib non-free" >> /etc/apt/sources.list
RUN apt-get update

FROM base as builder-tools
# builder tools
RUN DEBIAN_FRONTEND=noninteractive apt-get install -yqq \
	build-essential clang cmake mingw-w64

# developer tools
RUN DEBIAN_FRONTEND=noninteractive apt-get install -yqq \
	cppcheck \
	clang-format \
	git \
	python3 \
	python3-pip \
	tmux \
	valgrind \
	vim

FROM builder-tools as reverse-tools
RUN DEBIAN_FRONTEND=noninteractive apt-get install -yqq \
	ltrace radare2 rizin strace

FROM reverse-tools as disasseble-tools
RUN apt-get install -yqq \
	c++filt \
	nasm \
	gcc-multilib \
	bsdmainutils

FROM disasseble-tools as emulator
# windows emulator (experimental)
ENV WINEDEBUG -all
RUN dpkg --add-architecture i386 \
	&& DEBIAN_FRONTEND=noninteractive apt-get update && apt-get install -yqq \
	wine wine32:i386 wine64
RUN apt-get update -yqq && apt-get install -y metasploit-framework
RUN apt-get -y autoremove && apt-get -y autoclean && rm -rf /var/lib/apt/lists/*

WORKDIR /root/dropper
ENTRYPOINT [ "/bin/bash" ]
