FROM ubuntu@sha256:2b7412e6465c3c7fc5bb21d3e6f1917c167358449fecac8176c6e496e5c1f05f as base

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install -yqq \
	# essential tools
	ca-certificates file gnupg wget \
	# build tools
	build-essential clang cmake gcc-multilib mingw-w64 \
	# forward engineering tools
	cppcheck clang-format git python3 python3-pip python3-venv tmux valgrind vim \
	# reverse engineering tools (in ppa)
	bsdmainutils c++filt exiftool ltrace nasm strace

# exploit engineering sources (out of ppa)
# RUN wget -q -O - https://archive.kali.org/archive-key.asc  | apt-key add - \
# 	&& echo "deb http://http.kali.org/kali kali-rolling main contrib non-free" >> /etc/apt/sources.list \
# 	&& apt-get update

# windows emulator (experimental)

ENV WINEDEBUG -all
RUN dpkg --add-architecture i386 \
	&& DEBIAN_FRONTEND=noninteractive apt-get update && apt-get install -yqq \
	wine wine32:i386 wine64

# Packaging

RUN apt-get -yqq install nsis p7zip-full

# Clean up

RUN apt-get -y autoremove && apt-get -y autoclean && rm -rf /var/lib/apt/lists/*

WORKDIR /root/dropper
ENTRYPOINT [ "/bin/bash" ]
